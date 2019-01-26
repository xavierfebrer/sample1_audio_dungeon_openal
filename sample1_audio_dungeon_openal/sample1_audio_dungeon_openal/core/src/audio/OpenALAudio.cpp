#include "..\..\include\OpenALAudio.h"
#include "efx.h"
#include "efx-creative.h"
#include "EFX-Util.h"
#include "xram.h"
#include "alut.h"

OpenALAudio::OpenALAudio() {
}

OpenALAudio::~OpenALAudio() {
	device = alcGetContextsDevice(context);
	alcMakeContextCurrent(NULL);
	alcDestroyContext(context);
	alcCloseDevice(device);
}

bool OpenALAudio::init() {
	if (!initialized) {
		if (initOpenAL()) {
			return false;
		}
		initialized = true;
	}
	return true;
}

bool OpenALAudio::checkError(const std::string & msg) {
	ALCenum error = alGetError();
	if (error != AL_NO_ERROR) {
		std::cout << "checkError: " << msg << std::endl;
		return true;
	}
	return false;
}

void OpenALAudio::listAudioDevices(const ALCchar *devices) {
	const ALCchar *device = devices, *next = devices + 1;
	size_t len = 0;

	fprintf(stdout, "Devices list:\n");
	fprintf(stdout, "----------\n");
	while (device && *device != '\0' && next && *next != '\0') {
		fprintf(stdout, "%s\n", device);
		len = strlen(device);
		device += (len + 1);
		next += (len + 2);
	}
	fprintf(stdout, "----------\n");
}

ALenum OpenALAudio::toALFormat(short channels, short samples) {
	bool stereo = (channels > 1);
	if (samples == 16) {
		if (stereo) {
			return AL_FORMAT_STEREO16;
		} else {
			return AL_FORMAT_MONO16;
		}
	} else if (samples == 8) {
		if (stereo) {
			return AL_FORMAT_STEREO8;
		} else {
			return AL_FORMAT_MONO8;
		}
	}
	return -1;
}

bool OpenALAudio::initExtensions() {
	enumeration = alcIsExtensionPresent(NULL, "ALC_ENUMERATION_EXT");
	if (enumeration == AL_FALSE) {
		std::cout << "enumeration extension not available" << std::endl;
		return false;
	}
	return true;
}
bool OpenALAudio::initDevice() {
	listAudioDevices(alcGetString(NULL, ALC_DEVICE_SPECIFIER));
	if (!defaultDeviceName) {
		defaultDeviceName = alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER);
	}
	device = alcOpenDevice(defaultDeviceName);
	if (!device) {
		std::cout << "unable to open default device" << std::endl;
		return false;
	}
	std::cout << "Device: " << alcGetString(device, ALC_DEVICE_SPECIFIER) << std::endl;
	return true;
}

bool OpenALAudio::initContext() {
	context = alcCreateContext(device, NULL);
	if (!alcMakeContextCurrent(context)) {
		std::cout << "failed to make default context" << std::endl;
		return false;
	}
	if (checkError("make default context")) return false;
	return true;
}

bool OpenALAudio::initOpenAL() {
	if (!initExtensions()) return false;
	if (!initDevice()) return false;
	if (!initContext()) return false;

	ALfloat listenerOri[] = { 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f };
	// set orientation
	alListener3f(AL_POSITION, 0, 0, 1.0f);
	if (checkError("listener position")) return false;
	alListener3f(AL_VELOCITY, 0, 0, 0);
	if (checkError("listener velocity")) return false;
	alListenerfv(AL_ORIENTATION, listenerOri);
	if (checkError("listener orientation")) return false;

	alutInitWithoutContext(NULL, NULL);

	return true;
}

BaseComponentReadiness OpenALAudio::isReady() {
	return isInitialized() ? BaseComponentReadiness::READY : BaseComponentReadiness::NOT_READY;
}
