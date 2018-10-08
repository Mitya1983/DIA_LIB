#ifndef EXPORTTOFILE_H
#define EXPORTTOFILE_H

#include <QObject>

class ExportToFile : public QObject
{
    Q_OBJECT
public:
    explicit ExportToFile(QObject *parent = nullptr);
    
signals:
    
public slots:
};

#endif // EXPORTTOFILE_H