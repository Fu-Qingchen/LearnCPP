#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTableWidgetItem>
#include <array>
#include <QString>
#include <QStringList>

#pragma execution_character_set("utf-8")    //解决显示乱码问题

enum Statu { Income = 0, Outcome };
enum Type { Health = 0, Trans, Education, Daily, Elect, Utility, CMCC, Food, Gift, UNSET, In};

struct IOflow
{
    IOflow(QString datetime, double value, QString name = "", QString item = "",
           Statu statu = Outcome, Type type = UNSET):
        tradeTime(datetime), value(value), name(name), statu(statu), item(item) {
        if(statu == Income){ this->type = In; color = "#C9E2AE"; }
        else{this->type = type; color = "#FFF1B6";}
    }
    QString tradeTime;
    QString name;
    QString item;
    Statu statu;
    Type type;
    double value = 0;
    QString color;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_wechat_clicked();    // 添加 微信 账单到表格

    void on_pushButton_alipay_clicked();    // 添加支付宝账单到表格

private:
    Ui::MainWindow *ui;
    QLabel *alipay_statu, *wechat_statu;
    QStringList typeString{"保险", "交通", "教育", "日用", "数码", "水电",
                           "通讯", "食品", "礼物", "待定"};
    QStringList statuString{"收入", "支出"};
    QString wechatKeyword{"微信支付账单"}, alipayKeyword{"alipay_record"};
    Type typeInCopy;

    void init_Statu();              // 状态栏初始化
    void init_Table();              // 表格初始化
    void init_FilePath();           // 获取文件路径

    void getDataFromWechat(QString);
    void getDataFromAlipay(QString);

    void insertColumnByIOflow(IOflow &);    // 在表格中插入一行
    void setTableItemStyle(QTableWidgetItem *&item, IOflow &data){
        item->setBackgroundColor(data.color);
        item->setTextAlignment(Qt::AlignCenter);
    }   // 设置表格样式
    QString getFilePath(QString);

    void keyPressEvent(QKeyEvent *);
    void Table2ExcelByHtml(QTableWidget, QString);
};

#endif // MAINWINDOW_H
