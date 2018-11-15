#ifndef INSULINDOSE_H
#define INSULINDOSE_H

#include <QObject>
#include <QString>

class InsulinDose : public QObject
{
    Q_OBJECT
protected:
    double dose;
public:
    explicit InsulinDose(QObject *parent = nullptr);
    InsulinDose(const double &arg_dose, QObject *parent = nullptr);
    
    Q_INVOKABLE double getDose() const;
    Q_INVOKABLE virtual QString getData();
    
    virtual ~InsulinDose() = default;
    
signals:
    void on_doseValueChanged();
    
public slots:
    virtual void setDose(const double &arg_dose);
};

#endif // INSULINDOSE_H
