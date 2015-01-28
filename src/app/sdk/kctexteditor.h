#ifndef KCTEXTEDITOR_H
#define KCTEXTEDITOR_H

#include <QPlainTextEdit>

class KCTextEditorPanelBar;
class KCTextEditor : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit KCTextEditor(QWidget *parent = 0);
    ~KCTextEditor();

signals:

public slots:

private slots:
    void updateHighlights();

private:
    void highlightCurrentLine(QList<QTextEdit::ExtraSelection> &selections);
    void highlightParentheses(QList<QTextEdit::ExtraSelection> &selections);

    KCTextEditorPanelBar *m_panelBar;

    QColor m_lineColor;
    QColor m_parenthesesColor;
};

#endif // KCTEXTEDITOR_H
