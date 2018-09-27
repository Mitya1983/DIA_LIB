#include "grange.h"

GRange::GRange(QObject *parent) : QObject(parent){}

GRange::GRange(const double &arg_lowerBound, const double &arg_upperbound, QObject *parent) : 
                QObject(parent), lowerBound(arg_lowerBound), upperbound(arg_upperbound)
{
//    setLowerBorderValue(lowerBound);
//    setUpperBorderValue(upperbound);
//    setNormalSurplus(upperbound);
    connect(this, &GRange::on_lowerBoundValueChanged, this, &GRange::setLowerBorderValue);
    connect(this, &GRange::on_upperBoundValueChanged, this, &GRange::setUpperBorderValue);
    connect(this, &GRange::on_upperBoundValueChanged, this, &GRange::setNormalSurplus);
    emit on_lowerBoundValueChanged(lowerBound);
    emit on_upperBoundValueChanged(upperbound);
}

void GRange::setLowerBound(const double &arg_lowerBound)
{
    lowerBound = arg_lowerBound;
    emit on_lowerBoundValueChanged(lowerBound);
}

double GRange::getLowerBound() const
{
    return lowerBound;
}

void GRange::setUpperBound(const double &arg_upperbound)
{
    upperbound = arg_upperbound;
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
    normalSurplus = arg_upperBound + 3;
}
