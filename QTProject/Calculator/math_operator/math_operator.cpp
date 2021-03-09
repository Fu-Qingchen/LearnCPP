/*****************************************************
** Copyright(C), 2015-2025, Fu_Qingchen.
** Version:     alpha
** Author:      Fu_Qingchen
** Date:        2021/3/5
** Description: 实现计算器的算术操作
*****************************************************/

#include "math_operator.h"
#include <stack>
#include <fstream>
#include <QDebug>

using namespace std;

CMath_operator::CMath_operator()
{
    outfile.open("debugMathOperator.txt");
    outfile << "create math operator" << endl;
}

//CMath_operator::CMath_operator(QString function)
//{
//    outfile.open("debugMathOperator.txt");
//    outfile << "create math operator" << endl;
//    if(function.at(0) == '-')
//    {
//        m_function = "0" + function;
//    }
//    else
//    {
//        m_function = function;
//    }
//    m_result = calculation();
//}

double CMath_operator::calculation()
{
    stack<double> numberStack;
    stack<char> operatorStack;
    operatorStack.push('\0');   // 用于栈空时的比较
    auto iter = m_function.begin();

    int negative_flag = 1;      // 判断负数
    while (!operatorStack.empty())
    {
        // 处理数字
        if (iter->isNumber() || *iter == '.')
        {
            QString temp = *iter++;
            while (iter->isNumber() || *iter == '.')
            {
                temp += *iter++;
            }
            numberStack.push(negative_flag * temp.toDouble());
            negative_flag = 1;
            continue;
        }   // 如果操作符是数字则读取数字并入栈

        // 处理操作符
        char op = operatorStack.top();
        double num1, num2;
        switch (compare(iter->toLatin1(), op))
        {
        case '>':   // 当前运算符优先级高，计算延迟
            operatorStack.push(iter->toLatin1());
            if(*++iter == '-')
            {
                negative_flag = -1;
                ++iter;
            }
            else
            {
                negative_flag = 1;
            }
            break;
        case '<':   // 当前运算符优先级低，进行运算
            operatorStack.pop();
            num1 = numberStack.top();
            numberStack.pop();
            num2 = numberStack.top();
            numberStack.pop();
            numberStack.push(calcu(num1, op, num2));
            break;
        case '=':   // 右括号和左括号相遇
            operatorStack.pop();
            if(*++iter == '-')
            {
                negative_flag = -1;
                ++iter;
            }
            else
            {
                negative_flag = 1;
            }
            break;
        default:
            break;
        }
    }
    outfile.close();

    // 语法正确 || 没出现除0
    if (numberStack.size() == 1 && !m_vaild)
    {
        m_vaild = 1;
    }
    return numberStack.top();
}

char CMath_operator::compare(char curr, char stackTop)
{
    return pri[char2rank(curr)][char2rank(stackTop)];
}

CMath_operator::EnumOperator CMath_operator::char2rank(char opera)
{
    switch (opera)
    {
    case '+':   return EnumAdd;
    case '-':   return EnumSub;
    case '*':   return EnumMul;
    case '/':   return EnumDiv;
    case '(':   return EnumL_P;
    case ')':   return EnumR_P;
    default :   return EnumEOE;
    }
}

double CMath_operator::calcu(double num1, char op, double num2)
{
    switch (op)
    {
    case '+':   return num2 + num1;
    case '-':   return num2 - num1;
    case '*':   return num2 * num1;
    case '/':
        if(num1 == 0)
        {
            m_vaild = -1;
            return ~0U;
        }
        else
        {
            return num2 / num1;
        }
    default :   return ~0U;
    }
}

int CMath_operator::isFunctionVaild()
{
    return m_vaild;
}

double CMath_operator::getResult()
{
    calculation();
    return m_result;
}

void CMath_operator::setString(QString function)
{
    outfile << "CMathOperator Input: " << function.toStdString() << endl;
    if(function.at(0) == '-')
    {
        m_function = "0" + function;
    }
    else
    {
        m_function = function;
    }
    qDebug() << "CMathOperator: " << m_function;
    outfile << "CMathOperator: " << m_function.toStdString() << endl;
    m_result = calculation();
    outfile << "calculation done" << endl;
    qDebug() << "calculation done";
}
