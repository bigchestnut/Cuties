#ifndef KCTABSTYLE_H
#define KCTABSTYLE_H

#include <QCommonStyle>

class QStyleOptionTab;
class KCTabStyle : public QCommonStyle
{
    Q_OBJECT
public:
    explicit KCTabStyle();
    void drawPrimitive(PrimitiveElement pe,
                       const QStyleOption *opt,
                       QPainter *p,
                       const QWidget *w) const;


    void drawControl(ControlElement element,
                         const QStyleOption *opt,
                         QPainter *p,
                         const QWidget *w) const;
signals:

public slots:

private:
    QStyle *m_style;
    void drawTabItem(const QStyleOptionTab *opt,
                         QPainter *p,
                         const QWidget *w) const;

};

#endif // KCTABSTYLE_H
