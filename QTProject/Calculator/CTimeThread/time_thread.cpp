/*****************************************************
** Copyright(C), 2015-2025, Fu_Qingchen.
** Version:     alpha
** Author:      Fu_Qingchen
** Date:        2021/3/9
** Description: 计算器的计时器接口
*****************************************************/

#include "time_thread.h"
#include <QTimer>
#include <QDateTime>

#pragma execution_character_set("utf-8")    //解决中文显示乱码问题

void CTimeThread::run()
{
    threadTimer = new QTimer();
    threadTimer->setInterval(1000);
    connect(threadTimer, &QTimer::timeout, this, &CTimeThread::timeOut);
    threadTimer->start();
}

void CTimeThread::timeOut()
{
    emit timer("当前时间：" + QDateTime::currentDateTime().toString("yyyy年MM月dd日 hh:mm:ss"));
}
