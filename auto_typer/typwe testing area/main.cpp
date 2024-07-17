#include <windows.h>

int main() {
    INPUT inputs[25] = {0};  // Assuming 12 characters (including space and !), each with press and release events

    // Simulate Caps Lock key press
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_CAPITAL;  // Virtual-key code for Caps Lock
    inputs[0].ki.dwFlags = 0;

    // Simulate 'H' key press
    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = 'H';  // Virtual-key code for 'H'
    inputs[1].ki.dwFlags = 0;

    // Simulate 'H' key release
    inputs[2].type = INPUT_KEYBOARD;
    inputs[2].ki.wVk = 'H';
    inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

    // Simulate 'E' key press
    inputs[3].type = INPUT_KEYBOARD;
    inputs[3].ki.wVk = 'E';  // Virtual-key code for 'E'
    inputs[3].ki.dwFlags = 0;

    // Simulate 'E' key release
    inputs[4].type = INPUT_KEYBOARD;
    inputs[4].ki.wVk = 'E';
    inputs[4].ki.dwFlags = KEYEVENTF_KEYUP;

    // Simulate 'L' key press (first 'L')
    inputs[5].type = INPUT_KEYBOARD;
    inputs[5].ki.wVk = 'L';  // Virtual-key code for 'L'
    inputs[5].ki.dwFlags = 0;

    // Simulate 'L' key release (first 'L')
    inputs[6].type = INPUT_KEYBOARD;
    inputs[6].ki.wVk = 'L';
    inputs[6].ki.dwFlags = KEYEVENTF_KEYUP;

    // Simulate 'L' key press (second 'L')
    inputs[7].type = INPUT_KEYBOARD;
    inputs[7].ki.wVk = 'L';  // Virtual-key code for 'L'
    inputs[7].ki.dwFlags = 0;

    // Simulate 'L' key release (second 'L')
    inputs[8].type = INPUT_KEYBOARD;
    inputs[8].ki.wVk = 'L';
    inputs[8].ki.dwFlags = KEYEVENTF_KEYUP;

    // Simulate 'O' key press
    inputs[9].type = INPUT_KEYBOARD;
    inputs[9].ki.wVk = 'O';  // Virtual-key code for 'O'
    inputs[9].ki.dwFlags = 0;

    // Simulate 'O' key release
    inputs[10].type = INPUT_KEYBOARD;
    inputs[10].ki.wVk = 'O';
    inputs[10].ki.dwFlags = KEYEVENTF_KEYUP;

    // Simulate space key press
    inputs[11].type = INPUT_KEYBOARD;
    inputs[11].ki.wVk = VK_SPACE;  // Virtual-key code for Spacebar
    inputs[11].ki.dwFlags = 0;

    // Simulate space key release
    inputs[12].type = INPUT_KEYBOARD;
    inputs[12].ki.wVk = VK_SPACE;
    inputs[12].ki.dwFlags = KEYEVENTF_KEYUP;

    // Simulate 'W' key press
    inputs[13].type = INPUT_KEYBOARD;
    inputs[13].ki.wVk = 'W';  // Virtual-key code for 'W'
    inputs[13].ki.dwFlags = 0;

    // Simulate 'W' key release
    inputs[14].type = INPUT_KEYBOARD;
    inputs[14].ki.wVk = 'W';
    inputs[14].ki.dwFlags = KEYEVENTF_KEYUP;

    // Simulate 'O' key press
    inputs[15].type = INPUT_KEYBOARD;
    inputs[15].ki.wVk = 'O';  // Virtual-key code for 'O'
    inputs[15].ki.dwFlags = 0;

    // Simulate 'O' key release
    inputs[16].type = INPUT_KEYBOARD;
    inputs[16].ki.wVk = 'O';
    inputs[16].ki.dwFlags = KEYEVENTF_KEYUP;

    // Simulate 'R' key press
    inputs[17].type = INPUT_KEYBOARD;
    inputs[17].ki.wVk = 'R';  // Virtual-key code for 'R'
    inputs[17].ki.dwFlags = 0;

    // Simulate 'R' key release
    inputs[18].type = INPUT_KEYBOARD;
    inputs[18].ki.wVk = 'R';
    inputs[18].ki.dwFlags = KEYEVENTF_KEYUP;

    // Simulate 'L' key press (third 'L')
    inputs[19].type = INPUT_KEYBOARD;
    inputs[19].ki.wVk = 'L';  // Virtual-key code for 'L'
    inputs[19].ki.dwFlags = 0;

    // Simulate 'L' key release (third 'L')
    inputs[20].type = INPUT_KEYBOARD;
    inputs[20].ki.wVk = 'L';
    inputs[20].ki.dwFlags = KEYEVENTF_KEYUP;

    // Simulate 'D' key press
    inputs[21].type = INPUT_KEYBOARD;
    inputs[21].ki.wVk = 'D';  // Virtual-key code for 'D'
    inputs[21].ki.dwFlags = 0;

    // Simulate 'D' key release
    inputs[22].type = INPUT_KEYBOARD;
    inputs[22].ki.wVk = 'D';
    inputs[22].ki.dwFlags = KEYEVENTF_KEYUP;

    // Simulate '!' key press
    inputs[23].type = INPUT_KEYBOARD;
    inputs[23].ki.wVk = VK_SHIFT;  // Virtual-key code for Shift key
    inputs[23].ki.dwFlags = 0;

    inputs[24].type = INPUT_KEYBOARD;
    inputs[24].ki.wVk = '1';  // Virtual-key code for '1' (to produce '!')
    inputs[24].ki.dwFlags = 0;

    // Simulate '!' key release
    inputs[25].type = INPUT_KEYBOARD;
    inputs[25].ki.wVk = '1';
    inputs[25].ki.dwFlags = KEYEVENTF_KEYUP;

    // Simulate Caps Lock key release
    inputs[26].type = INPUT_KEYBOARD;
    inputs[26].ki.wVk = VK_CAPITAL;  // Virtual-key code for Caps Lock
    inputs[26].ki.dwFlags = KEYEVENTF_KEYUP;

    // Send the input
    SendInput(27, inputs, sizeof(INPUT));

    return 0;
}
HELLO WORLD!