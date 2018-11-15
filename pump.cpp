#include "pump.h"

Pump::Pump(QObject *parent) : QObject(parent) {}

Pump::Pump(const QString &arg_manufacturer, const QString &arg_model, const int &arg_volume, QObject *parent) : 
    QObject (parent), manufacturer(arg_manufacturer), model(arg_model), volume(arg_volume) {}

void Pump::setManufacturer(const QString &arg_manufacturer)
{
    manufacturer = arg_manufacturer;
}

QString Pump::getManufacturer() const
{
    return manufacturer;
}

void Pump::setModel(const QString &arg_model)
{
    model = arg_model;
}

QString Pump::getModel() const
{
    return model;
}

void Pump::setVolume(const int &arg_volume)
{
    volume = arg_volume;
}

int Pump::getVolume() const
{
    return volume;
}

void Pump::setCurrentVolume(const int &arg_injection, const int &arg_averageInsDose)
{
    currentVolume -= arg_injection;
    if (currentVolume <= arg_averageInsDose)
    {
        emit on_lowInsulinVolume();
    }
}

int Pump::getCurrentVolume() const
{
    return currentVolume;
}
