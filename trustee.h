#ifndef TRUSTEE_H
#define TRUSTEE_H
/*Class for storing information about possible Patient Trustee (Parent, Husband, Wife etc)*/
#include <QString>
#include "user.h"

class Trustee : public User
{
    Q_OBJECT
    QString cellPhone;
    QString workPhone;
    QString homePhone;
public:
    Trustee();
    Trustee(const QString &arg_name, const QString &arg_surname, const QString &arg_cellPhone);
    Trustee(const QString &arg_name, const QString &arg_surname, const QString &arg_cellPhone, const QString &arg_workPhone);
    Trustee(const QString &arg_name, const QString &arg_surname, const QString &arg_cellPhone, const QString &arg_workPhone,
            const QString &arg_homePhone);

    Q_INVOKABLE void setCellPhone(const QString &arg_cellPhone);
    Q_INVOKABLE QString getCellPhone() const;
    Q_INVOKABLE void setWorkPhone(const QString &arg_workPhone);
    Q_INVOKABLE QString getWorkPhone() const;
    Q_INVOKABLE void setHomePhone(const QString &arg_homePhone);
    Q_INVOKABLE QString getHomePhone() const;

};

#endif // TRUSTEE_H
