#include "kctexteditorpanelbar.h"

#include "kctexteditor.h"

KCTextEditor::KCTextEditor(QWidget *parent) :
    QPlainTextEdit(parent)
{
    //Set properties.
    setObjectName("KCTextEditor");
    setAcceptDrops(false);
    setContentsMargins(0,0,0,0);
    setFrameShape(QFrame::NoFrame);
    setLineWidth(0);

    //Initial the panels.
    m_panelBar=new KCTextEditorPanelBar(this);

    //Highlight features.
    connect(this, &KCTextEditor::cursorPositionChanged,
            this, &KCTextEditor::updateHighlights);

    //Do the default highlight.
    updateHighlights();
}

KCTextEditor::~KCTextEditor()
{

}

void KCTextEditor::updateHighlights()
{
    //Using highlight selections to highlight the things we want.
    QList<QTextEdit::ExtraSelection> extraSelections;

    highlightCurrentLine(extraSelections);
//    highlightSearchResult(extraSelections);
//    highlightParentheses(extraSelections);

    setExtraSelections(extraSelections);
}

void KCTextEditor::highlightCurrentLine(
        QList<QTextEdit::ExtraSelection> &selections)
{
    //Check if the file is open as read only mode.
    if(!isReadOnly())
    {
        QTextEdit::ExtraSelection selection;
        selection.format.setBackground(m_lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor=textCursor();
        selection.cursor.clearSelection();
        selections.append(selection);
    }
}

void KCTextEditor::highlightParentheses(
        QList<QTextEdit::ExtraSelection> &selections)
{
    ;
}
