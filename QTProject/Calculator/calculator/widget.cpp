/*****************************************************
** Copyright(C), 2015-2025, Fu_Qingchen.
** Version:     alpha
** Author:      Fu_Qingchen
** Date:        2021/3/6
** Description: 实现计算器的界面操作
*****************************************************/

#include "widget.h"
#include "ui_widget.h"
#include <QKeyEvent>
#include <QPluginLoader>
#include <QDir>
#include <QDebug>

#pragma execution_character_set("utf-8")    //解决中文显示乱码问题

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    loadMathPlugins();
    loadTimePlugins();
    connect(m_timeInterface, SIGNAL(timer(QString)), this, SLOT(timerOut(QString)));
    qDebug() << "finish connect";
    m_timeInterface->run();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateUi()
{
    int size = function.size();
    ui->labelFunction->setText(function + " =");
    if (numberLOP)
    {
        ui->labelResult->setText("-");
        return;
    }
    if (function.at( size - 1) == ')' || function.at( size - 1).isDigit())
    {
        qDebug() << "function:" << function;
        m_mathInterface->setString(function);
        qDebug() << "finish set string";
        switch (m_mathInterface->isFunctionVaild()) {
        case -1:
            ui->labelResult->setText("除数不能为0");
            break;
        case 0:
            ui->labelResult->setText("-");
            break;
        case 1:
            ui->labelResult->setText(QString::number(m_mathInterface->getResult(), 'g', 16));
            break;
        default:
            break;
        }
    }
}

// https://doc.qt.io/qt-5/qtwidgets-tools-echoplugin-example.html
void Widget::loadMathPlugins()
{
    QPluginLoader pluginLoader("D:/Users/lenovo/Documents/GitHub/LearnCS/QTProject/Calculator/calculator/math_operator.dll");
    QObject *plugin = pluginLoader.instance();
    if (plugin) {
        m_mathInterface = qobject_cast<CMathOperatorInterface *>(plugin);
        if (m_mathInterface){
            qDebug() << "load math plugin success";
            return ;
        }
        pluginLoader.unload();
    }
}

void Widget::loadTimePlugins()
{
    QPluginLoader pluginLoader("D:/Users/lenovo/Documents/GitHub/LearnCS/QTProject/Calculator/calculator/CTimeThread.dll");
    QObject *plugin = pluginLoader.instance();
    if (plugin) {
        m_timeInterface = qobject_cast<CTimeThreadInterface *>(plugin);
        if (m_timeInterface){
            qDebug() << "load time plugin success";
            return ;
        }
        pluginLoader.unload();
    }
}

void Widget::on_pushButtonDot_clicked()
{
    if (function.at( function.size() - 1).isDigit())
    {
        function += '.';
        updateUi();
    }
    else
    {
        ui->labelResult->setText(". 使用错误");
    }
}

void Widget::on_pushButton0_clicked()
{
    function += '0';
    updateUi();
}

void Widget::on_pushButton1_clicked()
{
    if (function.size() == 1 && function.at(0).toLatin1() == '0'){
        function = '1';
    }
    else
    {
        function += '1';
    }
    updateUi();
}

void Widget::on_pushButton2_clicked()
{
    if (function.size() == 1 && function.at(0).toLatin1() == '0'){
        function = '2';
    }
    else
    {
        function += '2';
    }
    updateUi();
}

void Widget::on_pushButton3_clicked()
{
    if (function.size() == 1 && function.at(0).toLatin1() == '0'){
        function = '3';
    }
    else
    {
        function += '3';
    }
    updateUi();
}

void Widget::on_pushButton4_clicked()
{
    if (function.size() == 1 && function.at(0).toLatin1() == '0'){
        function = '4';
    }
    else
    {
        function += '4';
    }
    updateUi();
}

void Widget::on_pushButton5_clicked()
{
    if (function.size() == 1 && function.at(0).toLatin1() == '0'){
        function = '5';
    }
    else
    {
        function += '5';
    }
    updateUi();
}

void Widget::on_pushButton6_clicked()
{
    if (function.size() == 1 && function.at(0).toLatin1() == '0'){
        function = '6';
    }
    else
    {
        function += '6';
    }
    updateUi();
}

void Widget::on_pushButton7_clicked()
{
    if (function.size() == 1 && function.at(0).toLatin1() == '0'){
        function = '7';
    }
    else
    {
        function += '7';
    }
    updateUi();
}

void Widget::on_pushButton8_clicked()
{
    if (function.size() == 1 && function.at(0).toLatin1() == '0'){
        function = '8';
    }
    else
    {
        function += '8';
    }
    updateUi();
}

void Widget::on_pushButton9_clicked()
{
    if (function.size() == 1 && function.at(0).toLatin1() == '0'){
        function = '9';
    }
    else
    {
        function += '9';
    }
    updateUi();
}

void Widget::on_pushButtonEnter_clicked()
{
    m_mathInterface->setString(function);
    if (m_mathInterface->isFunctionVaild() == 1)
    {
        function = QString::number(m_mathInterface->getResult());
    }
    updateUi();
}

void Widget::on_pushButtonDiv_clicked()
{
    int size = function.size();
    switch (function.at(size - 1).toLatin1())
    {
    case '+':
    case '-':
    case '*':
    case '(':
        function = function.left(size - 1) + "/";
        break;
    default:
        function += '/';
         ;
        break;
    }
    updateUi();
}

void Widget::on_pushButtonMul_clicked()
{
    int size = function.size();
    if (size == 0){
        function = "0+";
        updateUi();
        return;
    }
    switch (function.at(size - 1).toLatin1())
    {
    case '+':
    case '-':
    case '/':
    case '(':
        function = function.left(size - 1) + "*";
        break;
    default:
        function += '*';
         ;
        break;
    }
    updateUi();
}

void Widget::on_pushButtonSub_clicked()
{
    int size = function.size();
    if (size == 0){
        function = "0-";
        updateUi();
        return;
    }
    switch (function.at(size - 1).toLatin1())
    {
    case '+':
    case '*':
    case '/':
    case '(':
        function = function.left(size - 1) + "-";
        break;
    default:
        function += '-';
        break;
    }
    updateUi();
}

void Widget::on_pushButtonAdd_clicked()
{
    int size = function.size();
    if (size == 0){
        function = "0";
        updateUi();
        return;
    }
    switch (function.at(size - 1).toLatin1()) {
    case '-':
    case '*':
    case '/':
    case '(':
        function = function.left(size - 1) + "+";
        break;
    default:
        function += '+';
         ;
        break;
    }
    updateUi();
}

void Widget::on_pushButtonLOP_clicked()
{
    int size = function.size();
    if (size == 0){
        function = "0";
        updateUi();
        return;
    }
    if (size == 0)
    {
        function = '(';
    }
    else if (function.at(size - 1).isDigit() || function.at(size - 1).toLatin1() == ')')
    {
        ui->labelResult->setText("请在 ( 前输入 *");
        return;
    }
    else
    {
        function += '(';
    }
    ++numberLOP;
    updateUi();
}

void Widget::on_pushButtonROP_clicked()
{
    if (numberLOP)
    {
        --numberLOP;
        if (function.at( function.size() - 1) == '(')
        {
            if ( function.size() == 1)
            {
                function = "0";
                updateUi();
                return;
            }
            function = function.left( function.size() - 1);
        }
        else
        {
            function += ')';
        }
        updateUi();
    }
}

void Widget::on_pushButtonClear_clicked()
{
    function = "0";
    updateUi();
}

void Widget::on_pushButtonBack_clicked()
{
    int size = function.size();
    if (size == 0)
    {
        return;
    }
    else if (size == 1)
    {
        function = "0";
        updateUi();
    }
    else
    {
        if (function.at(size - 1).toLatin1() == '(')
        {
            --numberLOP;
        }
        if (function.at(size - 1).toLatin1() == ')')
        {
            ++numberLOP;
        }
        function = function.left(size - 1);
        updateUi();
    }
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_0:
        emit ui->pushButton0->click();
        break;
    case Qt::Key_1:
        emit ui->pushButton1->click();
        break;
    case Qt::Key_2:
        emit ui->pushButton2->click();
        break;
    case Qt::Key_3:
        emit ui->pushButton3->click();
        break;
    case Qt::Key_4:
        emit ui->pushButton4->click();
        break;
    case Qt::Key_5:
        emit ui->pushButton5->click();
        break;
    case Qt::Key_6:
        emit ui->pushButton6->click();
        break;
    case Qt::Key_7:
        emit ui->pushButton7->click();
        break;
    case Qt::Key_8:
        emit ui->pushButton8->click();
        break;
    case Qt::Key_9:
        emit ui->pushButton9->click();
        break;
    case Qt::Key_Backspace:
        emit ui->pushButtonBack->click();
        break;
    case Qt::Key_Delete:
    case Qt::Key_Escape:
        emit ui->pushButtonClear->click();
        break;
    case Qt::Key_Plus:
        emit ui->pushButtonAdd->click();
        break;
    case Qt::Key_Minus:
        emit ui->pushButtonSub->click();
        break;
    case Qt::Key_Asterisk:
        emit ui->pushButtonMul->click();
        break;
    case Qt::Key_Slash:
        emit ui->pushButtonDiv->click();
        break;
    case Qt::Key_Period:
        emit ui->pushButtonDot->click();
        break;
    case Qt::Key_ParenLeft:
        emit ui->pushButtonLOP->click();
        break;
    case Qt::Key_ParenRight:
        emit ui->pushButtonROP->click();
        break;
    case Qt::Key_Enter:
        emit ui->pushButtonEnter->click();
        break;
    default:
        break;
    }
}

void Widget::timerOut(QString dateTime)
{
    qDebug() << "run";
    ui->label->setText(dateTime);
}
