#ifndef MYSTRINGLISTMODEL_H
#define MYSTRINGLISTMODEL_H

#include <QObject>
#include <QStringListModel>
#include <iostream>
#include <sstream>
#include <string>
#include <QBrush>
#include <QColor>
#include <QMap>
#include <QVariant>

namespace LogWatcher {
/* This class expands the ability QStringListModel */
class MyStringListModel : public QStringListModel
{
public:
    MyStringListModel(QObject* parent = Q_NULLPTR);

	/* Overriding QStringListModel class methods,
     * so that it would be possible to add colors to the ListView
     * */
	QVariant data(const QModelIndex& index, int role) const override;
	bool setData(const QModelIndex& index, const QVariant& value, int role) override;

private:
	std::map<int, QColor> m_rowColors;
};
}
#endif // MYSTRINGLISTMODEL_H