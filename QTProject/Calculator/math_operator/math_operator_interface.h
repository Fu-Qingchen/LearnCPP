/*****************************************************
** Copyright(C), 2015-2025, Fu_Qingchen.
** Version:     alpha
** Author:      Fu_Qingchen
** Date:        2021/3/8
** Description: 计算器的算术接口
*****************************************************/

#ifndef MATH_OPERATOR_INTERFACE_H
#define MATH_OPERATOR_INTERFACE_H

#include <QtPlugin>

class CMathOperatorInterface
{
public:
    virtual int isFunctionVaild() = 0;

    virtual double getResult() = 0;

    virtual void setString(QString) = 0;
};

Q_DECLARE_INTERFACE(CMathOperatorInterface, "MathDLL/V1.0");

#endif // MATH_OPERATOR_INTERFACE_H
