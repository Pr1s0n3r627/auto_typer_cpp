#include <iostream>
#include "autoitx_wrapper.h"

int main() {
    std::cout << "Starting auto_typer.exe" << std::endl;

    // Test typing a simple string
    const char* text = "Hello, World!\n";
    int result = AU3_Send(text, 1);

    if (result == 1) {
        std::cout << "Text sent successfully." << std::endl;
    } else {
        std::cout << "Failed to send text. Error code: " << result << std::endl;
    }

    std::cout << "Finished auto_typer.exe" << std::endl;

    return 0;
}
