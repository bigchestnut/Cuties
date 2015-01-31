#ifndef KCGLOBAL_H
#define KCGLOBAL_H

#include <QAction>

#include <QObject>

namespace KCGlobalNameSpace
{
enum MenuCategories
{
    File,
    Edit,
    View,
    Search,
    Execute,
    Debug,
    Tools,
    Tabs,
    Help,
    MenuCategoriesCount
};
struct MenuActions
{
    QAction *action=nullptr;
    int category=0;
};
}

using namespace KCGlobalNameSpace;

class KCThemeConfigure;
class KCGlobal : public QObject
{
    Q_OBJECT
public:
    static KCGlobal *instace();
    ~KCGlobal();
    QPalette getPalette(const QString &identityName);

signals:

public slots:

private:
    static KCGlobal *m_instance;
    static KCThemeConfigure *m_themeInstance;
    explicit KCGlobal(QObject *parent = 0);
};

#endif // KCGLOBAL_H
