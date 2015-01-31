#include <QPainter>
#include <QStyleFactory>
#include <QStyleOptionTab>
#include "kctabstyle.h"

KCTabStyle::KCTabStyle() :
    QCommonStyle()
{
    m_style=QStyleFactory::create("fusion");
}

void KCTabStyle::drawPrimitive(QStyle::PrimitiveElement pe,
                               const QStyleOption *opt,
                               QPainter *p,
                               const QWidget *w) const
{
    switch (pe)
    {
    case PE_IndicatorTabClose:
    {
        QIcon tabCloseIcon;
        tabCloseIcon.addPixmap(QPixmap("://tab/TabCloseNormal.png"),
                               QIcon::Normal,QIcon::Off);
        tabCloseIcon.addPixmap(QPixmap("://tab/TabCloseDown.png"),
                               QIcon::Normal,
                               QIcon::On);
        tabCloseIcon.addPixmap(QPixmap("://tab/TabCloseHover.png"),
                               QIcon::Active,
                               QIcon::Off);
        QIcon::Mode mode = opt->state & State_Enabled ?
                    (opt->state & State_Raised ? QIcon::Active : QIcon::Normal)
                  : QIcon::Disabled;
        if(!(opt->state & State_Raised)
                && !(opt->state & State_Sunken)
                && !(opt->state & QStyle::State_Selected))
        {
            mode = QIcon::Disabled;
        }
        QPixmap tabClosePixmap=tabCloseIcon.pixmap(proxy()->pixelMetric(QStyle::PM_SmallIconSize),
                                                   mode,
                                                   opt->state & State_Sunken ? QIcon::On : QIcon::Off);
        proxy()->drawItemPixmap(p,opt->rect,Qt::AlignCenter,tabClosePixmap);
        break;
    }
    default:
        m_style->drawPrimitive(pe,opt,p,w);
        break;
    }
}

void KCTabStyle::drawControl(QStyle::ControlElement element,
                             const QStyleOption *opt,
                             QPainter *p,
                             const QWidget *w) const
{
    p->setRenderHints(QPainter::Antialiasing |
                      QPainter::TextAntialiasing |
                      QPainter::SmoothPixmapTransform,
                      true);
    switch (element)
    {
    case CE_TabBarTab:
    {
        const QStyleOptionTab *tabOption=
                qstyleoption_cast<const QStyleOptionTab *>(opt);
        if(tabOption!=nullptr)
        {
            drawTabItem(tabOption,p,w);
        }
        break;
    }
    default:
        m_style->drawControl(element,opt,p,w);
        break;
    }
}

void KCTabStyle::drawTabItem(const QStyleOptionTab *opt, QPainter *p, const QWidget *w) const
{
    if(opt->state & QStyle::State_Selected)
    {
        QStyleOptionTab blankTextOptionTab=*opt;
        blankTextOptionTab.text=QString(opt->text.length(),QChar(' '));
        m_style->drawControl(CE_TabBarTab,&blankTextOptionTab,p,w);
        int alignment = Qt::AlignCenter | Qt::TextShowMnemonic;
        if(!proxy()->styleHint(SH_UnderlineShortcut, opt, w))
        {
            alignment |= Qt::TextHideMnemonic;
        }
        m_style->drawItemText(p,
                              subElementRect(SE_TabBarTabText, opt, w),
                              alignment,
                              opt->palette,
                              true,
                              opt->text,
                              QPalette::HighlightedText);
        return;
    }
    m_style->drawControl(CE_TabBarTab,opt,p,w);
}
