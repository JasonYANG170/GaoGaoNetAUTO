[简体中文](README.md) | [English](README_en.md)

<div align="center">
    <h1>GaoGaoNetAUTO Gaogao campus network automatic authentication </h1>
    <img src="https://img.shields.io/github/license/JasonYANG170/GaoGaoNetAUTO?label=License&style=for-the-badge">
    <img src="https://img.shields.io/github/commit-activity/w/JasonYANG170/GaoGaoNetAUTO?style=for-the-badge">
	<img src="https://img.shields.io/github/languages/count/JasonYANG170/GaoGaoNetAUTO?logo=CPLUSPLUS&style=for-the-badge">
	<br>
    	<a href="https://discord.com/invite/az3ceRmgVe"><img alt="Discord" src="https://img.shields.io/discord/978108215499816980?style=social&logo=discord&label=echosec"></a>
  <br>

This is a QT application based on C++ language
  
<br>

</div>

## Features
- ✅ Automatic authentication at startup
- ✅ Scan QR code for authentication on PC
- ✅ Mobile IP authentication
- ✅ Show authentication data
- ✅ Support manual disconnection
 
## Overview
This program is developed for individuals and must not be used for illegal purposes. The developer does not assume any responsibility.
Please strictly abide by the regulations of Guangzhou Yungao Technology Co., Ltd.
This project is dedicated to helping students quickly connect to the Internet and will not be used for commercial purposes, profit, etc.
If you have any objections to this project, please contact me
Now you can use it

## Tutorial:
1. You need to download the SSL packet capture wizard on your mobile phone or use other methods to capture Token.
2. Open the GaoGao app.
3. Return to the packet capture software and open the data packet containing auth.yungao in the data.
4. Copy the Token after Bearer in the request header to before Content.
5. Download the GaoGaoNetAUTO.exe file below and install it.
6. Paste the Token into the GaoGaoNetAUTO software.
7. You’re done, now you no longer need to scan the QR code to log in to Gaogao, the device will automatically log in every time it is turned on!
**The token changes when a device logs in. Do not log out of your GaoGao account.**
## Tutorial on connecting devices that cannot display QR codes:
 1. Find the IP address of the current device in the device settings.
 2. Enter the device IP address in Device 2 and authenticate.
## Router networking tutorial:
#### Method 1 (use mobile network authentication, recommended):
 1. Find the IP address of the current router in the router background.
 2. Enter the router IP address in device 2 and authenticate.
#### Method 2 (using computer network authentication):
 1. Click Device 1 Authentication and write down the computer IP.
 2. Modify the computer IP. The router uses a static IP to connect to the computer IP in 1.
### 🚧Known issues
Device 1 (computer) network authentication is achieved by scanning the QR code. The test believes that the IP cannot be modified, but it can be done through other methods.
1. Please authenticate device 1 first and remember the IP address of device 1,
2. Set a static IP in the device that needs to be connected to the Internet.
3. Change the IP to the IP address of the authenticated device 1
