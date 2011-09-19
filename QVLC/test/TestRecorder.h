/****************************************************************************
* VLC-Qt - Qt and libvlc connector library
* Copyright (C) 2010 Tadej Novak <tadej@tano.si>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#ifndef VLCQT_TEST_RECORDER_H_
#define VLCQT_TEST_RECORDER_H_

#include <QtGui/QDialog>

#include "core/Instance.h"
#include "core/Media.h"
#include "core/MediaPlayer.h"

namespace Ui {
    class TestRecorder;
}

class TestRecorder : public QDialog
{
Q_OBJECT
public:
	TestRecorder(QWidget *parent = 0);
	~TestRecorder();

private:
	Ui::TestRecorder *ui;

	VlcInstance *_instance;
	VlcMedia *_media;
	VlcMediaPlayer *_player;
};

#endif // VLCQT_TEST_RECORDER_H_
