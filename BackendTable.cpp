#include "BackendTable.h"

BackendTable::BackendTable(QObject *parent) :
    QAbstractTableModel(parent),
    mm_count(3)
{

}

BackendTable::~BackendTable()
{

}

int BackendTable::rowCount(const QModelIndex&) const
{
    return mm_count;
}

int BackendTable::columnCount(const QModelIndex&) const
{
    return mm_count;
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
    quint16 new_index_list = new_index.row() * mm_count + new_index.column();
//    mm_table[new_index_list] = value.toString();
    // оповещаем GUI о изменении ячейки
//    emit dataChanged(new_index, new_index);
//     проверяем по вертикали и горизонтали
//    checkVert(new_index, color);
//    checkHor(new_index, color);
    return true;
}

bool BackendTable::startGame(quint16 count, QString select_elem)
{
    mm_count = count;

    // сделать шаг
    if (select_elem != "X")
        return false;

    emit sig_StartGame();
    return true;
}
QString BackendTable::getValue(const QModelIndex &index) const
{
    QString value = mm_table.value(index.row() * mm_count + index.column());
    return value;
}
