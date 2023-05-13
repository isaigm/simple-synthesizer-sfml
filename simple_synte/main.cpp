#include "App.h"
#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
HMIDIOUT proxy = 0;

App app;
void CALLBACK MidiInProc(
    HMIDIIN hMidiIn,
    UINT wMsg,
    DWORD_PTR dwInstance,
    DWORD_PTR dwParam1,
    DWORD_PTR dwParam2)
{
    uint8_t firstByte = dwParam1 & 0xFF;
    uint8_t note = (dwParam1 >> 8) & 0xFF;

    if (firstByte == 0x90)
    {

        app.pressKey(note);
    }
    else if (firstByte == 0x80)
    {
        app.relaseKey(note);
    }
}
int main()
{
    HMIDIIN instrument = 0;
    if (midiOutOpen(&proxy, 2, NULL, 0, NULL) == MMSYSERR_NOERROR)
    {
        std::cout << "ok\n";
    }
    if (midiInOpen(&instrument, 0, reinterpret_cast<DWORD_PTR>(MidiInProc), 0, CALLBACK_FUNCTION) == MMSYSERR_NOERROR)
    {
        std::cout << "midi device opened\n";
        midiInStart(instrument);
    }
    else
    {
        std::cout << "no midi device found\n";
    }
    app.run();
	return 0;
}