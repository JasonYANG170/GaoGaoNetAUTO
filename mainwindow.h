
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "qnetworkaccessmanager.h"
#include "qsystemtrayicon.h"
#include <QWebEngineView>
#include <QMainWindow>
#include <QtWebEngineWidgets/QWebEngineView>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }

QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
void onLoadFinished(bool ok);
    void on_pushButton_2_clicked();
void minimizeToSystemTray(QSystemTrayIcon* trayIcon);
void on_pushButton_3_clicked();

void on_pushButton_4_clicked();

void on_pushButton_6_clicked();

void on_pushButton_5_clicked();

void on_pushButton_7_clicked();

void on_pushButton12_clicked();

private:
    Ui::MainWindow *ui;
 QNetworkReply* reply;
    QNetworkAccessManager *networkManager;
       QWebEngineView *webView; // 声明webView变量
};

#endif // MAINWINDOW_H
