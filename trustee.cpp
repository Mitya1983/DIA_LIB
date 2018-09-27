#include "trustee.h"

Trustee::Trustee() {}

Trustee::Trustee(const QString &arg_name, const QString &arg_surname, const QString &arg_cellPhone) :
                    User(arg_name, arg_surname), cellPhone(arg_cellPhone) {}

Trustee::Trustee(const QString &arg_name, const QString &arg_surname, const QString &arg_cellPhone, const QString &arg_workPhone) :
                    User(arg_name, arg_surname), cellPhone(arg_cellPhone), workPhone(arg_workPhone) {}

Trustee::Trustee(const QString &arg_name, const QString &arg_surname, const QString &arg_cellPhone, const QString &arg_workPhone,
                    const QString &arg_homePhone) :
                        User(arg_name, arg_surname), cellPhone(arg_cellPhone), workPhone(arg_workPhone), homePhone(arg_homePhone) {}

void Trustee::setCellPhone(const QString &arg_cellPhone)
{
    cellPhone = arg_cellPhone;
}

QString Trustee::getCellPhone() const
{
    return cellPhone;
}

void Trustee::setWorkPhone(const QString &arg_workPhone)
{
    workPhone = arg_workPhone;
}

QString Trustee::getWorkPhone() const
{
    return workPhone;
}

void Trustee::setHomePhone(const QString &arg_homePhone)
{
    homePhone = arg_homePhone;
}

QString Trustee::getHomePhone() const
{
    return homePhone;
}

Trustee::~Trustee()
{

}
