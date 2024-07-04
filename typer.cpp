#include <iostream>
#include <windows.h>

void typeText(const std::string& text, int delay_ms = 100) {
    INPUT input;
    input.type = INPUT_KEYBOARD;
    input.ki.wScan = 0;
    input.ki.time = 0;
    input.ki.dwExtraInfo = 0;

    for (char c : text) {
        if (isupper(c)) {
            // Press and release the shift key
            input.ki.wVk = VK_SHIFT;
            input.ki.dwFlags = 0; // keydown
            SendInput(1, &input, sizeof(INPUT));

            input.ki.dwFlags = KEYEVENTF_KEYUP; // keyup
            SendInput(1, &input, sizeof(INPUT));

            // Send the uppercase character
            input.ki.wVk = VkKeyScanA(c) & 0xFF;
        } else {
            input.ki.wVk = VkKeyScanA(c) & 0xFF;
        }

        input.ki.dwFlags = 0; // keydown
        SendInput(1, &input, sizeof(INPUT));

        input.ki.dwFlags = KEYEVENTF_KEYUP; // keyup
        SendInput(1, &input, sizeof(INPUT));

        Sleep(delay_ms); // delay between keystrokes
    }
}

int main() {
    std::string textToType = "int main() {\n\tstd::cout << \"Hello, world!\" << std::endl;\n\treturn 0;\n}";
    typeText(textToType, 1); // type with 100 ms delay between keystrokes
    return 0;
}
