/*
 * Copyright (C) 2020 ~ 2021 Uniontech Software Technology Co.,Ltd.
 *
 * Author:     Hou Lei <houlei@uniontech.com>
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

#ifndef RECORDPROCESS_H
#define RECORDPROCESS_H

#include "utils/desktopinfo.h"
#include "utils/configsettings.h"

#include <QProcess>
#include <QObject>
#include <QRect>

#include <proc/readproc.h>
#include <proc/sysinfo.h>

//不需要开启线程，用信号槽代替 process->waitForFinished(-1); 避免线程等待浪费系统资源
class RecordProcess  : public QObject
{
    Q_OBJECT

    typedef std::map<int, proc_t> StoredProcType;

public:
    static const int RECORD_TYPE_VIDEO;
    static const int RECORD_TYPE_GIF;
    static const int RECORD_GIF_SLEEP_TIME;
    static const int RECORD_AUDIO_INPUT_MIC;
    static const int RECORD_AUDIO_INPUT_SYSTEMAUDIO;
    static const int RECORD_AUDIO_INPUT_MIC_SYSTEMAUDIO;

    static const int RECORD_FRAMERATE_5;
    static const int RECORD_FRAMERATE_10;
    static const int RECORD_FRAMERATE_20;
    static const int RECORD_FRAMERATE_24;
    static const int RECORD_FRAMERATE_30;

    explicit RecordProcess(QObject *parent = nullptr);
    ~RecordProcess();

    void setRecordInfo(const QRect &recordRect, const QString &filename);
    //void setRecordType(int recordType);
    //void setFrameRate(int framerate);
    void setRecordAudioInputType(int inputType);
    void startRecord();
    //void setIsZhaoXinPlatform(bool status);
    void stopRecord();
    void recordVideo();
    void initProcess();
    void setRecordMouse(const bool status);
    //int readSleepProcessPid();

private slots:
    /**
     * @brief onRecordFinish:录屏完成
     */
    void onRecordFinish();

    /**
     * @brief onStartTranscode:开始转码
     */
    void onStartTranscode();

    /**
     * @brief onTranscodeFinish:转码完成
     */
    void onTranscodeFinish();

private:
    QProcess *m_recorderProcess = nullptr;

    int recordType = 0;
    int recordAudioInputType = 0;
    bool m_isRecordMouse = true;

    QRect m_recordRect;

    QString savePath;
    QString saveBaseName;
    QString saveTempDir;
    QString saveDir;
    QString defaultSaveDir;
    QString saveAreaName;
    QString displayNumber;

    ConfigSettings *settings = nullptr;

    int byzanzProcessId = 0;
    int m_framerate;

    //QString lastAudioSink;
    //bool m_isZhaoxin = false;
    DesktopInfo m_info;
    QProcess *m_pTranscodeProcess = nullptr;
};

#endif //RECORDPROCESS_H
