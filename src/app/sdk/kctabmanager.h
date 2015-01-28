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
#ifndef KCTABMANAGER_H
#define KCTABMANAGER_H

#include "kcglobal.h"

#include <QTabWidget>

namespace KCTabManagerNamespace
{
enum TabManagerActions
{
    FileNew,
    FileOpen,
    FileSave,
    FileSaveAs,
    FileSaveAll,
    FileClose,
    FileCloseAll,
    FileCloseAllOthers,
    FileExit,
    EditUndo,
    EditRedo,
    EditCut,
    EditCopy,
    EditPaste,
    EditSelectAll,
    TabManagerActionsCount
};
}

using namespace KCTabManagerNamespace;

class KCCodeEditor;
class KCTabManager : public QTabWidget
{
    Q_OBJECT
public:
    explicit KCTabManager(QWidget *parent = 0);
    ~KCTabManager();
    void generateMenuActionList(QList<MenuActions> &list);

signals:

public slots:
    int newFile(const QString &suffix="");

private slots:
    void retranslate();

private:
    void initialActions();
    int addCodeEditor(KCCodeEditor *editor);
    QTabBar *m_tabBar;
    int m_newFileCount=0;
    QString m_untitledText;
    QAction *m_tabManagerAction[TabManagerActionsCount];
};

#endif // KCTABMANAGER_H
