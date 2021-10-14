/*
 * Copyright (C) 2020 ~ 2021 Uniontech Software Technology Co.,Ltd.
 *
 * Author:     He MingYang <hemingyang@uniontech.com>
 *
 * Maintainer: Liu Zheng <liuzheng@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SHAPESUTILS_H
#define SHAPESUTILS_H

#include <QtCore>
#include <QColor>

typedef QList<QPointF> FourPoints;
//Q_DECLARE_METATYPE(FourPoints)

/* shape*/
class Toolshape
{
public:
    QString type;
    FourPoints mainPoints;
    int index = -1;
    int lineWidth = 1;
    int colorIndex = 0;
    bool isBlur = false;
    bool isMosaic = false;
    bool isStraight = false;
    bool isShiftPressed = false;
    int fontSize = 1;

    QList<QPointF> points;
    QList<QList<qreal>> portion;
    QPointF arrowRotatePos;
    Toolshape();
    //~Toolshape();

    //friend QDebug &operator<<(QDebug &argument, const Toolshape &obj);
    //friend QDataStream &operator>>(QDataStream &in, Toolshape &obj);
    //Toolshape operator=(Toolshape obj);
    //bool operator==(const Toolshape &other) const;
    //static void registerMetaType();
};

//typedef QList<QPointF> FourPoints;
typedef QList <Toolshape> Toolshapes;
//Q_DECLARE_METATYPE(Toolshape)
//Q_DECLARE_METATYPE(Toolshapes)

#endif // SHAPESUTILS_H
