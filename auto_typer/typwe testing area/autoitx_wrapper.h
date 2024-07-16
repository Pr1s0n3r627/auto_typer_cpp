#ifndef AUTOITX_WRAPPER_H
#define AUTOITX_WRAPPER_H

// Include necessary Windows headers
#include <windows.h>

// Declare function prototypes from autoitx.dll
extern "C" {

// Function to simulate typing text
int AU3_Send(const char *keys, int mode);

// Function to pause execution for a specified time
void AU3_Sleep(int milliseconds);

}

#endif // AUTOITX_WRAPPER_H
