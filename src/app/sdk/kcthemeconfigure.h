#ifndef KCTHEMECONFIGURE_H
#define KCTHEMECONFIGURE_H

#include <QPalette>
#include <QJsonObject>

#include <QHash>

#include "kcconfigure.h"

class KCThemeConfigure : public KCConfigure
{
    Q_OBJECT
public:
    static KCThemeConfigure *instance();
    ~KCThemeConfigure();
    QPalette getPalette(const QString &identityName);
    void loadConfigure();
    void saveConfigure();
    void setConfigureFile(const QString &filePath);

private:
    void parseObject(const QJsonObject &object, QPalette &palette);
    QColor stringToColor(const QString &colorString);
    static KCThemeConfigure *m_instance;
    explicit KCThemeConfigure(QObject *parent = 0);

    QString m_filePath;
    QHash<QString, QPalette> m_paletteMap;

    QHash<QString, QPalette::ColorRole> m_textRole;
    QHash<QPalette::ColorRole, QString> m_roleText;
};

#endif // KCTHEMECONFIGURE_H
