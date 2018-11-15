#include "user.h"

User::User(QObject *parent) : QObject(parent) {}

User::User(const QString &arg_name, const QString &arg_surname, QObject *parent) : QObject(parent), name(arg_name), surname(arg_surname) {}

void User::setName(const QString &arg_name)
{
    name = arg_name;
}

QString User::getName() const
{
    return name;
}

void User::setSurname(const QString &arg_surname)
{
    surname = arg_surname;
}

QString User::getSurname() const
{
    return surname;
}
