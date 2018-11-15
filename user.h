#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>

class User : public QObject
{
    Q_OBJECT
    QString name;
    QString surname;
public:
    explicit User(QObject *parent = nullptr);
    User(const QString &arg_name, const QString &arg_surname, QObject *parent = nullptr);

    enum struct Gender
    {
        Male = 0,
        Female = 1
    };
    Q_INVOKABLE virtual void setName(const QString &arg_name);
    Q_INVOKABLE virtual QString getName() const;
    Q_INVOKABLE virtual void setSurname(const QString &arg_surname);
    Q_INVOKABLE virtual QString getSurname() const;
    virtual ~User() = default;
signals:

public slots:
};

#endif // USER_H
