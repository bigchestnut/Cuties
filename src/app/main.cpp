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

#include "kcmainwindow.h"

#include "kcloader.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //Initial the KCLoader.
    KCLoader *loader=KCLoader::instance();
    //Show splash.
    loader->showSplash();
    //Initial the main window.
    KCMainWindow mainWindow;
    loader->setMainWindow(&mainWindow);
    //Load modules.
    loader->loadModules();
    //Hide the splash window after show the main window.
    loader->startApplication();
    //Launch application.
    int exitValue=app.exec();
    //Remove the loader after launching application.
    delete loader;
    return exitValue;
}
