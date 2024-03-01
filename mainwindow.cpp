#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWebEngineView>
#include <QWebEnginePage>
#include <QWebEngineSettings>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QMessageBox>
#include <QRegularExpression>
#include <QSettings>
#include <QSystemTrayIcon>
QString Tonkencode="";
QString drive1code="";
QString drive2code="";
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



                                 QString drive2;
                         // 从注册表读取code值
                         QSettings codeSettings2("HKEY_CURRENT_USER\\Software\\YourOrganization\\GaoGaoNetAUTO", QSettings::NativeFormat);
                         if (codeSettings2.contains("drive2")) {
                             drive2 = codeSettings2.value("drive2").toString();
                         }
                         drive2code=drive2;
                         // 设置初始值
                         ui->textEdit_3->setText(drive2);
                           ui->textEdit->append("设备2："+drive2);

    QString Tonken2;
    // 从注册表读取code值
    QSettings codeSettings("HKEY_CURRENT_USER\\Software\\YourOrganization\\GaoGaoNetAUTO", QSettings::NativeFormat);
    if (codeSettings.contains("Tonken")) {
        Tonken2 = codeSettings.value("Tonken").toString();
    }
    Tonkencode=Tonken2;
    // 设置初始值
    ui->textEdit->setText("账户Tonken："+Tonken2);
    webView = new QWebEngineView(this);
    connect(webView, &QWebEngineView::loadFinished, this, &MainWindow::onLoadFinished);

    webView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); // 设置大小策略为扩展
    webView->setMinimumSize(QSize(400, 300)); // 设置最小大小为 (30, 30)
    // 将webView添加到verticalLayout中
    ui->verticalLayout23->addWidget(webView);


    // 将布局设置为窗口的布局

    on_pushButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::minimizeToSystemTray(QSystemTrayIcon* trayIcon)
{
    QAction* minimizeAction = new QAction("最小化", this);
    connect(minimizeAction, &QAction::triggered, this, &QWidget::hide);

    QMenu* trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(minimizeAction);
    trayIcon->setContextMenu(trayIconMenu);
    connect(trayIcon, &QSystemTrayIcon::activated, this, [this](QSystemTrayIcon::ActivationReason reason) {
        if (reason == QSystemTrayIcon::DoubleClick) {
            this->showNormal();
            this->activateWindow();
        }
    });
}
#include <QNetworkInterface>


void MainWindow::on_pushButton_clicked()
{    QString drive1;
    // 从注册表读取code值
    QSettings codeSettings1("HKEY_CURRENT_USER\\Software\\YourOrganization\\GaoGaoNetAUTO", QSettings::NativeFormat);
    if (codeSettings1.contains("drive1")) {
        drive1 = codeSettings1.value("drive1").toString();
    }
    drive1code=drive1;
    // 设置初始3
    ui->textEdit_4->setText(drive1);
    ui->textEdit->append("设备1："+drive1);

    QString url = "http://auth.yungao-tech.com:1050/web/network/code?type=17&wlanuserip=10.194.28.69&wlanacname=Panabit&clientip=10.194.28.69&clientmac=d6:98:43:31:33:f3&paip=10.194.225.254&vlan=0.0&iarmdst=https://api-shoulei-ssl.xunlei.com/activity-v2/game_depend?activity_id=55555";

    webView->load(QUrl(url));
}

void MainWindow::onLoadFinished(bool ok)
{
    if (ok) {
        webView->page()->toHtml([this](const QString &html){
            QString pattern = "var code = \"([^\"]+)\";";
            QRegularExpression regex(pattern);
            QRegularExpressionMatch match = regex.match(html);
            if (match.hasMatch()) {
                QString code = match.captured(1);

                ui->textEdit->append("提取到的二维码code值: " + code);
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    QUrl url("http://auth.yungao-tech.com:1050/api/network/auth?str="+code);
    QNetworkRequest request(url);

    // 添加Authorization Header
    QString accessToken = Tonkencode;
    QByteArray authenticationHeader = "Bearer " + accessToken.toUtf8();
    request.setRawHeader("Authorization", authenticationHeader);

    QNetworkReply* reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            // 处理响应数据
            ui->textEdit->append("响应数据: " + data);
        } else {
            QByteArray error = reply->errorString().toUtf8();
            // 处理错误
            ui->textEdit->append("错误: " + error);
        }

        reply->deleteLater();
    });
            } else {
                ui->textEdit->append("未找到var code值");
            }
        });
    } else {
        ui->textEdit->append("页面加载失败");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    QUrl url("http://auth.yungao-tech.com:1050/api/network/logout?token=&ip="+drive1code);
    QNetworkRequest request(url);

    // 添加Authorization Header
    QString accessToken =Tonkencode;
    QByteArray authenticationHeader = "Bearer " + accessToken.toUtf8();
    request.setRawHeader("Authorization", authenticationHeader);

    QNetworkReply* reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            // 处理响应数据
            ui->textEdit->append("响应数据: " + data);
        } else {
            QByteArray error = reply->errorString().toUtf8();
            // 处理错误
            ui->textEdit->append("错误: " + error);
        }

        reply->deleteLater();
    });
}


#include <QSettings>

    void MainWindow::on_pushButton_3_clicked()
    {
        // 获取code值
        QString Tonken2 = ui->textEdit_2->toPlainText();

        // 保存到注册表
        QSettings settings("HKEY_CURRENT_USER\\Software\\YourOrganization\\GaoGaoNetAUTO", QSettings::NativeFormat);
        settings.setValue("Tonken", Tonken2);
         ui->textEdit->append("已保存");
    }
    #include <QFileInfo>
    void MainWindow::on_pushButton_4_clicked()
    {
         // 获取应用程序路径

        // 设置开机自启动
        QSettings* settings = new QSettings("HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run", QSettings::NativeFormat);
        auto application_name = QApplication::applicationName();
        settings->remove(application_name);


        delete settings;



        // 显示开启提示窗口
        QMessageBox::information(this, "完成", "已开启开机自启动");

    }

void MainWindow::on_pushButton_6_clicked()
{

        QString drive1 = ui->textEdit_4->toPlainText();
        // 保存到注册表
        QSettings settings("HKEY_CURRENT_USER\\Software\\YourOrganization\\GaoGaoNetAUTO", QSettings::NativeFormat);
        settings.setValue("drive1", drive1);
        ui->textEdit->append("已保存设备1的IP地址");
        // 在文本编辑框中输出IP地址
        ui->textEdit->append("当前设备IP地址 Current IP Address: " + drive1);
        on_pushButton_clicked();

}


void MainWindow::on_pushButton_5_clicked()
{
                             QString drive2 = ui->textEdit_3->toPlainText();
                             // 保存到注册表
                             QSettings settings("HKEY_CURRENT_USER\\Software\\YourOrganization\\GaoGaoNetAUTO", QSettings::NativeFormat);
                             settings.setValue("drive2", drive2);
                             ui->textEdit->append("已保存设备2的IP地址");
                             // 在文本编辑框中输出IP地址
                             ui->textEdit->append("当前设备IP地址 Current IP Address: " + drive2);

    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    QUrl url2("http://auth.yungao-tech.com:1050/api/network/auth?ip="+drive2);
    QNetworkRequest request(url2);

    // 添加Authorization Header
    QString accessToken = Tonkencode;
    QByteArray authenticationHeader = "Bearer " + accessToken.toUtf8();
    request.setRawHeader("Authorization", authenticationHeader);

    QNetworkReply* reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            // 处理响应数据
            ui->textEdit->append("响应数据: " + data);
        } else {
            QByteArray error = reply->errorString().toUtf8();
            // 处理错误
            ui->textEdit->append("错误: " + error);
        }

        reply->deleteLater();
    });
}


void MainWindow::on_pushButton_7_clicked()
{
    QNetworkAccessManager* manager = new QNetworkAccessManager(this);

    QUrl url("http://auth.yungao-tech.com:1050/api/network/logout?token=&ip="+drive2code);
    QNetworkRequest request(url);

    // 添加Authorization Header
    QString accessToken =Tonkencode;
    QByteArray authenticationHeader = "Bearer " + accessToken.toUtf8();
    request.setRawHeader("Authorization", authenticationHeader);

    QNetworkReply* reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, this, [this, reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            // 处理响应数据
            ui->textEdit->append("响应数据: " + data);
        } else {
            QByteArray error = reply->errorString().toUtf8();
            // 处理错误
            ui->textEdit->append("错误: " + error);
        }

        reply->deleteLater();
    });
}


void MainWindow::on_pushButton12_clicked()
{
     QList<QHostAddress> addressList = QNetworkInterface::allAddresses();
     QString ipAddress;
     QString ip="";
    // 找到第一个非本地IPv4地址
        for (const QHostAddress &address : addressList) {
      if (address != QHostAddress::LocalHost && address.protocol() == QAbstractSocket::IPv4Protocol) {
          ipAddress = address.toString();
          ip=ipAddress;
         break;
        }
       }
    //
    // 在文本编辑框中输出IP地址
    ui->textEdit->append("当前设备IP地址 Current IP Address: " + ip);
}

