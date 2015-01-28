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
#include "sao/knsaosubmenu.h"

#include "kcmainmenu.h"

KCMainMenu::KCMainMenu(QWidget *parent) :
    KNSAOMainMenu(parent)
{
    //Initial the sub menus.
    initialSubMenus();
    //Retranslate.
    retranslate();
}

KCMainMenu::~KCMainMenu()
{
    ;
}

void KCMainMenu::addCategoryAction(const int &category, QAction *action)
{
    m_subMenus[category]->addAction(action);
}

void KCMainMenu::retranslate()
{
    m_subMenus[File]->setTitle(tr("File"));
    m_subMenus[Edit]->setTitle(tr("Edit"));
    m_subMenus[View]->setTitle(tr("View"));
    m_subMenus[Search]->setTitle(tr("Search"));
    m_subMenus[Execute]->setTitle(tr("Execute"));
    m_subMenus[Debug]->setTitle(tr("Debug"));
    m_subMenus[Tools]->setTitle(tr("Tools"));
    m_subMenus[Tabs]->setTitle(tr("Tabs"));
    m_subMenus[Help]->setTitle(tr("Help"));
}

void KCMainMenu::initialSubMenus()
{
    //Initial the menu icons.
    QIcon menuIcons[MenuCategoriesCount];
    menuIcons[File]=QIcon("://menu/file.png");
    menuIcons[Edit]=QIcon("://menu/edit.png");
    menuIcons[View]=QIcon("://menu/view.png");
    menuIcons[Search]=QIcon("://menu/search.png");
    menuIcons[Execute]=QIcon("://menu/execute.png");
    menuIcons[Debug]=QIcon("://menu/debug.png");
    menuIcons[Tools]=QIcon("://menu/tools.png");
    menuIcons[Tabs]=QIcon("://menu/tabs.png");
    menuIcons[Help]=QIcon("://menu/help.png");

    for(int i=0; i<MenuCategoriesCount; i++)
    {
        //Initial the menu.
        m_subMenus[i]=new KNSAOSubMenu(this);
        //Set properties.
        m_subMenus[i]->setIcon(menuIcons[i]);
        //Add menu to main menu.
        addMenu(m_subMenus[i]);
    }
}

