#include "insulin.h"

Insulin::Insulin(QObject *parent) : QObject(parent) {}

Insulin::Insulin(const QString &arg_name, QObject *parent) : QObject(parent), name(arg_name) {}

Insulin::Insulin(const QString &arg_name, Insulin::InsulinTypes arg_type,  QObject *parent) : QObject(parent), type(arg_type), name(arg_name) {}

void Insulin::setName(const QString &arg_name)
{
    name = arg_name;
}

QString Insulin::getName() const
{
    return name;
}

void Insulin::setType(Insulin::InsulinTypes arg_type)
{
    type = arg_type;
}

Insulin::InsulinTypes Insulin::getType() const
{
    return type;
}

void Insulin::setVolume(const int &arg_volume)
{
    volume = arg_volume;
}

int Insulin::getVolume() const
{
    return volume;
}

void Insulin::setCurrentVolume(const int &arg_injection, const int &arg_averageInsDose)
{
    currentVolume -= arg_injection;
    if (currentVolume <= arg_averageInsDose)
    {
        emit on_lowInsulinVolume();
    }
}

int Insulin::getCurrentVolume() const
{
    return currentVolume;
}
