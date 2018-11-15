#ifndef PUMP_H
#define PUMP_H

#include <QObject>
#include <QString>

class Pump : public QObject
{
    Q_OBJECT
    QString manufacturer;
    QString model;
    int volume;
    int currentVolume;
public:
    explicit Pump(QObject *parent = nullptr);
    Pump(const QString &arg_manufacturer, const QString &arg_model, const int &arg_volume, QObject *parent = nullptr);
    Q_INVOKABLE void setManufacturer(const QString &arg_manufacturer);
    Q_INVOKABLE QString getManufacturer() const;
    Q_INVOKABLE void setModel(const QString &arg_model);
    Q_INVOKABLE QString getModel() const;
    Q_INVOKABLE void setVolume(const int &arg_volume);
    Q_INVOKABLE int getVolume() const;
    Q_INVOKABLE int getCurrentVolume() const;
    
    ~Pump() = default;
signals:
    void on_lowInsulinVolume();
public slots:
    Q_INVOKABLE void setCurrentVolume(const int &arg_injection, const int &arg_averageInsDose);
};

#endif // PUMP_H
