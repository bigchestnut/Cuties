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
#include <QPropertyAnimation>

#include "knsaostyle.h"

#include "knsaomainmenu.h"

KNSAOMainMenu::KNSAOMainMenu(QWidget *parent) :
    QMenu(parent)
{
    //Initial the object name.
    setObjectName("SAOMainMenu");
    //Initial the style.
    setStyle(KNSAOStyle::instance());
    //Set properties.
    setFixedWidth(160);

    //Initial animation.
    m_showAnime=new QPropertyAnimation(this, "geometry", this);
    m_showAnime->setEasingCurve(QEasingCurve::OutCubic);
}

KNSAOMainMenu::~KNSAOMainMenu()
{

}

void KNSAOMainMenu::showEvent(QShowEvent *e)
{
    //Set the animation properties.
    m_showAnime->setStartValue(QRect(geometry().x(),
                                     geometry().y(),
                                     geometry().width(),
                                     1));
    m_showAnime->setEndValue(geometry());
    //Start animation.
    m_showAnime->start();
    //Show main menu
    QMenu::showEvent(e);
}

