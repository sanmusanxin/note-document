/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QProgressBar *progressBar;
    QLabel *rclabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *idShowEdit;
    QLabel *label_3;
    QLabel *IDlabel;
    QTextEdit *textEdit;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *serial1Box;
    QPushButton *openButton;
    QPushButton *resShowButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *testStopButton;
    QPushButton *testStartButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1155, 738);
        MainWindow->setMinimumSize(QSize(1150, 725));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        gridLayout_2->addWidget(progressBar, 3, 0, 1, 2);

        rclabel = new QLabel(centralwidget);
        rclabel->setObjectName(QString::fromUtf8("rclabel"));
        rclabel->setMinimumSize(QSize(570, 140));
        QFont font;
        font.setPointSize(16);
        rclabel->setFont(font);

        gridLayout_2->addWidget(rclabel, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        idShowEdit = new QLineEdit(centralwidget);
        idShowEdit->setObjectName(QString::fromUtf8("idShowEdit"));
        idShowEdit->setMinimumSize(QSize(116, 40));
        idShowEdit->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_3->addWidget(idShowEdit);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(182, 40));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        IDlabel = new QLabel(centralwidget);
        IDlabel->setObjectName(QString::fromUtf8("IDlabel"));
        IDlabel->setMinimumSize(QSize(182, 40));
        IDlabel->setFont(font);

        horizontalLayout_3->addWidget(IDlabel);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 2);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(false);

        gridLayout_2->addWidget(textEdit, 2, 0, 1, 2);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(556, 140));
        groupBox->setMaximumSize(QSize(556, 140));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        serial1Box = new QComboBox(groupBox);
        serial1Box->setObjectName(QString::fromUtf8("serial1Box"));
        serial1Box->setMinimumSize(QSize(130, 51));
        serial1Box->setFont(font);
        serial1Box->setEditable(true);

        horizontalLayout->addWidget(serial1Box);

        openButton = new QPushButton(groupBox);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setMinimumSize(QSize(131, 51));
        openButton->setFont(font);

        horizontalLayout->addWidget(openButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        resShowButton = new QPushButton(groupBox);
        resShowButton->setObjectName(QString::fromUtf8("resShowButton"));
        resShowButton->setMinimumSize(QSize(260, 120));
        QFont font1;
        font1.setPointSize(24);
        resShowButton->setFont(font1);

        gridLayout->addWidget(resShowButton, 0, 1, 2, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        testStopButton = new QPushButton(groupBox);
        testStopButton->setObjectName(QString::fromUtf8("testStopButton"));
        testStopButton->setMinimumSize(QSize(130, 51));
        testStopButton->setFont(font);

        horizontalLayout_2->addWidget(testStopButton);

        testStartButton = new QPushButton(groupBox);
        testStartButton->setObjectName(QString::fromUtf8("testStartButton"));
        testStartButton->setEnabled(false);
        testStartButton->setMinimumSize(QSize(130, 51));
        testStartButton->setFont(font);

        horizontalLayout_2->addWidget(testStartButton);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1155, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        rclabel->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\344\272\247\345\223\201\344\272\214\347\273\264\347\240\201\346\211\223\346\240\207\345\217\267\347\240\201\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "   MCU\345\206\205\347\275\256ID\345\217\267\357\274\232", nullptr));
        IDlabel->setText(QCoreApplication::translate("MainWindow", "   --", nullptr));
        groupBox->setTitle(QString());
        openButton->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\350\256\276\345\244\207", nullptr));
        resShowButton->setText(QString());
        testStopButton->setText(QCoreApplication::translate("MainWindow", "\344\270\212\347\224\265", nullptr));
        testStartButton->setText(QCoreApplication::translate("MainWindow", "\346\265\213\350\257\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
