/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayoutMain;
    QLabel *label;
    QVBoxLayout *verticalLayoutKey;
    QLabel *labelFunction;
    QLabel *labelResult;
    QGridLayout *gridLayout;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonLOP;
    QPushButton *pushButtonDiv;
    QPushButton *pushButtonROP;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonBack;
    QPushButton *pushButtonMul;
    QPushButton *pushButtonSub;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton1;
    QPushButton *pushButton3;
    QPushButton *pushButton6;
    QPushButton *pushButton4;
    QPushButton *pushButton5;
    QPushButton *pushButton2;
    QPushButton *pushButton7;
    QPushButton *pushButton8;
    QPushButton *pushButton9;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton0;
    QPushButton *pushButtonDot;
    QPushButton *pushButtonEnter;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->setWindowModality(Qt::ApplicationModal);
        Widget->resize(400, 625);
        Widget->setMinimumSize(QSize(400, 625));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(18);
        Widget->setFont(font);
        Widget->setWindowTitle(QString::fromUtf8("\350\256\241\347\256\227\345\231\250"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/calculator.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(5);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        verticalLayoutMain = new QVBoxLayout();
        verticalLayoutMain->setSpacing(0);
        verticalLayoutMain->setObjectName(QStringLiteral("verticalLayoutMain"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);

        verticalLayoutMain->addWidget(label);

        verticalLayoutKey = new QVBoxLayout();
        verticalLayoutKey->setSpacing(6);
        verticalLayoutKey->setObjectName(QStringLiteral("verticalLayoutKey"));
        verticalLayoutKey->setContentsMargins(-1, 60, 10, 40);
        labelFunction = new QLabel(Widget);
        labelFunction->setObjectName(QStringLiteral("labelFunction"));
        QFont font2;
        font2.setPointSize(16);
        labelFunction->setFont(font2);
        labelFunction->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayoutKey->addWidget(labelFunction);

        labelResult = new QLabel(Widget);
        labelResult->setObjectName(QStringLiteral("labelResult"));
        QFont font3;
        font3.setPointSize(26);
        labelResult->setFont(font3);
        labelResult->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayoutKey->addWidget(labelResult);

        verticalLayoutKey->setStretch(0, 2);
        verticalLayoutKey->setStretch(1, 5);

        verticalLayoutMain->addLayout(verticalLayoutKey);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButtonAdd = new QPushButton(Widget);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonAdd->sizePolicy().hasHeightForWidth());
        pushButtonAdd->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonAdd, 1, 3, 1, 1);

        pushButtonLOP = new QPushButton(Widget);
        pushButtonLOP->setObjectName(QStringLiteral("pushButtonLOP"));
        sizePolicy.setHeightForWidth(pushButtonLOP->sizePolicy().hasHeightForWidth());
        pushButtonLOP->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonLOP, 0, 0, 1, 1);

        pushButtonDiv = new QPushButton(Widget);
        pushButtonDiv->setObjectName(QStringLiteral("pushButtonDiv"));
        sizePolicy.setHeightForWidth(pushButtonDiv->sizePolicy().hasHeightForWidth());
        pushButtonDiv->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonDiv, 1, 0, 1, 1);

        pushButtonROP = new QPushButton(Widget);
        pushButtonROP->setObjectName(QStringLiteral("pushButtonROP"));
        sizePolicy.setHeightForWidth(pushButtonROP->sizePolicy().hasHeightForWidth());
        pushButtonROP->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonROP, 0, 1, 1, 1);

        pushButtonClear = new QPushButton(Widget);
        pushButtonClear->setObjectName(QStringLiteral("pushButtonClear"));
        sizePolicy.setHeightForWidth(pushButtonClear->sizePolicy().hasHeightForWidth());
        pushButtonClear->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonClear, 0, 2, 1, 1);

        pushButtonBack = new QPushButton(Widget);
        pushButtonBack->setObjectName(QStringLiteral("pushButtonBack"));
        sizePolicy.setHeightForWidth(pushButtonBack->sizePolicy().hasHeightForWidth());
        pushButtonBack->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonBack, 0, 3, 1, 1);

        pushButtonMul = new QPushButton(Widget);
        pushButtonMul->setObjectName(QStringLiteral("pushButtonMul"));
        sizePolicy.setHeightForWidth(pushButtonMul->sizePolicy().hasHeightForWidth());
        pushButtonMul->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonMul, 1, 1, 1, 1);

        pushButtonSub = new QPushButton(Widget);
        pushButtonSub->setObjectName(QStringLiteral("pushButtonSub"));
        sizePolicy.setHeightForWidth(pushButtonSub->sizePolicy().hasHeightForWidth());
        pushButtonSub->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pushButtonSub, 1, 2, 1, 1);


        verticalLayoutMain->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(-1, 7, -1, -1);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton1 = new QPushButton(Widget);
        pushButton1->setObjectName(QStringLiteral("pushButton1"));
        sizePolicy.setHeightForWidth(pushButton1->sizePolicy().hasHeightForWidth());
        pushButton1->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(pushButton1, 2, 0, 1, 1);

        pushButton3 = new QPushButton(Widget);
        pushButton3->setObjectName(QStringLiteral("pushButton3"));
        sizePolicy.setHeightForWidth(pushButton3->sizePolicy().hasHeightForWidth());
        pushButton3->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(pushButton3, 2, 2, 1, 1);

        pushButton6 = new QPushButton(Widget);
        pushButton6->setObjectName(QStringLiteral("pushButton6"));
        sizePolicy.setHeightForWidth(pushButton6->sizePolicy().hasHeightForWidth());
        pushButton6->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(pushButton6, 1, 2, 1, 1);

        pushButton4 = new QPushButton(Widget);
        pushButton4->setObjectName(QStringLiteral("pushButton4"));
        sizePolicy.setHeightForWidth(pushButton4->sizePolicy().hasHeightForWidth());
        pushButton4->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(pushButton4, 1, 0, 1, 1);

        pushButton5 = new QPushButton(Widget);
        pushButton5->setObjectName(QStringLiteral("pushButton5"));
        sizePolicy.setHeightForWidth(pushButton5->sizePolicy().hasHeightForWidth());
        pushButton5->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(pushButton5, 1, 1, 1, 1);

        pushButton2 = new QPushButton(Widget);
        pushButton2->setObjectName(QStringLiteral("pushButton2"));
        sizePolicy.setHeightForWidth(pushButton2->sizePolicy().hasHeightForWidth());
        pushButton2->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(pushButton2, 2, 1, 1, 1);

        pushButton7 = new QPushButton(Widget);
        pushButton7->setObjectName(QStringLiteral("pushButton7"));
        sizePolicy.setHeightForWidth(pushButton7->sizePolicy().hasHeightForWidth());
        pushButton7->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(pushButton7, 0, 0, 1, 1);

        pushButton8 = new QPushButton(Widget);
        pushButton8->setObjectName(QStringLiteral("pushButton8"));
        sizePolicy.setHeightForWidth(pushButton8->sizePolicy().hasHeightForWidth());
        pushButton8->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(pushButton8, 0, 1, 1, 1);

        pushButton9 = new QPushButton(Widget);
        pushButton9->setObjectName(QStringLiteral("pushButton9"));
        sizePolicy.setHeightForWidth(pushButton9->sizePolicy().hasHeightForWidth());
        pushButton9->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(pushButton9, 0, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(7);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 7, -1, -1);
        pushButton0 = new QPushButton(Widget);
        pushButton0->setObjectName(QStringLiteral("pushButton0"));
        sizePolicy.setHeightForWidth(pushButton0->sizePolicy().hasHeightForWidth());
        pushButton0->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButton0);

        pushButtonDot = new QPushButton(Widget);
        pushButtonDot->setObjectName(QStringLiteral("pushButtonDot"));
        sizePolicy.setHeightForWidth(pushButtonDot->sizePolicy().hasHeightForWidth());
        pushButtonDot->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(pushButtonDot);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(0, 3);
        verticalLayout_2->setStretch(1, 1);

        horizontalLayout->addLayout(verticalLayout_2);

        pushButtonEnter = new QPushButton(Widget);
        pushButtonEnter->setObjectName(QStringLiteral("pushButtonEnter"));
        sizePolicy.setHeightForWidth(pushButtonEnter->sizePolicy().hasHeightForWidth());
        pushButtonEnter->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButtonEnter);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);

        verticalLayoutMain->addLayout(horizontalLayout);

        verticalLayoutMain->setStretch(1, 3);
        verticalLayoutMain->setStretch(2, 2);
        verticalLayoutMain->setStretch(3, 4);

        verticalLayout->addLayout(verticalLayoutMain);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        label->setText(QApplication::translate("Widget", "\345\275\223\345\211\215\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        labelFunction->setText(QApplication::translate("Widget", "\350\241\250\350\276\276\345\274\217", Q_NULLPTR));
        labelResult->setText(QApplication::translate("Widget", "\350\277\220\347\256\227\347\273\223\346\236\234", Q_NULLPTR));
        pushButtonAdd->setText(QApplication::translate("Widget", "+", Q_NULLPTR));
        pushButtonLOP->setText(QApplication::translate("Widget", "(", Q_NULLPTR));
        pushButtonDiv->setText(QApplication::translate("Widget", "\303\267", Q_NULLPTR));
        pushButtonROP->setText(QApplication::translate("Widget", ")", Q_NULLPTR));
        pushButtonClear->setText(QApplication::translate("Widget", "C", Q_NULLPTR));
        pushButtonBack->setText(QApplication::translate("Widget", "\360\237\224\231", Q_NULLPTR));
        pushButtonMul->setText(QApplication::translate("Widget", "\303\227", Q_NULLPTR));
        pushButtonSub->setText(QApplication::translate("Widget", "\357\274\215", Q_NULLPTR));
        pushButton1->setText(QApplication::translate("Widget", "1", Q_NULLPTR));
        pushButton3->setText(QApplication::translate("Widget", "3", Q_NULLPTR));
        pushButton6->setText(QApplication::translate("Widget", "6", Q_NULLPTR));
        pushButton4->setText(QApplication::translate("Widget", "4", Q_NULLPTR));
        pushButton5->setText(QApplication::translate("Widget", "5", Q_NULLPTR));
        pushButton2->setText(QApplication::translate("Widget", "2", Q_NULLPTR));
        pushButton7->setText(QApplication::translate("Widget", "7", Q_NULLPTR));
        pushButton8->setText(QApplication::translate("Widget", "8", Q_NULLPTR));
        pushButton9->setText(QApplication::translate("Widget", "9", Q_NULLPTR));
        pushButton0->setText(QApplication::translate("Widget", "0", Q_NULLPTR));
        pushButtonDot->setText(QApplication::translate("Widget", ".", Q_NULLPTR));
        pushButtonEnter->setText(QApplication::translate("Widget", "=", Q_NULLPTR));
        Q_UNUSED(Widget);
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
