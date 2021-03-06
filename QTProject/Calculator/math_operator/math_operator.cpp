#include "math_operator.h"
#include <stack>
#include <fstream>

using namespace std;

CMath_operator::CMath_operator(QString function)
{
    if(function.at(0) == '-')
    {
        m_function = "0" + function;
    }
    else
    {
        m_function = function;
    }

    m_result = calculation();
}

double CMath_operator::calculation()
{
    ofstream outfile;
    outfile.open("deBug.txt", ofstream::out);
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

                outfile << "operator: " << operatorStack.size() << endl;
                outfile << "number  : " << numberStack.size() << endl;

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
            outfile << numberStack.top() << endl;
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
        outfile << "-----------------" << endl;
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

EnumOperator CMath_operator::char2rank(char opera)
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
    if(!m_vaild)
    {
        calculation();
    }
    return m_vaild;
}
