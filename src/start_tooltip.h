/* -*- Mode: C++; indent-tabs-mode: nil; tab-width: 4 -*-
 * -*- coding: utf-8 -*-
 *
 * Copyright (C) 2011 ~ 2018 Deepin, Inc.
 *               2011 ~ 2018 Wang Yong
 *
 * Author:     Wang Yong <wangyong@deepin.com>
 * Maintainer: Wang Yong <wangyong@deepin.com>
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

#ifndef STARTTOOLTIP_H
#define STARTTOOLTIP_H

#include <DWidget>
#include <dwindowmanager.h>

DWM_USE_NAMESPACE
DWIDGET_USE_NAMESPACE

class StartTooltip : public DWidget
{
    Q_OBJECT

public:
    explicit StartTooltip(DWidget *parent = 0);
    void setWindowManager(DWindowManager *wm);

protected:
    void paintEvent(QPaintEvent *event);
    bool eventFilter(QObject *, QEvent *event);

private:
    QString text;

    QPixmap iconImg;
    DWindowManager *windowManager;
};

#endif
