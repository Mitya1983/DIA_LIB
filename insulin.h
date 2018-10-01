#ifndef INSULIN_H
#define INSULIN_H

#include <QObject>

class Insulin : public QObject
{
    Q_OBJECT
public:
    explicit Insulin(QObject *parent = nullptr);
    
signals:
    
public slots:
};

#endif // INSULIN_H