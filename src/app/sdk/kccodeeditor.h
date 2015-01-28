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
#ifndef KCCODEEDITOR_H
#define KCCODEEDITOR_H

#include <QWidget>

class KCTextEditor;
class KCCodeEditor : public QWidget
{
    Q_OBJECT
public:
    explicit KCCodeEditor(QWidget *parent = 0);
    ~KCCodeEditor();
    int untitled() const;
    void setUntitled(int untitled);
    QString fileName() const;

signals:

public slots:

private:
    KCTextEditor *m_textEditor;
    int m_untitled=0;
};

#endif // KCCODEEDITOR_H
