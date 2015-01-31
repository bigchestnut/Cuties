#ifndef KCCONFIGURE_H
#define KCCONFIGURE_H

#include <QObject>

class KCConfigure : public QObject
{
    Q_OBJECT
public:
    explicit KCConfigure(QObject *parent = 0);
    virtual void loadConfigure()=0;
    virtual void saveConfigure()=0;
    virtual void setConfigureFile(const QString &filePath)=0;

signals:

public slots:

protected:

private:
    ;
};

#endif // KCCONFIGURE_H
