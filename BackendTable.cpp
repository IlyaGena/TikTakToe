#include "BackendTable.h"

BackendTable::BackendTable(QObject *parent) :
    QAbstractTableModel(parent),
    mm_algorithm(this),
    mm_selectUser(CROSS),
    mm_selectComp(ZERO),
    mm_random()
{

}

BackendTable::~BackendTable()
{

}

int BackendTable::rowCount(const QModelIndex&) const
{
    return mm_countRow;
}

int BackendTable::columnCount(const QModelIndex&) const
{
    return mm_countCol;
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

bool BackendTable::setData(const QModelIndex &new_index)
{
    // вычестяем идентификатор изменяемого индекса в таблице mm_table
    quint16 new_index_list = new_index.row() * mm_countCol + new_index.column();
    mm_table[new_index_list] = mm_selectUser;

    emit dataChanged(new_index, new_index);

    if(mm_algorithm.checkResult(mm_table, mm_selectUser))
    {
        emit sig_EndGame();
        return true;
    }

    step();
    return true;
}

bool BackendTable::startGame(quint16 count, QString select_elem)
{
    mm_countCol = count;
    mm_countRow = count;
    mm_count = mm_countCol * mm_countRow;

    if (!mm_table.isEmpty())
        newGame();

    for (quint32 i = 0; i < mm_count; i++)
        mm_table.insert(i, "Null");

    if (select_elem != CROSS)
    {
        mm_selectComp = CROSS;
        mm_selectUser = ZERO;

        mm_algorithm.setElem(CROSS);

        quint32 firstStep = mm_random.bounded(mm_count);
        mm_table[firstStep] = mm_selectComp;
        QModelIndex changeIndex = getIndex(firstStep);
        emit dataChanged(changeIndex, changeIndex);
    }

    emit sig_StartGame();
    return true;
}

bool BackendTable::step()
{
    if (!mm_table.values().contains("Null"))
        return false;

    Move step = mm_algorithm.getIndex(mm_table, mm_selectComp);
    qDebug() << "Index: " << step.index;
    qDebug() << "Count: " << mm_algorithm.getcount();
    mm_algorithm.resetCount();
    mm_table[step.index] = mm_selectComp;
    QModelIndex changeIndex = getIndex(step.index);
    emit dataChanged(changeIndex, changeIndex);

    if(mm_algorithm.checkResult(mm_table, mm_selectComp))
        emit sig_EndGame();

    return true;
}

void BackendTable::newGame()
{
    for (quint32 i = 0; i < mm_count; i++)
        mm_table[i] = "Null";

    emit dataChanged(this->index(0,0), this->index(mm_countRow, mm_countCol));

    if (mm_selectComp == CROSS)
    {
        quint32 firstStep = mm_random.bounded(mm_count);
        mm_table[firstStep] = mm_selectComp;
        QModelIndex changeIndex = getIndex(firstStep);
        emit dataChanged(changeIndex, changeIndex);
    }
}
QString BackendTable::getValue(const QModelIndex &index) const
{
    quint16 index_list = index.row() * mm_countCol + index.column();
    QString value = mm_table.value(index_list);
    return value;
}

quint16 BackendTable::getIndexList(const QModelIndex &index) const
{
    quint16 index_list = index.row() * mm_countCol + index.column();
    return index_list;
}

QModelIndex BackendTable::getIndex(quint16 index)
{
    quint16 col = index % mm_countRow;
    quint16 row = index / mm_countRow;

    qDebug() << "Index: " << index;
    qDebug() << "Col: " << col;
    qDebug() << "Row: " << row;

    return this->index(row, col);
}
