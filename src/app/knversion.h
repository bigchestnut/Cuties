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
#ifndef KNVERSION
#define KNVERSION

//Change the version here.
#define MAJOR_VERSION 0
#define MINOR_VERSION 0
#define PATCH_VERSION 1

//----DON'T TOUCH BELOW---
//Generate string for version.
//MAGIC, DON'T TOUCH
// Stringify \a x.
#define _TOSTR(x)   #x
// Stringify \a x, perform macro expansion.
#define TOSTR(x)  _TOSTR(x)

/* the following are compile time version */
/* C++11 requires a space between literal and identifier */
#define APP_VERSION_STR \
    TOSTR(MAJOR_VERSION) "." TOSTR(MINOR_VERSION) "." TOSTR(PATCH_VERSION)
//----DON'T TOUCH ABOVE---

#endif // KNVERSION
