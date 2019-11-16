/********************************************************************************
** Form generated from reading UI file 'DataWidgetMapper.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAWIDGETMAPPER_H
#define UI_DATAWIDGETMAPPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataWidgetMapper
{
public:
    QGridLayout *gridLayout;
    QTableView *deviceTableView;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_2;
    QTableView *deviceTableView_2;

    void setupUi(QWidget *DataWidgetMapper)
    {
        if (DataWidgetMapper->objectName().isEmpty())
            DataWidgetMapper->setObjectName(QString::fromUtf8("DataWidgetMapper"));
        DataWidgetMapper->resize(860, 300);
        gridLayout = new QGridLayout(DataWidgetMapper);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        deviceTableView = new QTableView(DataWidgetMapper);
        deviceTableView->setObjectName(QString::fromUtf8("deviceTableView"));

        gridLayout->addWidget(deviceTableView, 0, 0, 1, 1);

        dockWidget = new QDockWidget(DataWidgetMapper);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setEnabled(true);
        dockWidget->setMinimumSize(QSize(111, 105));
        dockWidget->setMaximumSize(QSize(524287, 105));
        dockWidget->setMouseTracking(false);
        dockWidget->setAcceptDrops(false);
        dockWidget->setAutoFillBackground(false);
        dockWidget->setFloating(false);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout_2 = new QGridLayout(dockWidgetContents);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        deviceTableView_2 = new QTableView(dockWidgetContents);
        deviceTableView_2->setObjectName(QString::fromUtf8("deviceTableView_2"));

        gridLayout_2->addWidget(deviceTableView_2, 0, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);

        gridLayout->addWidget(dockWidget, 1, 0, 1, 1);


        retranslateUi(DataWidgetMapper);

        QMetaObject::connectSlotsByName(DataWidgetMapper);
    } // setupUi

    void retranslateUi(QWidget *DataWidgetMapper)
    {
        DataWidgetMapper->setWindowTitle(QApplication::translate("DataWidgetMapper", "DataWidgetMapper", nullptr));
        dockWidget->setWindowTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class DataWidgetMapper: public Ui_DataWidgetMapper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAWIDGETMAPPER_H
