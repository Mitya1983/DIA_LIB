#ifndef DAILYDOSE_H
#define DAILYDOSE_H

#include <QDate>
#include <QString>
#include "insulindose.h"

class DailyDose : public InsulinDose
{
    Q_OBJECT
    QDate date;
public:
    DailyDose();
    DailyDose(const double &arg_dose);
    Q_INVOKABLE QString getDate() const;
    Q_INVOKABLE QString getData() override;

signals:
    
public slots:
    void setDose(const double &arg_dose) override;
};

#endif // DAILYDOSE_H
