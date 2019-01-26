#pragma once

#include "al.h"
#include "alc.h"
#include "efx.h"
#include "efx-creative.h"
#include "EFX-Util.h"
#include "xram.h"
#include "alut.h"

#include "Audio.h"

#include "Util.h"

class OpenALAudio : public Audio {
public:
	OpenALAudio();
	virtual ~OpenALAudio() override;

	virtual bool init() override;
	virtual BaseComponentReadiness isReady() override;

	static void listAudioDevices(const ALCchar * devices);
	static ALenum toALFormat(short channels, short samples);
private:

	ALboolean enumeration;
	const ALCchar *devices;
	const ALCchar *defaultDeviceName = nullptr;//argv[1];	// TODO
	int ret;
	char *bufferData;
	ALCdevice *device;
	ALCcontext *context;

	static bool checkError(const std::string & msg);
	virtual bool initOpenAL();
	virtual bool initExtensions();
	virtual bool initDevice();
	virtual bool initContext();
};