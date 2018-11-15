#ifndef DOCTOR_H
#define DOCTOR_H
/*Class for storing information about Patient Doctor*/
#include "user.h"
#include <QString>
#include <map>
class Doctor : public User
{
    Q_OBJECT
    QString workPhone;
    QString cellPhone;
    QString clinicName;
    QString clinicAddress;
    std::map<QString/*Days*/, QString/*Working hours from-to*/> workingSchedule;
public:
    Doctor();
    Doctor(const QString &arg_name, const QString &arg_surname, const QString &arg_workPhone);
    Doctor(const QString &arg_name, const QString &arg_surname, const QString &arg_workPhone, const QString &arg_cellPhone);
    Doctor(const QString &arg_name, const QString &arg_surname, const QString &arg_workPhone, const QString &arg_cellPhone,
            const QString &arg_clinicName);
    Doctor(const QString &arg_name, const QString &arg_surname, const QString &arg_workPhone, const QString &arg_cellPhone,
            const QString &arg_clinicName, const QString &arg_clinicAddress);
    //Doctor(const Doctor &arg_doctor);
    
    Q_INVOKABLE void setWorkPhone(const QString &arg_workPhone);
    Q_INVOKABLE QString getWorkPhone() const;
    Q_INVOKABLE void setCellPhone(const QString &arg_cellPhone);
    Q_INVOKABLE QString getCellPhone() const;
    Q_INVOKABLE void setClinicName(const QString &arg_clinicName);
    Q_INVOKABLE QString getClinicName() const;
    Q_INVOKABLE void setClinicAddress(const QString &arg_clinicAddress);
    Q_INVOKABLE QString getClinicAddress() const;
    Q_INVOKABLE std::map<QString/*Days*/, QString/*Working hours from-to*/> getWorkingSchedule();

    ~Doctor() = default;
};

#endif // DOCTOR_H
