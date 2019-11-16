/********************************************************************************
** Form generated from reading UI file 'DlgComment.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCOMMENT_H
#define UI_DLGCOMMENT_H

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

class Ui_DlgComment
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEditComment;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *lineEditLog;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButtonNext;
    QRadioButton *radioButtonIntellect;
    QPushButton *pushButtonSave;

    void setupUi(QDialog *DlgComment)
    {
        if (DlgComment->objectName().isEmpty())
            DlgComment->setObjectName(QString::fromUtf8("DlgComment"));
        DlgComment->resize(892, 124);
        gridLayout_3 = new QGridLayout(DlgComment);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        lineEditComment = new QLineEdit(DlgComment);
        lineEditComment->setObjectName(QString::fromUtf8("lineEditComment"));

        gridLayout_2->addWidget(lineEditComment, 1, 2, 1, 1);

        label_4 = new QLabel(DlgComment);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 1, 1, 1, 1);

        label_3 = new QLabel(DlgComment);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 1, 1, 1);

        lineEditLog = new QLineEdit(DlgComment);
        lineEditLog->setObjectName(QString::fromUtf8("lineEditLog"));
        lineEditLog->setTabletTracking(false);
        lineEditLog->setFocusPolicy(Qt::NoFocus);
        lineEditLog->setReadOnly(true);

        gridLayout_2->addWidget(lineEditLog, 0, 2, 1, 1);

        groupBox = new QGroupBox(DlgComment);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        radioButtonNext = new QRadioButton(groupBox);
        radioButtonNext->setObjectName(QString::fromUtf8("radioButtonNext"));
        radioButtonNext->setChecked(true);

        horizontalLayout_2->addWidget(radioButtonNext);

        radioButtonIntellect = new QRadioButton(groupBox);
        radioButtonIntellect->setObjectName(QString::fromUtf8("radioButtonIntellect"));

        horizontalLayout_2->addWidget(radioButtonIntellect);


        gridLayout_2->addWidget(groupBox, 0, 0, 2, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 2, 3);

        pushButtonSave = new QPushButton(DlgComment);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));

        gridLayout_3->addWidget(pushButtonSave, 2, 0, 1, 3);


        retranslateUi(DlgComment);

        QMetaObject::connectSlotsByName(DlgComment);
    } // setupUi

    void retranslateUi(QDialog *DlgComment)
    {
        DlgComment->setWindowTitle(QApplication::translate("DlgComment", "DlgComment", nullptr));
        label_4->setText(QApplication::translate("DlgComment", "COMMENT", nullptr));
        label_3->setText(QApplication::translate("DlgComment", "ORIGINAL LOG", nullptr));
        groupBox->setTitle(QString());
        radioButtonNext->setText(QApplication::translate("DlgComment", "Next", nullptr));
        radioButtonIntellect->setText(QApplication::translate("DlgComment", "Intellect", nullptr));
        pushButtonSave->setText(QApplication::translate("DlgComment", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgComment: public Ui_DlgComment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCOMMENT_H
