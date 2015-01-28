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
#ifndef KCLOADER_H
#define KCLOADER_H

#include "kcglobal.h"

#include <QObject>

class QSplashScreen;
class QTimer;
class KCMainMenu;
class KCTabManager;
class KCMainWindow;
class KCUniTitlebar;
class KCLoader : public QObject
{
    Q_OBJECT
public:
    static KCLoader *instance();
    ~KCLoader();

    //Splash control.
    void showSplash();
    void hideSplash();

    //Main window control.
    KCMainWindow *mainWindow() const;
    void setMainWindow(KCMainWindow *mainWindow);

    //Application control.
    void loadModules();
    void startApplication();

signals:

public slots:

private:
    static KCLoader *m_instance;
    explicit KCLoader(QObject *parent = 0);
    inline void initalApplicationInformation();

    void addMainMenuAction(const QList<MenuActions> &actionList);

    //Splash screen.
    inline void initialSplashScreen();
    QSplashScreen *m_splashScreen;
    QTimer *m_splashTimer;

    //Title bar.
    void initialTitlebar();
    KCUniTitlebar *m_titlebar;

    //Tab manager.
    void initialTabManager();
    KCTabManager *m_tabManager;

    //Main menu.
    void initialMainMenu();
    KCMainMenu *m_mainMenu;

    //Main window.
    KCMainWindow *m_mainWindow;
};

#endif // KCLOADER_H
