#include "currentdose.h"

CurrentDose::CurrentDose() : InsulinDose () {}

CurrentDose::CurrentDose(const double &arg_dose) : InsulinDose (arg_dose), time (QTime::currentTime()) {}

QString CurrentDose::getTime() const
{
    QString _time = time.toString("hh:mm:ss");
    return _time;
}

QString CurrentDose::getData()
{
    QString data = time.toString("hh:mm:ss") + " | " + QString::number(dose);
    return data;
}

void CurrentDose::setDose(const double &arg_dose)
{
    dose = arg_dose;
    time = QTime::currentTime();
    emit on_doseValueChanged();
}
