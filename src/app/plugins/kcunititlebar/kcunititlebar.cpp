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
#include <QToolButton>

#include "kcunititlebar.h"

KCUniTitlebar::KCUniTitlebar(QWidget *parent) :
    QWidget(parent)
{
    //Set properties.
    setContentsMargins(0,0,0,0);
    setFixedHeight(32);

    //Initial the main menu button.
    m_mainMenu=new QToolButton(this);
    m_mainMenu->setAutoRaise(true);
    m_mainMenu->setFixedSize(32, 32);
    m_mainMenu->setIcon(QIcon("://mainmenu.png"));
    m_mainMenu->setIconSize(QSize(32, 32));
    m_mainMenu->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_1));
    connect(m_mainMenu, &QToolButton::pressed,
            m_mainMenu, &QToolButton::showMenu);
}

KCUniTitlebar::~KCUniTitlebar()
{
    ;
}

void KCUniTitlebar::setMainMenu(QMenu *menu)
{
    m_mainMenu->setMenu(menu);
}

