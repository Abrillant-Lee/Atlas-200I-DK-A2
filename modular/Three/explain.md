## 1、何为“推理”🤔？
相信大家在进行模型修改，调优时会遇到这些问题🙈：

> 1.我今天等老半天模型训练好了，推理结果也很好。欸很高兴，下班。结果第二天重新打开时，又要重新训练一边，真烦人。

> 2.欸我模型训练好了，我要部署到项目/发给谁，结果过去有又要重新训练。每重启一次就要训练一次。有时候在服务器上训练效果还不好，真烦人。

其实上述这些问题，就可以用“推理代码”来解决

<details><summary>🚀深度学习组成</summary>

##### &emsp;&emsp;学过算法的同学都知道，一个模型大体可以分为“训练”+“推理”两部分（参数提取数据处先不算”）。一般来说，推理代码和训练代码是放到一起的

- 一般我们会遇到训练和推理代码都放到一起的，就像这种：

    <details><summary>这种方式的训练代码，往往有着每次重新启动都要重新进行模型训练的坏处，如果使用的不是ipynb文件，甚至每次运行都要进行模型训练，非常麻烦。为此，推理代码应运而生</summary>
    
    ```
    # 定义模型网络
    class Net(nn.Module):
        def __init__(self):
            super().__init__()
            self.conv1 = nn.Conv2d(3, 6, 5)
            self.pool = nn.MaxPool2d(2, 2)
            self.conv2 = nn.Conv2d(6, 16, 5)
            self.fc1 = nn.Linear(16 * 5 * 5, 120)
            self.fc2 = nn.Linear(120, 84)
            self.fc3 = nn.Linear(84, 10)
        def forward(self, x):
            x = self.pool(F.relu(self.conv1(x)))
            x = self.pool(F.relu(self.conv2(x)))
            x = torch.flatten(x, 1) # flatten all dimensions except batch
            x = F.relu(self.fc1(x))
            x = F.relu(self.fc2(x))
            x = self.fc3(x)
            return x
    net = Net()

    # 训练模型
    criterion = nn.CrossEntropyLoss()
    optimizer = torch.optim.SGD(net.parameters(), lr=0.001, momentum=0.9)
    for epoch in range(2): 
        running_loss = 0.0
        for i, data in enumerate(trainloader, 0):
            inputs, labels = data
            optimizer.zero_grad()
            outputs = net(inputs)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()
            running_loss += loss.item()
            if i % 2000 == 1999: 
                print('[%d, %5d] loss: %.3f' %
                    (epoch + 1, i + 1, running_loss / 2000))
                running_loss = 0.0
    print('Finished Training')

    # 模型推理

    # 数据处理
    dataiter = iter(testloader)
    images, labels = dataiter.next()
    imshow(torchvision.utils.make_grid(images))
    print('GroundTruth: ', ' '.join('%5s' % classes[labels[j]] for j in range(4)))

    # 推理
    outputs = net(images)
    predicted = torch.max(outputs, 1)
    print('Predicted: ', ' '.join('%5s' % classes[predicted[j]]
                                for j in range(4)))
    ```
    </details>
</details>

<details><summary>🚀推理代码撰写</summary>

 ##### &emsp;&emsp;学过算法的同学都知道，一个模型大体可以分为“训练”+“推理”两部分（参数提取数据处先不算”）。一般来说，推理代码和训练代码是放到一起的

- 训练代码部分:
    <details><summary>训练代码可单独生成一份py文件，内部只需要包含模型定义和训练模型等部分即可，在最后将模型文件单独导出</summary>
    
    ```
    # 定义模型网络
        class Net(nn.Module):
            def __init__(self):
                super().__init__()
                self.conv1 = nn.Conv2d(3, 6, 5)
                self.pool = nn.MaxPool2d(2, 2)
                self.conv2 = nn.Conv2d(6, 16, 5)
                self.fc1 = nn.Linear(16 * 5 * 5, 120)
                self.fc2 = nn.Linear(120, 84)
                self.fc3 = nn.Linear(84, 10)
            def forward(self, x):
                x = self.pool(F.relu(self.conv1(x)))
                x = self.pool(F.relu(self.conv2(x)))
                x = torch.flatten(x, 1) # flatten all dimensions except batch
                x = F.relu(self.fc1(x))
                x = F.relu(self.fc2(x))
                x = self.fc3(x)
                return x
        net = Net()

        # 训练模型
        criterion = nn.CrossEntropyLoss()
        optimizer = torch.optim.SGD(net.parameters(), lr=0.001, momentum=0.9)
        for epoch in range(2): 
            running_loss = 0.0
            for i, data in enumerate(trainloader, 0):
                inputs, labels = data
                optimizer.zero_grad()
                outputs = net(inputs)
                loss = criterion(outputs, labels)
                loss.backward()
                optimizer.step()
                running_loss += loss.item()
                if i % 2000 == 1999: 
                    print('[%d, %5d] loss: %.3f' %
                        (epoch + 1, i + 1, running_loss / 2000))
                    running_loss = 0.0
        print('Finished Training')

    ```
    然后单独导出保存模型，经过此代码模型导出后，会将net模型导出获得一个字典编码格式的.pth模型文件
    ```
    PATH = './cifar_net.pth'
    torch.save(net.state_dict(), PATH)
    ```
    
    </details>
- 推理代码部分:
    <details><summary>推理代码通过调用导出的文件中储存的参数，一键更新模型，是不用训练也能达到训练后的效果</summary>
    
        # 导入模型
        class Net(nn.Module):
        def __init__(self):
            super().__init__()
            self.conv1 = nn.Conv2d(3, 6, 5)
            self.pool = nn.MaxPool2d(2, 2)
            self.conv2 = nn.Conv2d(6, 16, 5)
            self.fc1 = nn.Linear(16 * 5 * 5, 120)
            self.fc2 = nn.Linear(120, 84)
            self.fc3 = nn.Linear(84, 10)
        def forward(self, x):
            x = self.pool(F.relu(self.conv1(x)))
            x = self.pool(F.relu(self.conv2(x)))
            x = torch.flatten(x, 1) # flatten all dimensions except batch
            x = F.relu(self.fc1(x))
            x = F.relu(self.fc2(x))
            x = self.fc3(x)
            return x

        # 导入权重参数
        PATH = './cifar_net.pth'
        net = Net()
        net.load_state_dict(torch.load(PATH))

        # 数据处理-推理
         dataiter = iter(testloader)
        images, labels = dataiter.next()
        imshow(torchvision.utils.make_grid(images))
        print('GroundTruth: ', ' '.join('%5s' % classes[labels[j]] for j in range(4)))

        outputs = net(images)
        predicted = torch.max(outputs, 1)
        print('Predicted: ', ' '.join('%5s' % classes[predicted[j]]
                                    for j in range(4)))

    </details>
</details>

#### 至此，相信大家已经对这个深度学习中推理代码的位置有了一定的理解，后续在为大家深入讲解各个框架下推理代码和模型文件的不同之处

- 下期预告

    pytorch框架下的模型文件及导出导入方式