#pragma once

#include "al.h"
#include "alc.h"
#include "efx.h"
#include "efx-creative.h"
#include "EFX-Util.h"
#include "xram.h"
#include "alut.h"

#include "Util.h"

class OpenALSound {
public:
	OpenALSound(std::string path);
	~OpenALSound();

	bool init(float volume = 1.0f, bool loop = false, float pitch = 1.0f);
	bool play(bool forceRestart = true);
	bool pause();
	bool stop();
	bool isPlaying();
	bool isPaused();
	bool isStopped();
	float getVolume();
	bool setVolume(float volume);
	bool getLooping();
	bool setLooping(bool loop);
	float getPitch();
	bool setPitch(float pitch);
	bool release();
protected:
	std::string path;
private:
	ALuint buffer, source;

	bool checkError(const std::string & msg);
	bool initData(float volume = 1.0f, bool loop = false, float pitch = 1.0f);
};