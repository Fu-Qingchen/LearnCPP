/*****************************************************
** Copyright(C), 2015-2025, Fu_Qingchen.
** Version:     alpha
** Author:      Fu_Qingchen
** Date:        2021/3/5
** Description: ʵ�ּ���������������
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
    operatorStack.push('\0');   // ����ջ��ʱ�ıȽ�
    auto iter = m_function.begin();

    int negative_flag = 1;      // �жϸ���
    while (!operatorStack.empty())
    {
        // ��������
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
        }   // ������������������ȡ���ֲ���ջ

        // ���������
        char op = operatorStack.top();
        double num1, num2;
        switch (compare(iter->toLatin1(), op))
        {
        case '>':   // ��ǰ��������ȼ��ߣ������ӳ�
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
        case '<':   // ��ǰ��������ȼ��ͣ���������
            operatorStack.pop();
            num1 = numberStack.top();
            numberStack.pop();
            num2 = numberStack.top();
            numberStack.pop();
            numberStack.push(calcu(num1, op, num2));
            break;
        case '=':   // �����ź�����������
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

    // �﷨��ȷ || û���ֳ�0
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
