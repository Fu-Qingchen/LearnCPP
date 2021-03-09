/*****************************************************
** Copyright(C), 2015-2025, Fu_Qingchen.
** Version:     alpha
** Author:      Fu_Qingchen
** Date:        2021/3/5
** Description: ʵ�ּ���������������
*****************************************************/

#ifndef MATH_OPERATOR_GLOBAL_H
#define MATH_OPERATOR_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MATH_OPERATOR_LIBRARY)
#  define MATH_OPERATORSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MATH_OPERATORSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // MATH_OPERATOR_GLOBAL_H
