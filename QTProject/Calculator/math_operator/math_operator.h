/*****************************************************
** Copyright(C), 2015-2025, Baodi Technology.
** Version:     alpha
** Author:      Fu_Qingchen
** Date:        2021/3/5
** Description: ʵ�ּ���������������
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
    **Description:    �жϴ�����ַ����Ƿ���Խ�������
    **Input:          m_function:��Ҫ����ı��ʽ
    **Return:         true: ���Խ������� false: ���ܽ�������
    **Others:         ���贫����ַ�������ȷ��
    *************************************************/
    int isFunctionVaild();

private:
    // �жϱ��ʽ�Ƿ����
    // 1->����  0->�﷨���� -1->��0
    int m_vaild = 0;

    // ��ϵ����������ȼ�������ʵ�� calculate ����
    const char pri[7][7] = {
        /*  + */ '<', '<', '<', '<', '>', ' ', '>',
        /*  - */ '<', '<', '<', '<', '>', ' ', '>',
        /*��* */ '>', '>', '<', '<', '>', ' ', '>',
        /*  / */ '>', '>', '<', '<', '>', ' ', '>',
        /*ǰ( */ '>', '>', '>', '>', '>', ' ', '>',
        /*  ) */ '<', '<', '<', '<', '=', ' ', '>',
        /*  \0*/ '<', '<', '<', '<', ' ', ' ', '=',
        //       +    -    *    /    (    )    \0
        //                ջ     ��
    };

    QString m_function;

    /*************************************************
    **Function:       calculation
    **Description:    ��������ַ���ת��Ϊ���ʽ����������
    **Input:          m_function:��Ҫ����ı��ʽ
    **Return:         ����Ľ��
    **Others:         ���贫����ַ�������ȷ��
    **                �����ʵ������׺���ʽ��ֵ
    *************************************************/
    double calculation();

    char compare(char, char);

    EnumOperator char2rank(char);

    double calcu(double, char, double);

};

#endif // MATH_OPERATOR_H
