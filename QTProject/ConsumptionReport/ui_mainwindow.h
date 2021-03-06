/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionDelete;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *alipayPath;
    QPushButton *pushButton_wechat;
    QLabel *label_2;
    QLabel *label;
    QPushButton *pushButton_alipay;
    QLabel *wechatPath;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(847, 577);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setAutoFillBackground(true);
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        alipayPath = new QLabel(groupBox);
        alipayPath->setObjectName(QStringLiteral("alipayPath"));
        alipayPath->setMinimumSize(QSize(400, 0));
        alipayPath->setFrameShape(QFrame::NoFrame);
        alipayPath->setLineWidth(2);

        gridLayout_3->addWidget(alipayPath, 0, 1, 1, 1);

        pushButton_wechat = new QPushButton(groupBox);
        pushButton_wechat->setObjectName(QStringLiteral("pushButton_wechat"));
        pushButton_wechat->setMinimumSize(QSize(200, 0));

        gridLayout_3->addWidget(pushButton_wechat, 1, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(200, 16777215));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(200, 16777215));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        pushButton_alipay = new QPushButton(groupBox);
        pushButton_alipay->setObjectName(QStringLiteral("pushButton_alipay"));

        gridLayout_3->addWidget(pushButton_alipay, 0, 2, 1, 1);

        wechatPath = new QLabel(groupBox);
        wechatPath->setObjectName(QStringLiteral("wechatPath"));
        wechatPath->setMinimumSize(QSize(400, 0));
        wechatPath->setLineWidth(2);

        gridLayout_3->addWidget(wechatPath, 1, 1, 1, 1);


        gridLayout->addWidget(groupBox, 2, 0, 1, 1);

        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout->addWidget(tableWidget, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 847, 25));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\346\266\210\350\264\271\346\212\245\345\221\212", Q_NULLPTR));
        actionCopy->setText(QApplication::translate("MainWindow", "\345\244\215\345\210\266", Q_NULLPTR));
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", Q_NULLPTR));
        actionPaste->setText(QApplication::translate("MainWindow", "\347\262\230\350\264\264", Q_NULLPTR));
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", Q_NULLPTR));
        actionDelete->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244", Q_NULLPTR));
        actionDelete->setShortcut(QApplication::translate("MainWindow", "Del", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\350\276\223\345\205\245", Q_NULLPTR));
        alipayPath->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\344\275\215\347\275\256", Q_NULLPTR));
        pushButton_wechat->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\345\276\256\344\277\241\350\264\246\345\215\225", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\276\256\344\277\241\350\264\246\345\215\225\346\226\207\344\273\266", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\224\257\344\273\230\345\256\235\350\264\246\345\215\225\346\226\207\344\273\266", Q_NULLPTR));
        pushButton_alipay->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\346\224\257\344\273\230\345\256\235\350\264\246\345\215\225", Q_NULLPTR));
        wechatPath->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\344\275\215\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
