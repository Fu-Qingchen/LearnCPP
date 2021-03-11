/*****************************************************
** Copyright(C), 2015-2025, Fu_Qingchen.
** Version:     alpha
** Author:      Fu_Qingchen
** Date:        2021/3/6
** Description: 实现计算器的界面操作
*****************************************************/

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "math_operator_interface.h"
#include  "time_thread_interface.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton0_clicked();

    void on_pushButtonDot_clicked();

    void on_pushButton1_clicked();

    void on_pushButton2_clicked();

    void on_pushButton3_clicked();

    void on_pushButton4_clicked();

    void on_pushButton5_clicked();

    void on_pushButton6_clicked();

    void on_pushButton7_clicked();

    void on_pushButton8_clicked();

    void on_pushButton9_clicked();

    void on_pushButtonEnter_clicked();

    void on_pushButtonDiv_clicked();

    void on_pushButtonMul_clicked();

    void on_pushButtonSub_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonLOP_clicked();

    void on_pushButtonROP_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonBack_clicked();

    void timerOut(QString);

private:
    Ui::Widget *ui;

    CMathOperatorInterface *m_mathInterface;

    CTimeThreadInterface *m_timeInterface;

    QString function;

    int numberLOP = 0;

    void updateUi();

    void keyPressEvent(QKeyEvent *event);

    void loadMathPlugins();

    void loadTimePlugins();
};

#endif // WIDGET_H
