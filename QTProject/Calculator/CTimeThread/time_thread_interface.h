/*****************************************************
** Copyright(C), 2015-2025, Fu_Qingchen.
** Version:     alpha
** Author:      Fu_Qingchen
** Date:        2021/3/9
** Description: 计算器的计时器接口
*****************************************************/

#ifndef CTIMETHREADINTERFACE_H
#define CTIMETHREADINTERFACE_H

#include <QObject>
#include <QThread>
#include <QtPlugin>

class CTimeThreadInterface : public QThread
{
    Q_OBJECT
public:
    virtual void run() = 0;

signals:
    void timer(QString);    // 发出去给UI界面的信号
};

Q_DECLARE_INTERFACE(CTimeThreadInterface, "Time/V1.0")

#endif // CTIMETHREADINTERFACE_H
