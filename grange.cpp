#include "grange.h"
#include <stdexcept>

GRange::GRange(QObject *parent) : QObject(parent)
{
    connect(this, &GRange::on_lowerBoundValueChanged, this, &GRange::setLowerBorderValue);
    connect(this, &GRange::on_upperBoundValueChanged, this, &GRange::setUpperBorderValue);
    connect(this, &GRange::on_upperBoundValueChanged, this, &GRange::setNormalSurplus);
}

GRange::GRange(const double &arg_lowerBound, const double &arg_upperBound, QObject *parent) : 
                QObject(parent), lowerBound(arg_lowerBound), upperbound(arg_upperBound)
{
    connect(this, &GRange::on_lowerBoundValueChanged, this, &GRange::setLowerBorderValue);
    connect(this, &GRange::on_upperBoundValueChanged, this, &GRange::setUpperBorderValue);
    connect(this, &GRange::on_upperBoundValueChanged, this, &GRange::setNormalSurplus);
    emit on_lowerBoundValueChanged(lowerBound);
    emit on_upperBoundValueChanged(upperbound);
}

void GRange::setLowerBound(const double &arg_lowerBound)
{
//    if ((static_cast<int>(upperbound) != 0) && (arg_lowerBound > upperbound))
//        throw std::invalid_argument("lowerBound can't be bigger then upperBound");
//    else
//    {
        lowerBound = arg_lowerBound;
        emit on_lowerBoundValueChanged(lowerBound);
//    }   
}

double GRange::getLowerBound() const
{
    return lowerBound;
}

void GRange::setUpperBound(const double &arg_upperBound)
{
    upperbound = arg_upperBound;
    emit on_upperBoundValueChanged(upperbound);
}

double GRange::getUpperBound() const
{
    return upperbound;
}

double &GRange::getLowerBorderValue()
{
    return lowerBorderValue;
}

double &GRange::getUpperBorderValue()
{
    return upperBorderValue;
}

double &GRange::getNormalSurpus()
{
    return normalSurplus;
}

void GRange::setLowerBorderValue(const double &arg_lowerBound)
{
    lowerBorderValue = arg_lowerBound + 1.0;
}

void GRange::setUpperBorderValue(const double &arg_upperBound)
{
    upperBorderValue = arg_upperBound - 1.0;
}

void GRange::setNormalSurplus(const double &arg_upperBound)
{
    normalSurplus = arg_upperBound + 2;
}
