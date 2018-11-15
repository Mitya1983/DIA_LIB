#ifndef PATIENT_H
#define PATIENT_H

#include <QDate>
#include <QString>
#include <QtDebug>
#include <memory>
#include "user.h"
#include "grange.h"
#include "insulin.h"
#include "pump.h"
#include "doctor.h"
#include "insulindose.h"
class Patient : public User
{
  
private:
    
    Q_OBJECT
    Gender gender;
    QDate birthdate;
    int age;
    int diaExp;
    int height;
    int weight;
    double massIndex;
    std::unique_ptr<GRange> range;
    int breadUnit;
    bool isPump;
    std::unique_ptr<Insulin> basal;
    std::unique_ptr<Insulin> bolus;
    std::unique_ptr<Pump> pump;
    std::unique_ptr<Doctor> doctor;
    std::unique_ptr<InsulinDose> averageDose;
    double correctionFactor;
    double cHORatio;
    double breadUnitRatio;
    double averageGlucoseLevel;
private slots:
    void setAge();
    void setMassIndex();
    void setCorrectionFactor();
    void setCHORatio();
    void setBreadUnitRatio();
public:
    Patient();
    Patient(const QString &arg_name, const QString &arg_surname);
    Q_INVOKABLE void setGender(User::Gender arg_gender);
    Q_INVOKABLE QString getGender() const;
    Q_INVOKABLE void setBirthDate(const QString &arg_date);
    Q_INVOKABLE QString getBirthDate() const;
    Q_INVOKABLE QString getAge() const;
    Q_INVOKABLE void setDiaExp(const int &arg_experience);
    Q_INVOKABLE QString getDiaExp() const;
    Q_INVOKABLE void setHeight(const int &arg_height);
    Q_INVOKABLE QString getHeight() const;
    Q_INVOKABLE void setWeight(const int &arg_weight);
    Q_INVOKABLE QString getWeight() const;
    Q_INVOKABLE QString getMassIndex() const;
    Q_INVOKABLE void setRange(const double &arg_lowerBound, const double &arg_upperBound);
    Q_INVOKABLE std::unique_ptr<GRange>& getRange();
    //Q_INVOKABLE GRange* getRange();
    Q_INVOKABLE void setBreadUnit(const int &arg_BreadUnitValue);
    Q_INVOKABLE int getBreadUnit() const;
    Q_INVOKABLE void setIsPump(bool arg);
    Q_INVOKABLE bool checkPump() const;
    Q_INVOKABLE void setBasalInsulin(const QString &arg_name);
    std::unique_ptr<Insulin>& getBasalInsulin();
    //Q_INVOKABLE Insulin *getBasalInsulin();
    Q_INVOKABLE void setBolusInsulin(const QString &arg_name, Insulin::InsulinTypes arg_type);
    Q_INVOKABLE std::unique_ptr<Insulin>& getBolusInsulin();
    //Q_INVOKABLE Insulin *getBolusInsulin();
    Q_INVOKABLE void setPump(const QString &arg_manufacturer, const QString &arg_model, const int &arg_volume);
    Q_INVOKABLE std::unique_ptr<Pump>& getPump();
    //Q_INVOKABLE Pump *getPump();
    Q_INVOKABLE void setDoctor(const QString &arg_name, const QString &arg_surname, const QString &arg_workPhone = nullptr, const QString &arg_cellPhone = nullptr,
                               const QString &arg_clinicName = nullptr, const QString &arg_clinicAddress = nullptr);
    Q_INVOKABLE std::unique_ptr<Doctor>& getDoctor();
    //Q_INVOKABLE Doctor *getDoctor();
    Q_INVOKABLE double getAverageDose() const;
    Q_INVOKABLE double getCorrectionFactor() const;
    Q_INVOKABLE double getCHORatio() const;
    Q_INVOKABLE double getBreadUnitRatio() const;
    Q_INVOKABLE QString getAverageGlucoseLevel() const;
    
signals:
    void on_birthDateChanged();
    void on_weightValueChanged();
    void on_cHORationValueChanged();
public slots:
    void setAverageDose(const double &arg_dose);
    void setAverageGlucoseLevel(const double &arg_level);
};

#endif // PATIENT_H
