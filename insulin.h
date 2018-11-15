#ifndef INSULIN_H
#define INSULIN_H

#include <QObject>
#include <QString>

class Insulin : public QObject
{
public:
    enum struct InsulinTypes
    {
        Lispro = 0,
        Aspart = 0,
        Glulisine = 0,
        Regular = 1,
        Novolin = 1,
        Velosulin = 1,
//        NPH = 2,
//        Glargine = 3,
//        Detemir = 3,
//        Degludec = 3    
    };
private:
    Q_OBJECT
    InsulinTypes type;    
    QString name;
    int volume;
    int currentVolume;
public:
    
    explicit Insulin(QObject *parent = nullptr);
    Insulin(const QString &arg_name, QObject *parent = nullptr);
    Insulin(const QString &arg_name, Insulin::InsulinTypes arg_type, QObject *parent = nullptr);
    Q_INVOKABLE void setName(const QString &arg_name);
    Q_INVOKABLE QString getName() const;
    Q_INVOKABLE void setType(Insulin::InsulinTypes arg_type);
    Q_INVOKABLE InsulinTypes getType() const;
    Q_INVOKABLE void setVolume(const int &arg_volume);
    Q_INVOKABLE int getVolume() const;
    Q_INVOKABLE int getCurrentVolume() const;
    
    ~Insulin() = default;
signals:
    void on_lowInsulinVolume();
public slots:
    void setCurrentVolume(const int &arg_injection, const int &arg_averageInsDose);
};

#endif // INSULIN_H
