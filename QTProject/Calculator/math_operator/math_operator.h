/*****************************************************
** Copyright(C), 2015-2025, Fu_Qingchen.
** Version:     alpha
** Author:      Fu_Qingchen
** Date:        2021/3/5
** Description: ʵ�ּ���������������
*****************************************************/

#ifndef MATH_OPERATOR_H
#define MATH_OPERATOR_H

#include "math_operator_global.h"
#include "math_operator_interface.h"
#include <QtPlugin>
#include <QString>
#include <fstream>

class MATH_OPERATORSHARED_EXPORT CMath_operator : public QObject, public CMathOperatorInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "MathDLL/V1.0" FILE "")
    Q_INTERFACES(CMathOperatorInterface)

public:
    CMath_operator();

    ~CMath_operator()
    {
        outfile.close();
    }

//    CMath_operator(QString);

    int isFunctionVaild();

    double getResult();

    void setString(QString);

private:
    // �жϱ��ʽ�Ƿ����
    // 1->����  0->�﷨���� -1->��0
    int m_vaild = 0;

    double m_result;

    QString m_function;

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

    enum EnumOperator
    {
        EnumAdd = 0, EnumSub, EnumMul, EnumDiv, EnumL_P, EnumR_P, EnumEOE
    };

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

    std::ofstream outfile;

};

#endif // MATH_OPERATOR_H
