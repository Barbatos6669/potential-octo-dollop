#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "UIConfig.hpp"
#include "ProgramManager.hpp"


using namespace std;

int main() {
    cout << "Hello, SFML!" << endl;

    // Create a window
    ProgramManager programManager; // Create an instance of ProgramManager
    programManager.run(); // Run the program

    return 0;
}