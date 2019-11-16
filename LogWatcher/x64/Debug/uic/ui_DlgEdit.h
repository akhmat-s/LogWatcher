/********************************************************************************
** Form generated from reading UI file 'DlgEdit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGEDIT_H
#define UI_DLGEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_DlgEdit
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *pushButtonSave;
    QGridLayout *gridLayout;
    QLineEdit *lineEditLog;
    QLineEdit *lineEditComment;
    QLabel *label_2;
    QLabel *label;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonNext;
    QRadioButton *radioButtonIntellect;

    void setupUi(QDialog *DlgEdit)
    {
        if (DlgEdit->objectName().isEmpty())
            DlgEdit->setObjectName(QString::fromUtf8("DlgEdit"));
        DlgEdit->resize(800, 95);
        gridLayout_2 = new QGridLayout(DlgEdit);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButtonSave = new QPushButton(DlgEdit);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));

        gridLayout_2->addWidget(pushButtonSave, 1, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEditLog = new QLineEdit(DlgEdit);
        lineEditLog->setObjectName(QString::fromUtf8("lineEditLog"));
        lineEditLog->setTabletTracking(false);
        lineEditLog->setFocusPolicy(Qt::NoFocus);
        lineEditLog->setReadOnly(true);

        gridLayout->addWidget(lineEditLog, 0, 2, 1, 1);

        lineEditComment = new QLineEdit(DlgEdit);
        lineEditComment->setObjectName(QString::fromUtf8("lineEditComment"));

        gridLayout->addWidget(lineEditComment, 1, 2, 1, 1);

        label_2 = new QLabel(DlgEdit);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        label = new QLabel(DlgEdit);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        groupBox = new QGroupBox(DlgEdit);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButtonNext = new QRadioButton(groupBox);
        radioButtonNext->setObjectName(QString::fromUtf8("radioButtonNext"));

        horizontalLayout->addWidget(radioButtonNext);

        radioButtonIntellect = new QRadioButton(groupBox);
        radioButtonIntellect->setObjectName(QString::fromUtf8("radioButtonIntellect"));
        radioButtonIntellect->setChecked(true);

        horizontalLayout->addWidget(radioButtonIntellect);


        gridLayout->addWidget(groupBox, 0, 0, 2, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(DlgEdit);

        QMetaObject::connectSlotsByName(DlgEdit);
    } // setupUi

    void retranslateUi(QDialog *DlgEdit)
    {
        DlgEdit->setWindowTitle(QApplication::translate("DlgEdit", "DlgEdit", nullptr));
        pushButtonSave->setText(QApplication::translate("DlgEdit", "Save", nullptr));
        label_2->setText(QApplication::translate("DlgEdit", "COMMENT", nullptr));
        label->setText(QApplication::translate("DlgEdit", "ORIGINAL LOG", nullptr));
        groupBox->setTitle(QString());
        radioButtonNext->setText(QApplication::translate("DlgEdit", "Next", nullptr));
        radioButtonIntellect->setText(QApplication::translate("DlgEdit", "Intellect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgEdit: public Ui_DlgEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGEDIT_H
