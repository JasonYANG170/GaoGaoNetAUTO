<div align="center">
    <h1>GaoGaoNetAUTO 糕糕校园网自动认证</h1>
    <img src="https://img.shields.io/github/license/JasonYANG170/GaoGaoNetAUTO?label=License&style=for-the-badge">
    <img src="https://img.shields.io/github/commit-activity/w/JasonYANG170/GaoGaoNetAUTO?style=for-the-badge">
	<img src="https://img.shields.io/github/languages/count/JasonYANG170/GaoGaoNetAUTO?logo=CPLUSPLUS&style=for-the-badge">
	<br>
    	<a href="https://discord.com/invite/az3ceRmgVe"><img alt="Discord" src="https://img.shields.io/discord/978108215499816980?style=social&logo=discord&label=echosec"></a>
  <br>

这是一项基于C++语言的QT应用程序
  
<br>

</div>

## 功能
- ✅ 开机自动认证
- ✅ PC端扫码认证
- ✅ 手机端IP认证
- ✅ 显示认证数据
- ✅ 支持手动断网
 
## 说明
本程序为个人开发，切勿用于非法用途，开发者不承担一切责任。  
请严格遵守广州云糕科技有限公司规定  
本项目致力于帮助学生快速连接网络，不会用于商业用途，盈利等  
若对本项目有异议请与我联系  
现在你可以使用它了

## 教程：
1. 你需要先在手机下载SSL抓包精灵或使用其他方式抓取Tonken。
2. 打开糕糕APP。
3. 返回抓包软件，打开数据中含有auth.yungao的数据包。
4. 复制请求头中Bearer后的到Content前的Token。
5. 下载下方的GaoGaoNetAUTO.exe文件并安装。
6. 将Token粘贴到GaoGaoNetAUTO软件中。
7. 大功告成，现在你不再需要扫码登录糕糕，设备将在每次开机时自动登录了！  
**注意，Token会因为设备登录而改变，请不要退出糕糕账户。**
## 无法显示二维码的设备联网教程：
 1.在设备设置中找到当前设备的ip地址。  
 2.在设备2中输入设备ip地址，认证即可。
## 路由器联网教程：
#### 方法1（使用手机端网络认证，推荐）：   
 1.在路由器后台找到当前路由器的ip地址。
 2.在设备2中输入路由器ip地址，认证即可。  
#### 方法2（使用电脑端网络认证）：  
 1.点击设备1认证，记下电脑IP。  
 2.修改电脑IP，路由器使用静态IP连接到1中的电脑IP。
### 🚧已知问题o
设备1(电脑端)网络认证是通过扫描QR码实现，测试认为该IP不可修改，但是可以通过其他办法  
1.请先认证设备1并记住设备1的IP地址，  
2.在需要联网的设备中设置静态IP，  
3.修改IP为已经认证的设备1的IP地址
