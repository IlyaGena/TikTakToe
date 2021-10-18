#ifndef MINMAXALGORITHM_H
#define MINMAXALGORITHM_H

#include <QObject>
#include <QMap>

#define CROSS "X"
#define ZERO "O"

/*!
 * \brief The MinMaxAlgorithm class - класс алгоритма
 */
struct Move{
    qint32 score = 0;
    QString value = "";
    quint16 index = 0;
};

class MinMaxAlgorithm : public QObject
{
    Q_OBJECT
public:
    MinMaxAlgorithm(QObject *parent);

    Move getIndex(QMap<quint16, QString> orig_table, QString value);

    quint16 getcount();

    void setElem(QString elem_user);

    void resetCount();

private:
    /*!
     * \brief checkEmpty
     * \return  - возврат пустых индексов
     */
    QList<quint16> checkEmpty(QMap<quint16, QString> orig_table);

    /*!
     * \brief checkResult
     * \return - возврат проверки поля
     */
    bool checkResult(QMap<quint16, QString> table, QString value);

private:
    quint16 mm_count;
    QString mm_elem_comp = CROSS;
    QString mm_elem_user = ZERO;
};

#endif // MINMAXALGORITHM_H
