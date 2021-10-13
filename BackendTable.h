#ifndef BACKENDTABLE_H
#define BACKENDTABLE_H

#include <QObject>
#include <QAbstractTableModel>
#include <qqml.h>

#define WIDTH_PLACE 3
#define HEIGHT_PLACE 3

#define ELEMENT_X "X"
#define ELEMENT_O "O"

class BackendTable : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT
    QML_ADDED_IN_MINOR_VERSION(1)

public:
    BackendTable(QObject *parent = nullptr);
    ~BackendTable();

    /*!
     * \brief rowCount - получение количества строк
     * \return - количество строк
     */
    int rowCount(const QModelIndex& = QModelIndex()) const override;

    /*!
     * \brief columnCount - получение количества столбцов
     * \return - количество столбцов
     */
    Q_INVOKABLE int columnCount(const QModelIndex& = QModelIndex()) const override;

    /*!
     * \brief data - получение информации
     * \param index - запрашиваемый индекс
     * \param role - роль
     * \return - данные
     */
    QVariant data(const QModelIndex &index, int role) const override;

    /*!
     * \brief setData
     * \param new_index
     * \param value
     * \param role
     * \return
     */
    Q_INVOKABLE bool setData(const QModelIndex &new_index, const QVariant &value, int role) override;
private:
    /*!
     * \brief getValue - получение значения из mm_table
     * \param index - индекс из таблицы
     * \return - значение
     */
    QString getValue(const QModelIndex &index) const;

private:
    QMap<quint8, QString> mm_table;         //!< список значений в таблице
};

#endif // BACKENDTABLE_H
