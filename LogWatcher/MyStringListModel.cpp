#include "MyStringListModel.h"

namespace LogWatcher {
MyStringListModel::MyStringListModel(QObject* parent)
    : QStringListModel(parent)
{
}

QVariant MyStringListModel::data(const QModelIndex& index, int role) const
{
    if( role == Qt::ForegroundRole )
    {
        auto itr = m_rowColors.find(index.row());
        if (itr != m_rowColors.end())
        {
            return itr->second; 
        }
    }
    return QStringListModel::data(index, role);
}

bool MyStringListModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if( role == Qt::ForegroundRole )
    {
        m_rowColors[index.row()] = value.value<QColor>();
        return true;
    }
    return QStringListModel::setData(index, value, role);
}
}