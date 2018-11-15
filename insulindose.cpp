#include "insulindose.h"

InsulinDose::InsulinDose(QObject *parent) : QObject(parent){}

InsulinDose::InsulinDose(const double &arg_dose, QObject *parent) : QObject(parent), dose(arg_dose) {}

double InsulinDose::getDose() const
{
    return dose;
}

QString InsulinDose::getData()
{
    QString data = QString::number(dose);
    return data;
}

void InsulinDose::setDose(const double &arg_dose)
{
    dose = arg_dose;
    emit on_doseValueChanged();
}

