/* ScummVM - Scumm Interpreter
 * Copyright (C) 2001/2002 The ScummVM project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 */

#include "sound/mixer.h"
#include "simon/intern.h"

class SimonSound {
private:
	class Sound {
	protected:
		File *_file;
		uint32 *_offsets;
		SoundMixer *_mixer;

	public:
		Sound(SoundMixer *mixer, File *file, uint32 base = 0);
		virtual int playSound(uint sound, PlayingSoundHandle *handle, byte flags = 0) = 0;
	};

	class WavSound : public Sound {
	public:
		WavSound(SoundMixer *mixer, File *file, uint32 base = 0) : Sound(mixer, file, base) {};
		int playSound(uint sound, PlayingSoundHandle *handle, byte flags = 0);
	};

	class VocSound : public Sound {
	public:
		VocSound(SoundMixer *mixer, File *file, uint32 base = 0) : Sound(mixer, file, base) {};
		int playSound(uint sound, PlayingSoundHandle *handle, byte flags = 0);
	};

	class MP3Sound : public Sound {
	public:
		MP3Sound(SoundMixer *mixer, File *file, uint32 base = 0) : Sound(mixer, file, base) {};
		int playSound(uint sound, PlayingSoundHandle *handle, byte flags = 0);
	};

	byte _game;
	int _voice_index;
	int _ambient_index;
	SoundMixer *_mixer;

	Sound *_voice;
	Sound *_effects;

	bool _effects_paused;
	bool _ambient_paused;

public:
	PlayingSoundHandle _voice_handle;
	PlayingSoundHandle _effects_handle;
	PlayingSoundHandle _ambient_handle;

	uint _ambient_playing;

	SimonSound(const byte game, const GameSpecificSettings *gss, const char *gameDataPath, SoundMixer *mixer);

	void readSfxFile(const char *filename, const char *gameDataPath);
	void loadSfxTable(File *gameFile, uint32 base);

	void playVoice(uint sound);
	void playEffects(uint sound);
	void playAmbient(uint sound);

	bool hasVoice();
	void stopVoice();
	void stopAll();
	void effectsPause(bool b);
	void ambientPause(bool b);
};

