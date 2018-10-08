#include "patient.h"


Patient::Patient() 
{
    range = std::unique_ptr<GRange>(new GRange ());
    bolus = std::unique_ptr<Insulin>(new Insulin());
    averageDose = std::unique_ptr<InsulinDose>(new InsulinDose());
    connect(this, &Patient::on_birthDateChanged, this, &Patient::setAge);
    connect(this, &Patient::on_weightValueChanged, this, &Patient::setMassIndex);
    connect(averageDose.get(), &InsulinDose::on_doseValueChanged, this, &Patient::setCorrectionFactor);
    connect(averageDose.get(), &InsulinDose::on_doseValueChanged, this, &Patient::setCHORatio);
    connect(this, &Patient::on_cHORationValueChanged, this, &Patient::setBreadUnitRatio);
}

Patient::Patient(const QString &arg_name, const QString &arg_surname) : User(arg_name, arg_surname) 
{
    range = std::unique_ptr<GRange>(new GRange ());
    bolus = std::unique_ptr<Insulin>(new Insulin());
    averageDose = std::unique_ptr<InsulinDose>(new InsulinDose());
    connect(this, &Patient::on_birthDateChanged, this, &Patient::setAge);
    connect(this, &Patient::on_weightValueChanged, this, &Patient::setMassIndex);
    connect(averageDose.get(), &InsulinDose::on_doseValueChanged, this, &Patient::setCorrectionFactor);
    connect(averageDose.get(), &InsulinDose::on_doseValueChanged, this, &Patient::setCHORatio);
    connect(this, &Patient::on_cHORationValueChanged, this, &Patient::setBreadUnitRatio);
}

void Patient::setGender(User::Gender arg_gender)
{
    gender = arg_gender;
}

QString Patient::getGender() const
{
    QString data;
    if (gender == User::Gender::Male)
        data = tr("Male");
    if (gender == User::Gender::Female)
        data = tr("Female");
    return data;
}

void Patient::setBirthDate(const QString &arg_date)
{
    birthdate = QDate::fromString(arg_date, "dd.MM.yyyy");
    emit on_birthDateChanged();
}

QString Patient::getBirthDate() const
{
    QString data = birthdate.toString("dd.MM.yyyy");
    return data;
}

QString Patient::getAge() const
{
    QString data = QString::number(age);
    return data;
}

void Patient::setDiaExp(const int &arg_experience)
{
    diaExp = arg_experience;
}

QString Patient::getDiaExp() const
{
    QString data = QString::number(diaExp);
    return data;
}

void Patient::setHeight(const int &arg_height)
{
    height = arg_height;
}

QString Patient::getHeight() const
{
    QString data = QString::number(height);
    return data;
}

void Patient::setWeight(const int &arg_weight)
{
    weight = arg_weight;
    if (height > 0)
        emit on_weightValueChanged();
}

QString Patient::getWeight() const
{
    QString data = QString::number(weight);
    return data;
}

QString Patient::getMassIndex() const
{
    QString data = QString::number(massIndex);
    return data;
}

void Patient::setRange(const double &arg_lowerBound, const double &arg_upperBound)
{
    
    range->setLowerBound(arg_lowerBound); 
    range->setUpperBound(arg_upperBound);
}

GRange *Patient::getRange()
{
    return  range.get();
}

void Patient::setBreadUnit(const int &arg_BreadUnitValue)
{
    breadUnit = arg_BreadUnitValue;
}

int Patient::getBreadUnit() const
{
    return breadUnit;
}

void Patient::setBasalInsulin(const QString &arg_name)
{
    basal = std::unique_ptr<Insulin>(new Insulin (arg_name));
}

Insulin *Patient::getBasalInsulin()
{
    return basal.get();
}

void Patient::setBolusInsulin(const QString &arg_name, Insulin::InsulinTypes arg_type)
{
    bolus->setName(arg_name);
    bolus->setType(arg_type);
}

Insulin *Patient::getBolusInsulin()
{
    return bolus.get();
}

void Patient::setPump(const QString &arg_manufacturer, const QString &arg_model, const int &arg_volume)
{
//    pump.setManufacturer(arg_manufacturer);
//    pump.setModel(arg_model);
//    pump.setVolume(arg_volume);
    pump = std::unique_ptr<Pump>(new Pump(arg_manufacturer, arg_model, arg_volume));
}

Pump *Patient::getPump()
{
    return pump.get();
}

void Patient::setDoctor(const Doctor &arg_doctor)
{
    doctor.reset(new Doctor (arg_doctor));
}

Doctor *Patient::getDoctor()
{
    return doctor.get();
}

double Patient::getAverageDose() const
{
    return averageDose.get()->getDose();
}

double Patient::getCorrectionFactor() const
{
    return correctionFactor;
}

double Patient::getCHORatio() const
{
    return cHORatio;
}

double Patient::getBreadUnitRatio() const
{
    return breadUnitRatio;
}

Patient::~Patient()
{
    
}

void Patient::setAge()
{
    if (QDate::currentDate().month() < birthdate.month() && QDate::currentDate().day() < birthdate.day())
        age = QDate::currentDate().year() - (birthdate.year() + 1);
    else /*(QDate::currentDate().day() >= birthdate.day())*/
        age = QDate::currentDate().year() - birthdate.year();
}

void Patient::setMassIndex()
{
    double t_height = static_cast<double>(height) / 100.00;
    double t_index = weight / (t_height * t_height);
    massIndex = static_cast<int>(t_index * 10) / 10.00;
}

void Patient::setAverageDose(const double &arg_dose)
{
    averageDose.get()->setDose(arg_dose);
}

void Patient::setCorrectionFactor()
{
    switch  (static_cast<int>(bolus->getType()))
    {
    case 0:
        correctionFactor = static_cast<int>(100.00 / averageDose->getDose() * 10) / 10.00;
        break;
    case 1:
        correctionFactor = static_cast<int>(83.00 / averageDose->getDose() * 10) / 10.00;
        break;
    }
}

void Patient::setCHORatio()
{
    cHORatio = static_cast<int>(500.00 / averageDose->getDose() * 10) / 10.00;
    emit on_cHORationValueChanged();
}

void Patient::setBreadUnitRatio()
{
    breadUnitRatio = static_cast<int>((breadUnit / cHORatio) * 10) / 10.00;
}
