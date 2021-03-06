/*****************************************************
** Copyright(C), 2015-2025, Baodi Technology.
** Version:     alpha
** Author:      Fu_Qingchen
** Date:        2021/3/5
** Description: 实现计算器的算术操作
*****************************************************/

#ifndef MATH_OPERATOR_H
#define MATH_OPERATOR_H

#include "math_operator_global.h"
#include <QString>

enum EnumOperator
{
    EnumAdd = 0, EnumSub, EnumMul, EnumDiv, EnumL_P, EnumR_P, EnumEOE
};

class MATH_OPERATORSHARED_EXPORT CMath_operator
{
public:
    CMath_operator(QString);

    double m_result;

    /*************************************************
    **Function:       isFunctionVaild
    **Description:    判断传入的字符串是否可以进行运算
    **Input:          m_function:将要运算的表达式
    **Return:         true: 可以进行运算 false: 不能进行运算
    **Others:         假设传入的字符串是正确的
    *************************************************/
    int isFunctionVaild();

private:
    // 判断表达式是否可行
    // 1->可行  0->语法错误 -1->除0
    int m_vaild = 0;

    // 关系运算符的优先级，用于实现 calculate 函数
    const char pri[7][7] = {
        /*  + */ '<', '<', '<', '<', '>', ' ', '>',
        /*  - */ '<', '<', '<', '<', '>', ' ', '>',
        /*当* */ '>', '>', '<', '<', '>', ' ', '>',
        /*  / */ '>', '>', '<', '<', '>', ' ', '>',
        /*前( */ '>', '>', '>', '>', '>', ' ', '>',
        /*  ) */ '<', '<', '<', '<', '=', ' ', '>',
        /*  \0*/ '<', '<', '<', '<', ' ', ' ', '=',
        //       +    -    *    /    (    )    \0
        //                栈     顶
    };

    QString m_function;

    /*************************************************
    **Function:       calculation
    **Description:    将传入的字符串转换为表达式，进行运算
    **Input:          m_function:将要运算的表达式
    **Return:         运算的结果
    **Others:         假设传入的字符串是正确的
    **                这个其实就是中缀表达式求值
    *************************************************/
    double calculation();

    char compare(char, char);

    EnumOperator char2rank(char);

    double calcu(double, char, double);

};

#endif // MATH_OPERATOR_H
