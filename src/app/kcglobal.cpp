#include "kcthemeconfigure.h"

#include "kcglobal.h"

KCGlobal *KCGlobal::m_instance=nullptr;
KCThemeConfigure *KCGlobal::m_themeInstance=nullptr;

KCGlobal *KCGlobal::instace()
{
    return m_instance==nullptr?m_instance=new KCGlobal:m_instance;
}

KCGlobal::~KCGlobal()
{
    ;
}

QPalette KCGlobal::getPalette(const QString &identityName)
{
    ;
}

KCGlobal::KCGlobal(QObject *parent) :
    QObject(parent)
{
    //Set the theme instrance.
    m_themeInstance=KCThemeConfigure::instance();
}

