#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

// Function to add a key press and release
void addKey(INPUT* inputs, int& idx, WORD vk, bool shift) {
    if (shift) {
        inputs[idx].type = INPUT_KEYBOARD;
        inputs[idx].ki.wVk = VK_SHIFT;
        inputs[idx].ki.dwFlags = 0;
        ++idx;
    }

    inputs[idx].type = INPUT_KEYBOARD;
    inputs[idx].ki.wVk = vk;
    inputs[idx].ki.dwFlags = 0;
    ++idx;

    inputs[idx].type = INPUT_KEYBOARD;
    inputs[idx].ki.wVk = vk;
    inputs[idx].ki.dwFlags = KEYEVENTF_KEYUP;
    ++idx;

    if (shift) {
        inputs[idx].type = INPUT_KEYBOARD;
        inputs[idx].ki.wVk = VK_SHIFT;
        inputs[idx].ki.dwFlags = KEYEVENTF_KEYUP;
        ++idx;
    }
}

int main() {
    // Open the text file
    std::ifstream file("text.txt");
    if (!file) {
        std::cerr << "Failed to open text.txt\n";
        return 1;
    }

    // Read the entire content of the file into a string
    std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    // Prepare the INPUT structure array
    INPUT inputs[512] = { 0 };  // Adjust the size as needed

    int idx = 0;

    // Add inputs for each character in the text
    for (char c : text) {
        SHORT vk = VkKeyScan(c);
        WORD vkCode = vk & 0xff;
        bool shift = vk & 0x100;

        if (c == ' ') {
            addKey(inputs, idx, VK_SPACE, false);
        }
        else if (c == '\n') {
            addKey(inputs, idx, VK_RETURN, false);
        }
        else {
            addKey(inputs, idx, vkCode, shift);
        }
    }

    Sleep(5000);
    // Send the inputs
    SendInput(idx, inputs, sizeof(INPUT));

    // Close the file
    file.close();

    return 0;
}

/*
*/