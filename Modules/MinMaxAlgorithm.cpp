#include "MinMaxAlgorithm.h"

MinMaxAlgorithm::MinMaxAlgorithm(QObject* parent) :
    QObject(parent),
    mm_count(0)
{
}

Move MinMaxAlgorithm::getIndex(QMap<quint16, QString> new_table, QString value)
{
    mm_count++;

    Move returnMove;

    // получение списка индексов пустых клеток
    QList<quint16> availSpots = checkEmpty(new_table);

    // проверка результата на выигрыш или проигрыш
    if (checkResult(new_table, mm_elem_comp))
    {
        returnMove.score += 10;
        return returnMove;
    }
    else if (checkResult(new_table, mm_elem_user))
    {
        returnMove.score -= 10;
        return returnMove;
    }
    else if (availSpots.isEmpty())
    {
        returnMove.score += 0;
        return returnMove;
    }

    // an array to collect all the objects
    QList<Move> moves;

    // loop through available spots
    for (auto i = 0; i < availSpots.count(); i++){
        //create an object for each and store the index of that spot that was stored as a number in the object's index key
        Move move;
        // запоминаем индекс
        move.index = availSpots[i];

        // делаем шаг
        new_table[availSpots[i]] = value;

        // делаем шагн соперником
        Move result;

        if (value == mm_elem_comp)
            result = getIndex(new_table, mm_elem_user);
        if (value == mm_elem_user)
            result = getIndex(new_table, mm_elem_comp);

        move.score = result.score;

        // обнуляем свой ход
        new_table[availSpots[i]] = "Null";

        // добавляем в итоговый список
        moves.append(move);
    }

    // ищем лучший ход
    quint64 bestMove = 0;
    if(value == mm_elem_comp){
    qint64 bestScore = -10000;
    for(auto i = 0; i < moves.count(); i++){
        if(moves[i].score > bestScore){
            bestScore = moves[i].score;
            bestMove = i;
        }
    }
    }else{
        qint64 bestScore = 10000;
        for(auto i = 0; i < moves.count(); i++){
            if(moves[i].score < bestScore){
                bestScore = moves[i].score;
                bestMove = i;
            }
        }
    }

    // return the chosen move (object) from the array to the higher depth
    return moves[bestMove];
}

quint16 MinMaxAlgorithm::getcount()
{
    return mm_count;
}

void MinMaxAlgorithm::setElem(QString elem_user)
{
    mm_elem_comp = (elem_user == CROSS ? ZERO : CROSS);
    mm_elem_user = elem_user;
}

void MinMaxAlgorithm::resetCount()
{
    mm_count = 0;
}

QList<quint16> MinMaxAlgorithm::checkEmpty(QMap<quint16, QString> table)
{
    QList<quint16> empty_list;
    foreach(quint16 index, table.keys())
    {
        QString val = table.value(index);
        if (val != CROSS && val != ZERO)
            empty_list.append(index);
    }

    return empty_list;
}

bool MinMaxAlgorithm::checkResult(QMap<quint16, QString> table, QString value)
{
    if (    (table.value(0) == value && table.value(1) == value && table.value(2) == value) ||
            (table.value(3) == value && table.value(4) == value && table.value(5) == value) ||
            (table.value(6) == value && table.value(7) == value && table.value(8) == value) ||
            (table.value(0) == value && table.value(3) == value && table.value(6) == value) ||
            (table.value(1) == value && table.value(4) == value && table.value(7) == value) ||
            (table.value(2) == value && table.value(5) == value && table.value(8) == value) ||
            (table.value(0) == value && table.value(4) == value && table.value(8) == value) ||
            (table.value(2) == value && table.value(4) == value && table.value(6) == value))
        return true;

    else
        return false;

}
