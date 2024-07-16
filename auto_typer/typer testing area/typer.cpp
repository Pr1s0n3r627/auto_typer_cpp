#include <windows.h>
#include <iostream>
#include <string>

// Define function pointer type for AutoItX functions
typedef int (*AU3_SendFunc)(const char*, int);
typedef void (*AU3_SleepFunc)(int);

int main() {
    // Load autoitx.dll dynamically
    HINSTANCE hDll = LoadLibrary("autoitx.dll");
    if (hDll == NULL) {
        std::cerr << "Failed to load autoitx.dll" << std::endl;
        return 1;
    }

    // Get function pointers for AutoItX functions
    AU3_SendFunc AU3_Send = reinterpret_cast<AU3_SendFunc>(GetProcAddress(hDll, "AU3_Send"));
    AU3_SleepFunc AU3_Sleep = reinterpret_cast<AU3_SleepFunc>(GetProcAddress(hDll, "AU3_Sleep"));
    if (AU3_Send == NULL || AU3_Sleep == NULL) {
        std::cerr << "Failed to get function pointers from autoitx.dll" << std::endl;
        FreeLibrary(hDll);
        return 1;
    }

    // Text to type
    const char* text = "QWERTYUIOPASDFGHJKLZXCVBNM\n!@#$%^&*()_+1234567890-=[]{};':,.<>/?";

    // Delay between keystrokes
    int delay = 50;

    // Give the user 5 seconds to focus the target window
    std::cout << "You have 5 seconds to focus the target window..." << std::endl;
    Sleep(5000);

    // Simulate typing using AutoItX functions
    for (const char* c = text; *c; ++c) {
        AU3_Send(c, 1);
        AU3_Sleep(delay);
    }

    // Free the library handle
    FreeLibrary(hDll);

    return 0;
}
