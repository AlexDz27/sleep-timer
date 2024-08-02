#include <windows.h>
#include <powrprof.h>
#include <iostream>
#include <cstdlib> // For std::atoi

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <minutes>" << std::endl;
        return 1;
    }

    // Convert the command line argument to an integer
    int minutes = std::atoi(argv[1]);
    if (minutes <= 0) {
        std::cerr << "Please enter a positive integer for minutes." << std::endl;
        return 1;
    }

    // 60 minutes in milliseconds
    // const DWORD sleepTime = minutes * 60 * 1000;
    const DWORD sleepTime = minutes * 1000;

    std::cout << "The computer will go to sleep in " << minutes << " minutes..." << std::endl;

    // Sleep for 60 minutes
    Sleep(sleepTime);

    // Put the computer to sleep
    if (SetSuspendState(false, false, false) == 0) {
        std::cerr << "Failed to put the computer to sleep." << std::endl;
        return 1;
    }

    std::cout << "The computer is now sleeping." << std::endl;

    return 0;
}
