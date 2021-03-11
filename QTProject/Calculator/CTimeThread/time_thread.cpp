/*****************************************************
** Copyright(C), 2015-2025, Fu_Qingchen.
** Version:     alpha
** Author:      Fu_Qingchen
** Date:        2021/3/9
** Description: �������ļ�ʱ���ӿ�
*****************************************************/

#include "time_thread.h"
#include <QTimer>
#include <QDateTime>

#pragma execution_character_set("utf-8")    //���������ʾ��������

void CTimeThread::run()
{
    threadTimer = new QTimer();
    threadTimer->setInterval(1000);
    connect(threadTimer, &QTimer::timeout, this, &CTimeThread::timeOut);
    threadTimer->start();
}

void CTimeThread::timeOut()
{
    emit timer("��ǰʱ�䣺" + QDateTime::currentDateTime().toString("yyyy��MM��dd�� hh:mm:ss"));
}
