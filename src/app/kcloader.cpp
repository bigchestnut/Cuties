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
#include <QApplication>
#include <QSplashScreen>
#include <QStyleFactory>
#include <QTimer>

#include "plugins/kcmainmenu/kcmainmenu.h"
#include "plugins/kcunititlebar/kcunititlebar.h"
#include "kctabmanager.h"

#include "kcmainwindow.h"
#include "knversion.h"

#include "kcloader.h"

KCLoader *KCLoader::m_instance=nullptr;

KCLoader *KCLoader::instance()
{
    return m_instance==nullptr?m_instance=new KCLoader:m_instance;
}

KCLoader::~KCLoader()
{
    //Remove splash screen.
    delete m_splashScreen;
}

void KCLoader::showSplash()
{
    //Show the splash screen.
    m_splashScreen->show();
}

void KCLoader::hideSplash()
{
    //Using the timer to hide splash.
    m_splashTimer->start();
}

KCLoader::KCLoader(QObject *parent) :
    QObject(parent)
{
    initalApplicationInformation();
    initialSplashScreen();
}

void KCLoader::initalApplicationInformation()
{
    //Set application details.
    QApplication::setApplicationName("Cuties");
    QApplication::setApplicationVersion(APP_VERSION_STR);
    QApplication::setApplicationDisplayName("Cuties");
    QApplication::setOrganizationName("Kreogist Dev Team");
    QApplication::setOrganizationDomain("https://kreogist.github.io/Cuties");

    //Set window icon
    QApplication::setWindowIcon(QIcon("://icon.png"));

    //Set application effects
    QApplication::setEffectEnabled(Qt::UI_AnimateCombo, true);
    QApplication::setEffectEnabled(Qt::UI_FadeMenu, true);
    QApplication::setEffectEnabled(Qt::UI_AnimateToolBox, true);
    QApplication::setEffectEnabled(Qt::UI_AnimateTooltip, true);
    QApplication::setEffectEnabled(Qt::UI_FadeTooltip, true);

    //Set global styles.
    QApplication::setStyle(QStyleFactory::create("fusion"));
}

void KCLoader::addMainMenuAction(const QList<MenuActions> &actionList)
{
    //Add the action to main menu.
    for(QList<MenuActions>::const_iterator menuActionItem=actionList.begin();
        menuActionItem!=actionList.end();
        ++menuActionItem)
    {
        m_mainMenu->addCategoryAction((*menuActionItem).category,
                                      (*menuActionItem).action);
    }
}

void KCLoader::initialSplashScreen()
{
    //Initial the screen and timer.
    m_splashScreen=new QSplashScreen(QPixmap("://splash.png"));
    m_splashScreen->setContentsMargins(0,0,0,0);
    m_splashScreen->setWindowFlags(m_splashScreen->windowFlags() |
                                   Qt::WindowStaysOnTopHint);

    m_splashTimer=new QTimer(this);
    m_splashTimer->setSingleShot(true);
    m_splashTimer->setInterval(1000);
    connect(m_splashTimer, &QTimer::timeout,
            m_splashScreen, &QSplashScreen::close);
}

void KCLoader::initialTitlebar()
{
    //Initial the titlebar.
    m_titlebar=new KCUniTitlebar(m_mainWindow);
    //Set the titlebar.
    m_mainWindow->setMenuWidget(m_titlebar);
}

void KCLoader::initialTabManager()
{
    //Initial the tab manager.
    m_tabManager=new KCTabManager(m_mainWindow);
    //Set tab manager to central widget.
    m_mainWindow->setCentralWidget(m_tabManager);
    //Get the actions list from tab manager.
    QList<MenuActions> actionList;
    m_tabManager->generateMenuActionList(actionList);
    //Process the action list.
    addMainMenuAction(actionList);
}

void KCLoader::initialMainMenu()
{
    //Initial the main menu.
    m_mainMenu=new KCMainMenu(m_mainWindow);
    //Set the main menu.
    m_titlebar->setMainMenu(m_mainMenu);
}

KCMainWindow *KCLoader::mainWindow() const
{
    return m_mainWindow;
}

void KCLoader::setMainWindow(KCMainWindow *mainWindow)
{
    //Save the main window.
    m_mainWindow=mainWindow;
    //Set properties.
    m_mainWindow->setWindowTitle(QApplication::applicationDisplayName());
}

void KCLoader::loadModules()
{
    initialTitlebar();
    initialMainMenu();
    initialTabManager();
}

void KCLoader::startApplication()
{
    //Show the main window.
    m_mainWindow->show();
    //Hide splash.
    hideSplash();
}
