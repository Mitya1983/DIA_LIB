#ifndef INSULINDOSE_H
#define INSULINDOSE_H

#include <QObject>

class InsulinDose : public QObject
{
    Q_OBJECT
public:
    explicit InsulinDose(QObject *parent = nullptr);
    
signals:
    
public slots:
};

#endif // INSULINDOSE_H