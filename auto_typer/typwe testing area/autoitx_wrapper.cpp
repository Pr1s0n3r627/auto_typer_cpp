#include "autoitx_wrapper.h"

// Function to simulate typing text
int AU3_Send(const char *keys, int mode) {
    // Load autoitx.dll dynamically
    HINSTANCE hDll = LoadLibrary("autoitx.dll");
    if (hDll == NULL) {
        return 0; // Return 0 or handle error appropriately
    }

    // Get function pointer for AU3_Send function
    typedef int (*AU3_SendFunc)(const char*, int);
    AU3_SendFunc pAU3_Send = reinterpret_cast<AU3_SendFunc>(GetProcAddress(hDll, "AU3_Send"));
    if (pAU3_Send == NULL) {
        FreeLibrary(hDll);
        return 0; // Return 0 or handle error appropriately
    }

    // Call AU3_Send function
    int result = pAU3_Send(keys, mode);

    // Free the library handle
    FreeLibrary(hDll);

    return result;
}

// Function to pause execution for a specified time
void AU3_Sleep(int milliseconds) {
    // Load autoitx.dll dynamically
    HINSTANCE hDll = LoadLibrary("autoitx.dll");
    if (hDll == NULL) {
        return; // Handle error appropriately
    }

    // Get function pointer for AU3_Sleep function
    typedef void (*AU3_SleepFunc)(int);
    AU3_SleepFunc pAU3_Sleep = reinterpret_cast<AU3_SleepFunc>(GetProcAddress(hDll, "AU3_Sleep"));
    if (pAU3_Sleep == NULL) {
        FreeLibrary(hDll);
        return; // Handle error appropriately
    }

    // Call AU3_Sleep function
    pAU3_Sleep(milliseconds);

    // Free the library handle
    FreeLibrary(hDll);
}
