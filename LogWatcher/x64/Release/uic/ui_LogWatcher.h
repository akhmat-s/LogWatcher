/********************************************************************************
** Form generated from reading UI file 'LogWatcher.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGWATCHER_H
#define UI_LOGWATCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogWatcherClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonNext;
    QRadioButton *radioButtonIntellect;
    QPushButton *openButton;
    QPushButton *pushButtonOpenSearch;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBoxDebug;
    QComboBox *comboBoxDebug;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBoxInfo;
    QComboBox *comboBoxInfo;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBoxError;
    QComboBox *comboBoxError;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBoxWarning;
    QComboBox *comboBoxWarning;
    QPushButton *pushButtonAnalyz;
    QPushButton *pushButtonEditData;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_7;
    QTabWidget *tabWidget_2;

    void setupUi(QMainWindow *LogWatcherClass)
    {
        if (LogWatcherClass->objectName().isEmpty())
            LogWatcherClass->setObjectName(QString::fromUtf8("LogWatcherClass"));
        LogWatcherClass->resize(1051, 673);
        centralWidget = new QWidget(LogWatcherClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_6 = new QGridLayout(centralWidget);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        groupBox_3->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButtonNext = new QRadioButton(groupBox);
        radioButtonNext->setObjectName(QString::fromUtf8("radioButtonNext"));
        radioButtonNext->setFont(font);
        radioButtonNext->setChecked(true);

        horizontalLayout->addWidget(radioButtonNext);

        radioButtonIntellect = new QRadioButton(groupBox);
        radioButtonIntellect->setObjectName(QString::fromUtf8("radioButtonIntellect"));
        radioButtonIntellect->setFont(font);

        horizontalLayout->addWidget(radioButtonIntellect);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 2);

        openButton = new QPushButton(groupBox_3);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(openButton->sizePolicy().hasHeightForWidth());
        openButton->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(openButton, 1, 0, 1, 1);

        pushButtonOpenSearch = new QPushButton(groupBox_3);
        pushButtonOpenSearch->setObjectName(QString::fromUtf8("pushButtonOpenSearch"));
        sizePolicy.setHeightForWidth(pushButtonOpenSearch->sizePolicy().hasHeightForWidth());
        pushButtonOpenSearch->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(pushButtonOpenSearch, 1, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 0, 0, 2, 1);

        groupBox_5 = new QGroupBox(groupBox_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setFont(font);
        gridLayout_2 = new QGridLayout(groupBox_5);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        checkBoxDebug = new QCheckBox(groupBox_5);
        checkBoxDebug->setObjectName(QString::fromUtf8("checkBoxDebug"));
        checkBoxDebug->setFont(font);
        checkBoxDebug->setChecked(false);

        horizontalLayout_3->addWidget(checkBoxDebug);

        comboBoxDebug = new QComboBox(groupBox_5);
        comboBoxDebug->addItem(QString());
        comboBoxDebug->addItem(QString());
        comboBoxDebug->addItem(QString());
        comboBoxDebug->addItem(QString());
        comboBoxDebug->addItem(QString());
        comboBoxDebug->addItem(QString());
        comboBoxDebug->addItem(QString());
        comboBoxDebug->addItem(QString());
        comboBoxDebug->addItem(QString());
        comboBoxDebug->addItem(QString());
        comboBoxDebug->addItem(QString());
        comboBoxDebug->setObjectName(QString::fromUtf8("comboBoxDebug"));

        horizontalLayout_3->addWidget(comboBoxDebug);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        checkBoxInfo = new QCheckBox(groupBox_5);
        checkBoxInfo->setObjectName(QString::fromUtf8("checkBoxInfo"));
        checkBoxInfo->setFont(font);

        horizontalLayout_2->addWidget(checkBoxInfo);

        comboBoxInfo = new QComboBox(groupBox_5);
        comboBoxInfo->addItem(QString());
        comboBoxInfo->addItem(QString());
        comboBoxInfo->addItem(QString());
        comboBoxInfo->addItem(QString());
        comboBoxInfo->addItem(QString());
        comboBoxInfo->addItem(QString());
        comboBoxInfo->addItem(QString());
        comboBoxInfo->addItem(QString());
        comboBoxInfo->addItem(QString());
        comboBoxInfo->addItem(QString());
        comboBoxInfo->addItem(QString());
        comboBoxInfo->setObjectName(QString::fromUtf8("comboBoxInfo"));
        comboBoxInfo->setEnabled(true);

        horizontalLayout_2->addWidget(comboBoxInfo);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        checkBoxError = new QCheckBox(groupBox_5);
        checkBoxError->setObjectName(QString::fromUtf8("checkBoxError"));
        checkBoxError->setFont(font);

        horizontalLayout_5->addWidget(checkBoxError);

        comboBoxError = new QComboBox(groupBox_5);
        comboBoxError->addItem(QString());
        comboBoxError->addItem(QString());
        comboBoxError->addItem(QString());
        comboBoxError->addItem(QString());
        comboBoxError->addItem(QString());
        comboBoxError->addItem(QString());
        comboBoxError->addItem(QString());
        comboBoxError->addItem(QString());
        comboBoxError->addItem(QString());
        comboBoxError->addItem(QString());
        comboBoxError->addItem(QString());
        comboBoxError->setObjectName(QString::fromUtf8("comboBoxError"));

        horizontalLayout_5->addWidget(comboBoxError);


        gridLayout_2->addLayout(horizontalLayout_5, 0, 3, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        checkBoxWarning = new QCheckBox(groupBox_5);
        checkBoxWarning->setObjectName(QString::fromUtf8("checkBoxWarning"));
        checkBoxWarning->setFont(font);

        horizontalLayout_4->addWidget(checkBoxWarning);

        comboBoxWarning = new QComboBox(groupBox_5);
        comboBoxWarning->addItem(QString());
        comboBoxWarning->addItem(QString());
        comboBoxWarning->addItem(QString());
        comboBoxWarning->addItem(QString());
        comboBoxWarning->addItem(QString());
        comboBoxWarning->addItem(QString());
        comboBoxWarning->addItem(QString());
        comboBoxWarning->addItem(QString());
        comboBoxWarning->addItem(QString());
        comboBoxWarning->addItem(QString());
        comboBoxWarning->addItem(QString());
        comboBoxWarning->setObjectName(QString::fromUtf8("comboBoxWarning"));

        horizontalLayout_4->addWidget(comboBoxWarning);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 2, 1, 1);

        pushButtonAnalyz = new QPushButton(groupBox_5);
        pushButtonAnalyz->setObjectName(QString::fromUtf8("pushButtonAnalyz"));
        pushButtonAnalyz->setFont(font);

        gridLayout_2->addWidget(pushButtonAnalyz, 0, 4, 1, 1);


        gridLayout_4->addWidget(groupBox_5, 0, 1, 1, 1);

        pushButtonEditData = new QPushButton(groupBox_2);
        pushButtonEditData->setObjectName(QString::fromUtf8("pushButtonEditData"));
        sizePolicy.setHeightForWidth(pushButtonEditData->sizePolicy().hasHeightForWidth());
        pushButtonEditData->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(pushButtonEditData, 1, 1, 1, 1);


        gridLayout_6->addWidget(groupBox_2, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setTabsClosable(true);

        gridLayout_6->addWidget(tabWidget, 1, 0, 1, 1);

        LogWatcherClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LogWatcherClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1051, 21));
        LogWatcherClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(LogWatcherClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        LogWatcherClass->setStatusBar(statusBar);
        dockWidget = new QDockWidget(LogWatcherClass);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout_7 = new QGridLayout(dockWidgetContents);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        tabWidget_2 = new QTabWidget(dockWidgetContents);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setTabsClosable(true);

        gridLayout_7->addWidget(tabWidget_2, 0, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);
        LogWatcherClass->addDockWidget(Qt::BottomDockWidgetArea, dockWidget);

        retranslateUi(LogWatcherClass);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(LogWatcherClass);
    } // setupUi

    void retranslateUi(QMainWindow *LogWatcherClass)
    {
        LogWatcherClass->setWindowTitle(QCoreApplication::translate("LogWatcherClass", "LogWatcher", nullptr));
        groupBox_2->setTitle(QString());
        groupBox_3->setTitle(QString());
        groupBox->setTitle(QString());
        radioButtonNext->setText(QCoreApplication::translate("LogWatcherClass", "NEXT", nullptr));
        radioButtonIntellect->setText(QCoreApplication::translate("LogWatcherClass", "INTELLECT", nullptr));
        openButton->setText(QCoreApplication::translate("LogWatcherClass", "OPEN", nullptr));
        pushButtonOpenSearch->setText(QCoreApplication::translate("LogWatcherClass", "SEARCH", nullptr));
        groupBox_5->setTitle(QString());
        checkBoxDebug->setText(QCoreApplication::translate("LogWatcherClass", "DEBUG", nullptr));
        comboBoxDebug->setItemText(0, QCoreApplication::translate("LogWatcherClass", "White", nullptr));
        comboBoxDebug->setItemText(1, QCoreApplication::translate("LogWatcherClass", "Red", nullptr));
        comboBoxDebug->setItemText(2, QCoreApplication::translate("LogWatcherClass", "Yellow", nullptr));
        comboBoxDebug->setItemText(3, QCoreApplication::translate("LogWatcherClass", "Cyan", nullptr));
        comboBoxDebug->setItemText(4, QCoreApplication::translate("LogWatcherClass", "Violet", nullptr));
        comboBoxDebug->setItemText(5, QCoreApplication::translate("LogWatcherClass", "Purple", nullptr));
        comboBoxDebug->setItemText(6, QCoreApplication::translate("LogWatcherClass", "Magenta", nullptr));
        comboBoxDebug->setItemText(7, QCoreApplication::translate("LogWatcherClass", "Lavender", nullptr));
        comboBoxDebug->setItemText(8, QCoreApplication::translate("LogWatcherClass", "Gray", nullptr));
        comboBoxDebug->setItemText(9, QCoreApplication::translate("LogWatcherClass", "Green", nullptr));
        comboBoxDebug->setItemText(10, QCoreApplication::translate("LogWatcherClass", "Blue", nullptr));

        checkBoxInfo->setText(QCoreApplication::translate("LogWatcherClass", "INFO", nullptr));
        comboBoxInfo->setItemText(0, QCoreApplication::translate("LogWatcherClass", "White", nullptr));
        comboBoxInfo->setItemText(1, QCoreApplication::translate("LogWatcherClass", "Red", nullptr));
        comboBoxInfo->setItemText(2, QCoreApplication::translate("LogWatcherClass", "Yellow", nullptr));
        comboBoxInfo->setItemText(3, QCoreApplication::translate("LogWatcherClass", "Cyan", nullptr));
        comboBoxInfo->setItemText(4, QCoreApplication::translate("LogWatcherClass", "Violet", nullptr));
        comboBoxInfo->setItemText(5, QCoreApplication::translate("LogWatcherClass", "Purple", nullptr));
        comboBoxInfo->setItemText(6, QCoreApplication::translate("LogWatcherClass", "Magenta", nullptr));
        comboBoxInfo->setItemText(7, QCoreApplication::translate("LogWatcherClass", "Lavender", nullptr));
        comboBoxInfo->setItemText(8, QCoreApplication::translate("LogWatcherClass", "Gray", nullptr));
        comboBoxInfo->setItemText(9, QCoreApplication::translate("LogWatcherClass", "Green", nullptr));
        comboBoxInfo->setItemText(10, QCoreApplication::translate("LogWatcherClass", "Blue", nullptr));

        checkBoxError->setText(QCoreApplication::translate("LogWatcherClass", "ERROR", nullptr));
        comboBoxError->setItemText(0, QCoreApplication::translate("LogWatcherClass", "White", nullptr));
        comboBoxError->setItemText(1, QCoreApplication::translate("LogWatcherClass", "Red", nullptr));
        comboBoxError->setItemText(2, QCoreApplication::translate("LogWatcherClass", "Yellow", nullptr));
        comboBoxError->setItemText(3, QCoreApplication::translate("LogWatcherClass", "Cyan", nullptr));
        comboBoxError->setItemText(4, QCoreApplication::translate("LogWatcherClass", "Violet", nullptr));
        comboBoxError->setItemText(5, QCoreApplication::translate("LogWatcherClass", "Purple", nullptr));
        comboBoxError->setItemText(6, QCoreApplication::translate("LogWatcherClass", "Magenta", nullptr));
        comboBoxError->setItemText(7, QCoreApplication::translate("LogWatcherClass", "Lavender", nullptr));
        comboBoxError->setItemText(8, QCoreApplication::translate("LogWatcherClass", "Gray", nullptr));
        comboBoxError->setItemText(9, QCoreApplication::translate("LogWatcherClass", "Green", nullptr));
        comboBoxError->setItemText(10, QCoreApplication::translate("LogWatcherClass", "Blue", nullptr));

        checkBoxWarning->setText(QCoreApplication::translate("LogWatcherClass", "WARNING", nullptr));
        comboBoxWarning->setItemText(0, QCoreApplication::translate("LogWatcherClass", "White", nullptr));
        comboBoxWarning->setItemText(1, QCoreApplication::translate("LogWatcherClass", "Red", nullptr));
        comboBoxWarning->setItemText(2, QCoreApplication::translate("LogWatcherClass", "Yellow", nullptr));
        comboBoxWarning->setItemText(3, QCoreApplication::translate("LogWatcherClass", "Cyan", nullptr));
        comboBoxWarning->setItemText(4, QCoreApplication::translate("LogWatcherClass", "Violet", nullptr));
        comboBoxWarning->setItemText(5, QCoreApplication::translate("LogWatcherClass", "Purple", nullptr));
        comboBoxWarning->setItemText(6, QCoreApplication::translate("LogWatcherClass", "Magenta", nullptr));
        comboBoxWarning->setItemText(7, QCoreApplication::translate("LogWatcherClass", "Lavender", nullptr));
        comboBoxWarning->setItemText(8, QCoreApplication::translate("LogWatcherClass", "Gray", nullptr));
        comboBoxWarning->setItemText(9, QCoreApplication::translate("LogWatcherClass", "Green", nullptr));
        comboBoxWarning->setItemText(10, QCoreApplication::translate("LogWatcherClass", "Blue", nullptr));

        pushButtonAnalyz->setText(QCoreApplication::translate("LogWatcherClass", "ANALYZE", nullptr));
        pushButtonEditData->setText(QCoreApplication::translate("LogWatcherClass", "EDIT DATABASE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogWatcherClass: public Ui_LogWatcherClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGWATCHER_H
