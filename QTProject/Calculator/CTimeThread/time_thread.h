/*****************************************************
** Copyright(C), 2015-2025, Fu_Qingchen.
** Version:     alpha
** Author:      Fu_Qingchen
** Date:        2021/3/9
** Description: 计算器的计时器接口
*****************************************************/

#ifndef TIME_THREAD_H
#define TIME_THREAD_H

#include "time_thread_global.h"
#include "time_thread_interface.h"
#include <QTimer>

class CTIMETHREADSHARED_EXPORT CTimeThread : public CTimeThreadInterface
{
    Q_OBJECT
    Q_INTERFACES(CTimeThreadInterface)
    Q_PLUGIN_METADATA(IID "Time/V1.0" FILE "")

public:
    void run() override ;

signals:
    void timer(QString);    // 发出去给UI界面的信号

private slots:
    void timeOut();

private:
    QTimer *threadTimer;
};

#endif // TIME_THREAD_H
