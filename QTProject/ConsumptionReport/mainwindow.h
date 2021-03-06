#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTableWidgetItem>
#include <array>
#include <QString>
#include <QStringList>

#pragma execution_character_set("utf-8")    //�����ʾ��������

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
    void on_pushButton_wechat_clicked();    // ��� ΢�� �˵������

    void on_pushButton_alipay_clicked();    // ���֧�����˵������

private:
    Ui::MainWindow *ui;
    QLabel *alipay_statu, *wechat_statu;
    QStringList typeString{"����", "��ͨ", "����", "����", "����", "ˮ��",
                           "ͨѶ", "ʳƷ", "����", "����"};
    QStringList statuString{"����", "֧��"};
    QString wechatKeyword{"΢��֧���˵�"}, alipayKeyword{"alipay_record"};
    Type typeInCopy;

    void init_Statu();              // ״̬����ʼ��
    void init_Table();              // ����ʼ��
    void init_FilePath();           // ��ȡ�ļ�·��

    void getDataFromWechat(QString);
    void getDataFromAlipay(QString);

    void insertColumnByIOflow(IOflow &);    // �ڱ���в���һ��
    void setTableItemStyle(QTableWidgetItem *&item, IOflow &data){
        item->setBackgroundColor(data.color);
        item->setTextAlignment(Qt::AlignCenter);
    }   // ���ñ����ʽ
    QString getFilePath(QString);

    void keyPressEvent(QKeyEvent *);
    void Table2ExcelByHtml(QTableWidget, QString);
};

#endif // MAINWINDOW_H
