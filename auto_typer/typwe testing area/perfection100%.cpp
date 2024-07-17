#include <windows.h>

int main() {
    // Define the text to type
    const char* text = 
        "#include<iostream>\n"
        "int HeLLo(){\n"
        "std::cout<<\"HeLLo\";\n"
        "return 0;\n}";

    // Prepare the INPUT structure array
    INPUT inputs[512] = {0};  // Large enough to hold all inputs

    // Function to add a key press and release
    auto addKey = [](INPUT* inputs, int& idx, WORD vk, bool shift) {
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
    };

    int idx = 0;

    // Add inputs for each character
    for (int i = 0; text[i] != '\0'; ++i) {
        SHORT vk = VkKeyScan(text[i]);
        WORD vkCode = vk & 0xff;
        bool shift = vk & 0x100;

        if (text[i] == ' ') {
            addKey(inputs, idx, VK_SPACE, false);
        } else if (text[i] == '\n') {
            addKey(inputs, idx, VK_RETURN, false);
        } else {
            addKey(inputs, idx, vkCode, shift);
        }
    }

    Sleep(5000); 

    // Send the inputs
    SendInput(idx, inputs, sizeof(INPUT));

    return 0;
}

/*
output:
#include<iostream>
int HeLLo(){
std::cout<<"HeLLo";
return 0;
}
*/