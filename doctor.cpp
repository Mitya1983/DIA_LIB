#include "doctor.h"

Doctor::Doctor()
{

}

Doctor::Doctor(const QString &arg_name, const QString &arg_surname, const QString &arg_workPhone) : User(arg_name, arg_surname), workPhone(arg_workPhone) {}

Doctor::Doctor(const QString &arg_name, const QString &arg_surname, const QString &arg_workPhone, const QString &arg_cellPhone) :
                    User(arg_name, arg_surname), workPhone(arg_workPhone), cellPhone(arg_cellPhone) {}

Doctor::Doctor(const QString &arg_name, const QString &arg_surname, const QString &arg_workPhone, const QString &arg_cellPhone, const QString &arg_clinicName) :
                    User(arg_name, arg_surname), workPhone(arg_workPhone), cellPhone(arg_cellPhone), clinicName(arg_clinicName){}

Doctor::Doctor(const QString &arg_name, const QString &arg_surname, const QString &arg_workPhone, const QString &arg_cellPhone, const QString &arg_clinicName,
               const QString &arg_clinicAddress) :
                User(arg_name, arg_surname), workPhone(arg_workPhone), cellPhone(arg_cellPhone), clinicName(arg_clinicName), clinicAddress(arg_clinicAddress){}

//Doctor::Doctor(const Doctor &arg_doctor)
//{
//    this->setName(arg_doctor.getName());
//    this->setSurname(arg_doctor.getSurname());
//    this->setWorkPhone(arg_doctor.getWorkPhone());
//    this->setCellPhone(arg_doctor.getCellPhone());
//    this->setClinicName(arg_doctor.getClinicName());
//    this->setClinicAddress(arg_doctor.getClinicAddress());
//}

void Doctor::setWorkPhone(const QString &arg_workPhone)
{
    workPhone = arg_workPhone;
}

QString Doctor::getWorkPhone() const
{
    return workPhone;
}

void Doctor::setCellPhone(const QString &arg_cellPhone)
{
    cellPhone = arg_cellPhone;
}

QString Doctor::getCellPhone() const
{
    return cellPhone;
}

void Doctor::setClinicName(const QString &arg_clinicName)
{
    clinicName = arg_clinicName;
}

QString Doctor::getClinicName() const
{
    return clinicName;
}

void Doctor::setClinicAddress(const QString &arg_clinicAddress)
{
    clinicAddress = arg_clinicAddress;
}

QString Doctor::getClinicAddress() const
{
    return clinicAddress;
}

std::map<QString, QString> Doctor::getWorkingSchedule()
{
    return workingSchedule;
}

//Doctor::~Doctor()
//{
    
//}
