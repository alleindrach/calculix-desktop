# 如何运行
## 启动docker
``` 
   python3 ./calculix_desktop.py  -v D:/examples 
```
上面的命令会启动一个docker 容器，作为calculix的运行环境，通过浏览器窗口的vnc viewer访问

## 在vnc viewer 的终端管理器里执行下述操作：


  #切换到超级用户
  ```
    sudo su
  ``` 
  #设置脚本环境
  ```
    export  PATH=/home/ubuntu/project/Scripts:$PATH
  ```
  #设置可执行文件
  ```
    chmod a+x /home/ubuntu/project/Scripts/

    find /home/ubuntu/project/ -name test.py |xargs -i chmod a+x {}
  ```
  
## 执行所有的测试
```
  /home/ubuntu/project/testall.py 
```
## 执行其中一个测试
```
  cd /home/ubuntu/project/Linear/Mesh1
  ./test.py
```
注意命令行窗口里的提示，可能需要输入 c 回车，或者e 回车 继续，有时候打开的gmsh数据设置窗口要关闭后才能继续求解。