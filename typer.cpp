#include <windows.h>
#include <iostream>
#include <string>

void simulateKeystroke(char key) {
    // Create a keydown input event
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;
    input.ki.wVk = VkKeyScan(key); // Virtual-key code
    input.ki.dwFlags = 0; // 0 for key press

    // Send the keydown event
    SendInput(1, &input, sizeof(INPUT));

    // Create a keyup input event
    input.ki.dwFlags = KEYEVENTF_KEYUP; // Key up flag

    // Send the keyup event
    SendInput(1, &input, sizeof(INPUT));
}

void typeString(const std::string &text, int delay) {
    for (char c : text) {
        simulateKeystroke(c);
        Sleep(delay);
    }
}

int main() {
    std::string text = "QWERTYUIOPASDFGHJKLZXCVBNM\n!@#$%^&*()_+1234567890-=[]{};':,.<>/?";
    int delay = 10;

    Sleep(5000); // Give the user 5 seconds to focus the target window

    typeString(text, delay);

    return 0;
}
