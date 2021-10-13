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

bool BackendTable::setData(const QModelIndex &new_index, const QVariant &value, int role)
{
    // вычестяем идентификатор изменяемого индекса в таблице mm_table
    quint16 new_index_list = new_index.row() * WIDTH_PLACE + new_index.column();
//    mm_table[new_index_list] = value.toString();
    // оповещаем GUI о изменении ячейки
//    emit dataChanged(new_index, new_index);
//     проверяем по вертикали и горизонтали
//    checkVert(new_index, color);
//    checkHor(new_index, color);
    return true;
}
QString BackendTable::getValue(const QModelIndex &index) const
{
    QString value = mm_table.value(index.row() * WIDTH_PLACE + index.column());
    return value;
}
