#include "BackendTable.h"

BackendTable::BackendTable(QObject *parent) :
    QAbstractTableModel(parent)
{

}

BackendTable::~BackendTable()
{

}

int BackendTable::rowCount(const QModelIndex&) const
{
    return HEIGHT_PLACE;
}

int BackendTable::columnCount(const QModelIndex&) const
{
    return WIDTH_PLACE;
}

QVariant BackendTable::data(const QModelIndex &index, int role) const
{
    switch (role) {
    case Qt::DisplayRole:
    {
        //получение цвета и его возврат
        QString value = getValue(index);
        return value;
    }
    default:
        break;
    }

    return QVariant();
}

QString BackendTable::getValue(const QModelIndex &index) const
{
    QString value = mm_table.value(index.row() * WIDTH_PLACE + index.column());
    return value;
}
