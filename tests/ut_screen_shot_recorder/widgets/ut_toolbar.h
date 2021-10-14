#pragma once
#include <gtest/gtest.h>
#include <QTest>
#include <QDebug>
#include "stub.h"
#include "addr_pri.h"
#include <DApplicationHelper>

#include "../../src/main_window.h"
#include "../../src/widgets/toolbar.h"

using namespace testing;
ACCESS_PRIVATE_FUN(ToolBar, void(QPaintEvent *), paintEvent);
ACCESS_PRIVATE_FUN(ToolBar, void(QEvent *), enterEvent);
ACCESS_PRIVATE_FUN(ToolBar, bool(QObject *,QEvent *), eventFilter);

class ToolBarTest:public testing::Test{

public:
    Stub stub;
    ToolBar *m_toolBar;
    MainWindow *m_mainWindow;
    virtual void SetUp() override{
        m_mainWindow = new MainWindow;
        m_toolBar = new ToolBar(m_mainWindow);
        m_toolBar->initToolBar();
    }

    virtual void TearDown() override{
        if(nullptr != m_toolBar)
            delete m_toolBar;
        if(nullptr != m_mainWindow)
            delete m_mainWindow;
    }
};

TEST_F(ToolBarTest, paintEvent)
{
    QPaintEvent *paintEvent = new QPaintEvent(QRect());
    call_private_fun::ToolBarpaintEvent(*m_toolBar,paintEvent);
}

TEST_F(ToolBarTest, enterEvent)
{
    QEvent *e = new QEvent(QEvent::Enter);
    call_private_fun::ToolBarenterEvent(*m_toolBar,e);
}

TEST_F(ToolBarTest, eventFilter)
{
    QObject *obj = new QObject();
    QEvent *e = new QEvent(QEvent::Enter);
    call_private_fun::ToolBareventFilter(*m_toolBar,obj,e);

    QEvent *paletteEvent = new QEvent(QEvent::PaletteChange);
    call_private_fun::ToolBareventFilter(*m_toolBar,obj,paletteEvent);
    if(nullptr != obj)
        obj->deleteLater();
}

TEST_F(ToolBarTest, setExpand)
{
    m_toolBar->setExpand(true,QString("rect"));
}

TEST_F(ToolBarTest, showAt)
{
    m_toolBar->showAt(QPoint(380,268));
}

TEST_F(ToolBarTest, currentFunctionMode)
{
    m_toolBar->currentFunctionMode(QString("rect"));
}

TEST_F(ToolBarTest, keyBoardCheckedToMainSlot)
{
    m_toolBar->keyBoardCheckedToMainSlot(true);
}

TEST_F(ToolBarTest, microphoneActionCheckedToMainSlot)
{
    m_toolBar->microphoneActionCheckedToMainSlot(true);
}

TEST_F(ToolBarTest, systemAudioActionCheckedToMainSlot)
{
    m_toolBar->systemAudioActionCheckedToMainSlot(true);
}

TEST_F(ToolBarTest, changeArrowAndLineFromMain)
{
    m_toolBar->changeArrowAndLineFromMain(5);
}

TEST_F(ToolBarTest, setRecordButtonDisable)
{
    m_toolBar->setRecordButtonDisable();
}

TEST_F(ToolBarTest, setRecordLaunchMode)
{
    m_toolBar->setRecordLaunchMode(true);
}

TEST_F(ToolBarTest, setVideoButtonInit)
{
    m_toolBar->setVideoButtonInit();
}

TEST_F(ToolBarTest, shapeClickedFromMain)
{
    m_toolBar->shapeClickedFromMain(QString("rect"));
}

TEST_F(ToolBarTest, setMicroPhoneEnable)
{
    m_toolBar->setMicroPhoneEnable(true);
}

TEST_F(ToolBarTest, setSystemAudioEnable)
{
    m_toolBar->setSystemAudioEnable(true);
}

TEST_F(ToolBarTest, setCameraDeviceEnable)
{
    m_toolBar->setCameraDeviceEnable(true);
}
