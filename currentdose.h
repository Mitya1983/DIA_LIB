#ifndef CURRENTDOSE_H
#define CURRENTDOSE_H

#include <QTime>
#include <QString>
#include "insulindose.h"


class CurrentDose : public InsulinDose
{
    Q_OBJECT
    QTime time;
public:
    CurrentDose();
    CurrentDose(const double &arg_dose);
    Q_INVOKABLE QString getTime() const;
    Q_INVOKABLE QString getData() override;

signals:
    
public slots:
    void setDose(const double &arg_dose) override;    
};

#endif // CURRENTDOSE_H
