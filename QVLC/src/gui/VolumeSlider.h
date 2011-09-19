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

#ifndef VLCQT_VOLUMESLIDER_H_
#define VLCQT_VOLUMESLIDER_H_

#include <QtCore/QTimer>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

/*!
	\class VlcVolumeSlider VolumeSlider.h vlc-qt/VolumeSlider.h
	\brief Volume slider widget

	This is one of VLC-Qt GUI classes.
	It provides graphical volume control and also visual display of current volume.
*/
class VlcVolumeSlider : public QWidget
{
Q_OBJECT
public:
	/*!
		\brief VlcVolumeSlider constructor
		\param parent volume slider's parent GUI widget (QWidget)
	*/
	VlcVolumeSlider(QWidget *parent = 0);

	/*!
		VlcVolumeSlider destructor
	*/
	~VlcVolumeSlider();


public slots:
	/*!
		\brief Toggle mute
	*/
	void mute();

	/*!
		\brief Set volume for current media
		\param volume number from 0 to 200 (int)
	*/
	void setVolume(const int &volume);

	/*!
		\brief Get volume for current media
		\return volume number from 0 to 200 (int)
	*/
	int volume() const;

	/*!
		\brief Decreases or increases volume for 1, depending on the parameter.

		Limits from 0 to 200 apply to this function.
		\param up if true increases the volume (bool)
	*/
	void volumeControl(const bool &up);

	/*!
		Decreases volume for 1. This function is provided for convenience.
		\sa volumeControl()
	*/
	void volumeDown() { volumeControl(false); }

	/*!
		Increases volume for 1. This function is provided for convenience.
		\sa volumeControl()
	*/
	void volumeUp() { volumeControl(true); }


private slots:
	void updateVolume();

private:
	int _currentVolume;

	QSlider *_slider;
	QLabel *_label;
	QTimer *_timer;
};

#endif // VLCQT_VOLUMESLIDER_H_
