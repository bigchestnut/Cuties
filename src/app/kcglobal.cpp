#include "kcglobal.h"

KCGlobal *KCGlobal::m_instance=nullptr;

KCGlobal *KCGlobal::instace()
{
    return m_instance==nullptr?m_instance=new KCGlobal:m_instance;
}

KCGlobal::~KCGlobal()
{
    ;
}

KCGlobal::KCGlobal(QObject *parent) :
    QObject(parent)
{

}

