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

class KCGlobal : public QObject
{
    Q_OBJECT
public:
    static KCGlobal *instace();
    ~KCGlobal();

signals:

public slots:

private:
    static KCGlobal *m_instance;
    explicit KCGlobal(QObject *parent = 0);

};

#endif // KCGLOBAL_H
