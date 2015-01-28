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
#ifndef KCMAINMENU_H
#define KCMAINMENU_H

#include "kcglobal.h"

#include "sao/knsaomainmenu.h"

class KNSAOSubMenu;
class KCMainMenu : public KNSAOMainMenu
{
    Q_OBJECT
public:
    explicit KCMainMenu(QWidget *parent = 0);
    ~KCMainMenu();
    void addCategoryAction(const int &category, QAction *action);

private slots:
    void retranslate();

private:
    void initialSubMenus();
    KNSAOSubMenu *m_subMenus[MenuCategoriesCount];
};

#endif // KCMAINMENU_H
