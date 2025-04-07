/********************************************************************************************/
/*  main.cpp                                                                                */
/********************************************************************************************/
/*                               This file is part of:                                      */
/*                                     To Do List                                           */       
/*                                                                                          */
/********************************************************************************************/
/*                                                                                          */
/*  This program is free software: you can redistribute it and/or modify                    */
/*  it under the terms of the GNU General Public License as published by                    */
/*  the Free Software Foundation, either version 3 of the License, or                       */
/*  (at your option) any later version.                                                     */
/*                                                                                          */
/*                                                                                          */
/*  This program is distributed in the hope that it will be useful,                         */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of                          */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                           */
/*  GNU General Public License for more details.                                            */
/*                                                                                          */
/*  You should have received a copy of the GNU General Public License                       */
/*  along with this program.  If not, see <http://www.gnu.org/licenses/>.                   */
/*                                                                                          */
/********************************************************************************************/

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