#ifndef KCCONFIGUREBACKEND_H
#define KCCONFIGUREBACKEND_H

#include <QObject>

class KCConfigureBackend : public QObject
{
    Q_OBJECT
public:
    ~KCConfigureBackend();

    void setValue(const QString &group,
                  const QString &key,
                  const QVariant &value);

    void setGroup(const QString &group);
    void setValue(const QString &key,
                  const QVariant &value);


signals:

public slots:

private:
    explicit KCConfigureBackend(QObject *parent = 0);
};

#endif // KCCONFIGUREBACKEND_H
