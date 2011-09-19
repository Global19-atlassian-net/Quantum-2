/****************************************************************************
* VLC-Qt - Qt and libvlc connector library
* Copyright (C) 2011 Tadej Novak <tadej@tano.si>
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

#include <QtGui/QHBoxLayout>

#include "core/Audio.h"
#include "core/Error.h"
#include "core/MediaPlayer.h"
#include "gui/VolumeSlider.h"

VlcVolumeSlider::VlcVolumeSlider(QWidget *parent)
	: QWidget(parent)
{
	_slider = new QSlider(this);
	_slider->setOrientation(Qt::Horizontal);
	_slider->setMaximum(200);

	_label = new QLabel(this);
	_label->setMinimumWidth(20);
	_label->setText(QString().number(0));

	QHBoxLayout *layout = new QHBoxLayout;
	layout->addWidget(_slider);
	layout->addWidget(_label);
	setLayout(layout);

	_timer = new QTimer(this);

	connect(_timer, SIGNAL(timeout()), this, SLOT(updateVolume()));
	connect(_slider, SIGNAL(valueChanged(int)), this, SLOT(setVolume(int)));

	_timer->start(100);
}

VlcVolumeSlider::~VlcVolumeSlider()
{
	delete _slider;
	delete _label;
	delete _timer;
}

void VlcVolumeSlider::mute()
{
	bool mute = VlcAudio::getMute();

	if(mute) {
		_timer->start(100);
		_slider->setDisabled(false);
		_label->setDisabled(false);
	} else {
		_timer->stop();
		_slider->setDisabled(true);
		_label->setDisabled(true);
	}

	VlcAudio::toggleMute();
}

void VlcVolumeSlider::setVolume(const int &volume)
{
	_currentVolume = volume;
	_slider->setValue(_currentVolume);
	_label->setText(QString().number(_currentVolume));
}

void VlcVolumeSlider::updateVolume()
{
	VlcAudio::setVolume(_currentVolume);
}

int VlcVolumeSlider::volume() const
{
	return _currentVolume;
}

void VlcVolumeSlider::volumeControl(const bool &up)
{
	if(up) {
		if(_currentVolume != 200) {
			setVolume(_currentVolume+1);
		}
	} else {
		if(_currentVolume != 0) {
			setVolume(_currentVolume-1);
		}
	}
}
