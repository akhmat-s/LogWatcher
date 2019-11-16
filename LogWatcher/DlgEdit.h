#ifndef DLGEDIT_H
#define DLGEDIT_H

#include <QDialog>
#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include <QMessageBox>
#include <QRegExpValidator>
#include <QScrollBar>

#include "ui_DlgEdit.h"
#include "DataBase.h"

namespace LogWatcher {
/* GUI Class, responsible for editing the log to the database */
class DlgEdit : public QDialog
{
    Q_OBJECT

public:
    explicit DlgEdit(int row = -1, QWidget* parent = Q_NULLPTR);
    ~DlgEdit();

signals:
    void signalReady();

private slots:
    void on_buttonBox_accepted();

private:
    /* Initializing the model */
    void setupModel();

    Ui::DlgEdit ui;
    QSqlTableModel* m_model;
    QDataWidgetMapper* m_mapper;
};
}
#endif // DLGEDIT_H