#include <windows.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
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
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}
int main() {
    std::string text;
    int delay;

    std::cout << "Enter the text you want to type: ";
    std::getline(std::cin, text);

    std::cout << "Enter delay between keystrokes (in milliseconds): ";
    std::cin >> delay;

    std::this_thread::sleep_for(std::chrono::seconds(5)); // Give the user 5 seconds to focus the target window

    typeString(text, delay);

    return 0;
}
