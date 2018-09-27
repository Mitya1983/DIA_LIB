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
    explicit User(const QString &arg_name, const QString &arg_surname, QObject *parent = nullptr);

    Q_INVOKABLE virtual void setName(const QString &arg_name);
    Q_INVOKABLE virtual QString getName() const;
    Q_INVOKABLE virtual void setSurname(const QString &arg_surname);
    Q_INVOKABLE virtual QString getSurname() const;

    virtual ~User();
signals:

public slots:
};

#endif // USER_H
