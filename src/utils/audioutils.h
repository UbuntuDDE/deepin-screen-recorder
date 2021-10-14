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

#ifndef AUDIOUTILS_H
#define AUDIOUTILS_H
#include <QObject>
#include <QProcess>
class AudioUtils: public QObject
{
    Q_OBJECT
public:
    explicit AudioUtils(QObject *parent = nullptr);
    //bool isSystemAudioOutput();
    //bool isMicrophoneOutput();
    //void setupMicrophoneOutput();
    //void setupSystemAudioOutput();
    //void setupAudioSink(QString sink);
    //bool canVirtualCardOutput();
    //static bool canMicrophoneInput();
    //QString currentAudioSink();
    //QString currentAudioSource();
    QString currentAudioChannel();
private:
    //void initProcess();

private:
    //QProcess *process;

};

#endif // AUDIOUTILS_H
