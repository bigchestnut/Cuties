#ifndef KCTEXTEDITORLINENUMBERPANEL_H
#define KCTEXTEDITORLINENUMBERPANEL_H

#include "kctexteditorpanel.h"

class KCTextEditorLineNumberPanel : public KCTextEditorPanel
{
    Q_OBJECT
public:
    explicit KCTextEditorLineNumberPanel(QWidget *parent = 0);
    ~KCTextEditorLineNumberPanel();

signals:

public slots:
};

#endif // KCTEXTEDITORLINENUMBERPANEL_H
