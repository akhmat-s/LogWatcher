#ifndef DLGCOMMENT_H
#define DLGCOMMENT_H

#include <QDialog>
#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include <QMessageBox>
#include <QRegExpValidator>
#include <QScrollBar>

#include "ui_DlgComment.h"
#include "DataBase.h"

namespace LogWatcher {
/* GUI Class, responsible for adding the log to the database */
class DlgComment : public QDialog
{
    Q_OBJECT

public:
    explicit DlgComment(int row = -1, QWidget* parent = Q_NULLPTR);
    ~DlgComment();

    Ui::DlgComment& getUI() { return ui; }

signals:
    void signalReady();

private slots:
    void on_buttonBox_accepted();

private:
    /* Initializing the model */
    void setupModel();

    Ui::DlgComment ui;
    QSqlTableModel* m_model;
    QDataWidgetMapper* m_mapper;
};
}
#endif // DLGCOMMENT_H