#ifndef SRCHDLG_H
#define SRCHDLG_H

#include <QDialog>
#include <QColor>
#include <QString>
#include <QVariantList>

#include <QDialog>
#include "ui_SrchDlg.h"

namespace LogWatcher {
/* GUI Class. Search Window. */
class SrchDlg : public QDialog
{
    Q_OBJECT

public:
    SrchDlg(QWidget* parent = Q_NULLPTR);
    ~SrchDlg();

    /* Combine text into regular expressions */
    QStringList searchString();
    
    /* Set the color of the search bar */
    QList<QVariant>  findComboBoxColor();

private:
    Ui::SrchDlg ui;
    QList<QVariant> m_numberOfAllCollors;
};
}
#endif // SRCHDLG_H