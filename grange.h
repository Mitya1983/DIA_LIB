#ifndef GRANGE_H
#define GRANGE_H
/*Class for storing information about preferred glucose ranges*/
#include <QObject>

class GRange : public QObject
{
    Q_OBJECT
    double lowerBound;
    double upperbound;
    double lowerBorderValue;
    double upperBorderValue;
    double normalSurplus;
public:
    explicit GRange(QObject *parent = nullptr);
    GRange(const double &arg_lowerBound, const double &arg_upperBound, QObject *parent = nullptr);

    Q_INVOKABLE void setLowerBound(const double &arg_lowerBound);
    Q_INVOKABLE double getLowerBound() const;
    Q_INVOKABLE void setUpperBound(const double &arg_upperBound);
    Q_INVOKABLE double getUpperBound() const;
    Q_INVOKABLE double &getLowerBorderValue();
    Q_INVOKABLE double &getUpperBorderValue();
    Q_INVOKABLE double &getNormalSurpus();
    
    ~GRange() = default;
    
signals:
    void on_upperBoundValueChanged(double value);
    void on_lowerBoundValueChanged(double value);
private slots:
    void setLowerBorderValue(const double &arg_lowerBound);
    void setUpperBorderValue(const double &arg_upperBound);
    void setNormalSurplus(const double &arg_upperBound);
};

#endif // GRANGE_H
