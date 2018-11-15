#include "dailydose.h"

DailyDose::DailyDose() : InsulinDose () {}

DailyDose::DailyDose(const double &arg_dose) : InsulinDose (arg_dose), date(QDate::currentDate()) {}

QString DailyDose::getDate() const
{
    QString _date = date.toString("dd.MM.yyyy");
    return _date;
}

QString DailyDose::getData()
{
    QString data = date.toString("dd.MM.yyyy") + " | " + QString::number(dose);
    return data;
}

void DailyDose::setDose(const double &arg_dose)
{
    dose = arg_dose;
    date = QDate::currentDate();
    emit on_doseValueChanged();
}
