#include "..\..\include\OpenALSound.h"

OpenALSound::OpenALSound(std::string path) : path(path) {
}

OpenALSound::~OpenALSound() {
	release();
}

bool OpenALSound::init(float volume, bool loop, float pitch) {
	if (!initData(volume, loop, pitch)) return false;
	return true;
}

bool OpenALSound::play(bool forceRestart) {
	if (!isPlaying()) {
		alSourcePlay(source);
		if (checkError("source playing")) return false;
	} else if(forceRestart) {
		stop();
		play(false);
	}
	return true;
}

bool OpenALSound::pause() {
	if (isPlaying()) {
		alSourcePause(source);
		if (checkError("source playing")) return false;
	}
	return true;
}

bool OpenALSound::stop() {
	if (!isStopped()) {
		alSourceStop(source);
		if (checkError("source playing")) return false;
	}
	return true;
}

bool OpenALSound::isPlaying() {
	ALenum state;
	alGetSourcei(source, AL_SOURCE_STATE, &state);
	if (checkError("source state get")) return false;
	return (state == AL_PLAYING);
}

bool OpenALSound::isPaused() {
	ALenum state;
	alGetSourcei(source, AL_SOURCE_STATE, &state);
	if (checkError("source state get")) return false;
	return (state == AL_PAUSED);
}

bool OpenALSound::isStopped() {
	ALenum state;
	alGetSourcei(source, AL_SOURCE_STATE, &state);
	if (checkError("source state get")) return false;
	return (state == AL_STOPPED);
}

float OpenALSound::getVolume() {
	ALfloat value;
	alGetSourcef(source, AL_GAIN, &value);
	if (checkError("getVolume")) return false;
	return value;
}

bool OpenALSound::setVolume(float volume) {
	alSourcef(source, AL_GAIN, volume);
	if (checkError("setVolume")) return false;
	return true;
}

bool OpenALSound::getLooping() {
	ALint value;
	alGetSourcei(source, AL_LOOPING, &value);
	if (checkError("getVolume")) return false;
	return value;
}

bool OpenALSound::setLooping(bool loop) {
	alSourcei(source, AL_LOOPING, loop ? AL_TRUE : AL_FALSE);
	if (checkError("setLooping")) return false;
	return true;
}

float OpenALSound::getPitch() {
	ALfloat value;
	alGetSourcef(source, AL_PITCH, &value);
	if (checkError("getVolume")) return false;
	return value;
}

bool OpenALSound::setPitch(float pitch) {
	alSourcef(source, AL_PITCH, pitch);
	if (checkError("setPitch")) return false;
	return true;
}

bool OpenALSound::release() {
	stop();
	alDeleteSources(1, &source);
	alDeleteBuffers(1, &buffer);
	return true;
}

bool OpenALSound::checkError(const std::string & msg) {
	ALCenum error = alGetError();
	if (error != AL_NO_ERROR) {
		std::cout << "checkError: " << msg << std::endl;
		return true;
	}
	return false;
}

bool OpenALSound::initData(float volume, bool loop, float pitch) {
	ALenum format;
	ALvoid *data;
	ALsizei size;
	ALfloat freq;
	ALboolean looping = loop ? AL_TRUE : AL_FALSE;

	alGenSources((ALuint)1, &source);
	if (checkError("source generation")) return false;

	alSourcef(source, AL_PITCH, pitch);
	if (checkError("source pitch")) return false;
	alSourcef(source, AL_GAIN, volume);
	if (checkError("source gain")) return false;
	alSource3f(source, AL_POSITION, 0, 0, 0);
	if (checkError("source position")) return false;
	alSource3f(source, AL_VELOCITY, 0, 0, 0);
	if (checkError("source velocity")) return false;
	alSourcei(source, AL_LOOPING, looping);
	if (checkError("source looping")) return false;

	alGenBuffers(1, &buffer);
	if (checkError("buffer generation")) return false;

	data = alutLoadMemoryFromFile(path.c_str(), &format, &size, &freq);
	if (checkError("loading wav file")) return false;

	alBufferData(buffer, format, data, size, (ALsizei)freq);
	if (checkError("buffer copy")) return false;

	alSourcei(source, AL_BUFFER, buffer);
	if (checkError("buffer binding")) return false;

	return true;
}
