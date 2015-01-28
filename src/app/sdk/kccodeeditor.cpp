/*
 *  Copyright 2013-2015 Kreogist Dev Team
 *
 *  This file is part of Kreogist Cuties.
 *
 *  Kreogist Cuties is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Kreogist Cuties is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Kreogist Cuties.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <QBoxLayout>

#include "kctexteditor.h"

#include "kccodeeditor.h"

KCCodeEditor::KCCodeEditor(QWidget *parent) :
    QWidget(parent)
{
    //Set properties.
    setObjectName("KCCodeEditor");
    setContentsMargins(0,0,0,0);

    //Initial the layout.
    QBoxLayout *editorLayout=new QBoxLayout(QBoxLayout::TopToBottom, this);
    editorLayout->setContentsMargins(0,0,0,0);
    editorLayout->setSpacing(0);
    setLayout(editorLayout);
    //Initial the text editor.
    m_textEditor=new KCTextEditor(this);
    editorLayout->addWidget(m_textEditor);
}

KCCodeEditor::~KCCodeEditor()
{

}

int KCCodeEditor::untitled() const
{
    return m_untitled;
}

void KCCodeEditor::setUntitled(int untitled)
{
    m_untitled = untitled;
}

QString KCCodeEditor::fileName() const
{
    return QString();
}
