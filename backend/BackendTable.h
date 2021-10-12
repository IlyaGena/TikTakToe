#ifndef BACKENDTABLE_H
#define BACKENDTABLE_H

#include <QObject>
#include <QAbstractTableModel>
#include <qqml.h>

class BackendTable : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT
    QML_ADDED_IN_MINOR_VERSION(1)

public:
    BackendTable();
};

#endif // BACKENDTABLE_H
