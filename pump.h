#ifndef PUMP_H
#define PUMP_H

#include <QObject>

class Pump : public QObject
{
    Q_OBJECT
public:
    explicit Pump(QObject *parent = nullptr);
    
signals:
    
public slots:
};

#endif // PUMP_H