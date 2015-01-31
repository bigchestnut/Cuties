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
#include <QAction>
#include <QTabBar>

#include "kccodeeditor.h"
#include "kctabstyle.h"

#include "kctabmanager.h"

KCTabStyle *KCTabManager::m_tabStyle=nullptr;

KCTabManager::KCTabManager(QWidget *parent) :
    QTabWidget(parent)
{
    if(m_tabStyle==nullptr)
    {
        m_tabStyle=new KCTabStyle;
    }
    setStyle(m_tabStyle);
    //Set properties.
    setAcceptDrops(true);
    setContentsMargins(0,0,0,0);
    setDocumentMode(true);
    setElideMode(Qt::ElideRight);
    setObjectName("KCTabManager");
    setTabPosition(QTabWidget::South);
    setTabsClosable(true);

    //Customize tab bar.
    m_tabBar=tabBar();
    //Set properties.
    m_tabBar->setMinimumHeight(0);
    m_tabBar->setContentsMargins(0,0,0,0);
    m_tabBar->setContextMenuPolicy(Qt::CustomContextMenu);

    //Initial actions.
    initialActions();
    //Retranslate.
    retranslate();
}

KCTabManager::~KCTabManager()
{
    ;
}

void KCTabManager::generateMenuActionList(QList<MenuActions> &list)
{
    for(int i=0; i<EditUndo; i++)
    {
        MenuActions fileAction;
        fileAction.action=m_tabManagerAction[i];
        fileAction.category=File;
        list.append(fileAction);
    }
    for(int i=EditUndo; i<TabManagerActionsCount; i++)
    {
        MenuActions editAction;
        editAction.action=m_tabManagerAction[i];
        editAction.category=Edit;
        list.append(editAction);
    }
}

int KCTabManager::newFile(const QString &suffix)
{
    //Generate a code editor.
    KCCodeEditor *editor=new KCCodeEditor(this);
    if(editor==NULL)
    {
        //!FIXME: show message box "Out of memeory."
        return -1;
    }
    //Set untitled index.
    editor->setUntitled(++m_newFileCount);
    //Add the tab.
    return addCodeEditor(editor);
}

void KCTabManager::retranslate()
{
    //Retranslate the untitled caption.
    m_untitledText=tr("Untitled ");
    //Retranslate every tab.
    for(int i=0; i<count(); i++)
    {
        //Check the editor's status.
        KCCodeEditor *editor=static_cast<KCCodeEditor *>(widget(i));
        if(editor->untitled())
        {
            //Rename the tab.
            setTabText(i, m_untitledText+QString::number(editor->untitled()));
        }
    }
    //Retranslate the actions.
    m_tabManagerAction[FileNew]->setText(tr("New Source File"));
    m_tabManagerAction[FileOpen]->setText(tr("Open"));
    m_tabManagerAction[FileSave]->setText(tr("Save"));
    m_tabManagerAction[FileSaveAs]->setText(tr("Save As"));
    m_tabManagerAction[FileSaveAll]->setText(tr("Save All"));
    m_tabManagerAction[FileClose]->setText(tr("Close"));
    m_tabManagerAction[FileCloseAll]->setText(tr("Close All"));
    m_tabManagerAction[FileCloseAllOthers]->setText(tr("Close All Other File"));
    m_tabManagerAction[FileExit]->setText(tr("Exit"));
    m_tabManagerAction[EditUndo]->setText(tr("Undo"));
    m_tabManagerAction[EditRedo]->setText(tr("Redo"));
    m_tabManagerAction[EditCut]->setText(tr("Cut"));
    m_tabManagerAction[EditCopy]->setText(tr("Copy"));
    m_tabManagerAction[EditPaste]->setText(tr("Paste"));
    m_tabManagerAction[EditSelectAll]->setText(tr("Select All"));
}

void KCTabManager::initialActions()
{
    QString actionPaths[TabManagerActionsCount];
    actionPaths[FileNew]="://actions/FileNew.png";
    actionPaths[FileOpen]="://actions/FileOpen.png";
    actionPaths[FileSave]="://actions/FileSave.png";
    actionPaths[FileSaveAs]="://actions/FileSaveAs.png";
    actionPaths[FileSaveAll]="://actions/FileSaveAll.png";
    actionPaths[FileClose]="://actions/FileClose.png";
    actionPaths[FileExit]="://actions/FileExit.png";
    actionPaths[EditUndo]="://actions/EditUndo.png";
    actionPaths[EditRedo]="://actions/EditRedo.png";
    actionPaths[EditCut]="://actions/EditCut.png";
    actionPaths[EditCopy]="://actions/EditCopy.png";
    actionPaths[EditPaste]="://actions/EditPaste.png";
    actionPaths[EditSelectAll]="://actions/EditSelectAll.png";

    QIcon actionIcon;
    for(int i=0; i<TabManagerActionsCount; i++)
    {
        //Load the icon.
        if(!actionPaths[i].isEmpty())
        {
            actionIcon=QIcon(actionPaths[i]);
        }
        //Initial the action.
        m_tabManagerAction[i]=new QAction(actionIcon, "", this);
    }

    //Link the actions.
    connect(m_tabManagerAction[FileNew], SIGNAL(triggered()),
            this, SLOT(newFile()));
}

int KCTabManager::addCodeEditor(KCCodeEditor *editor)
{
    int tabIndex=addTab(editor,
                        editor->untitled()?
                            m_untitledText+QString::number(editor->untitled()):
                            editor->fileName());
    setCurrentIndex(tabIndex);
    return tabIndex;
}
