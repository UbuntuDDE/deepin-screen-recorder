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

#ifndef SHOTTOOLWIDGET_H
#define SHOTTOOLWIDGET_H

#include "toolbutton.h"

#include <DLabel>
#include <DStackedWidget>

#include <QObject>
#include <QVBoxLayout>

DWIDGET_USE_NAMESPACE

class ShotToolWidget : public DStackedWidget
{
    Q_OBJECT
public:
    explicit ShotToolWidget(DWidget *parent = nullptr);
    ~ShotToolWidget();

    void initWidget();
    //截屏矩形按钮二级控件初始化
    void initRectLabel();
    //截屏圆形按钮二级控件初始化
    void initCircLabel();
    //截屏直线按钮二级控件初始化
    void initLineLabel();
    //截屏画笔按钮二级控件初始化
    void initPenLabel();
    //截屏文本按钮二级控件初始化
    void initTextLabel();

signals:
    void changeArrowAndLine(int line); //0 for line, 1 for arrow

public slots:
    void switchContent(QString shapeType);
    void colorChecked(QString colorType);

private:
    DLabel *m_rectSubTool;
    DLabel *m_circSubTool;
    DLabel *m_lineSubTool;
    DLabel *m_penSubTool;
    DLabel *m_textSubTool;

    bool m_rectInitFlag;
    bool m_circInitFlag;
    bool m_lineInitFlag;
    bool m_penInitFlag;
    bool m_textInitFlag;

    ToolButton *m_blurRectButton;
    ToolButton *m_mosaicRectButton;
    ToolButton *m_blurCircButton;
    ToolButton *m_mosaicCircButton;

    QString m_currentType;
    bool m_arrowFlag;
    int m_themeType;
    QButtonGroup *m_buttonGroup;
    QButtonGroup *m_thicknessBtnGroup;
    QButtonGroup *m_funcBtnGroup;
    QVBoxLayout *m_rectLayout;
};

#endif // SHOTTOOLWIDGET_H
