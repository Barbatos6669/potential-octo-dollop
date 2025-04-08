/********************************************************************************************/
/*  ProgramManager.hpp                                                                      */
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
#pragma Once 
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "iostream"
#include "AppState.hpp"
#include "UIConfig.hpp"
#include "PersistentUI.hpp"
#include "MyDay.hpp"
#include "TasksState.hpp"
#include "AddTask.hpp"
#include "Settings.hpp"
#include "Calender.hpp"
#include "TaskList.hpp"
#include "TaskItem.hpp"


class ProgramManager
{
    public:
        // Constructor and Destructor
        ProgramManager();
        ~ProgramManager();

        void run(); // Main loop of the program

    private:
        sf::RenderWindow window; // SFML window
        sf::Event event; // SFML event
        sf::Clock clock; // SFML clock

        PersistentUI persistentUI; // Persistent UI object
        AppState currentState; // Current application state

        MyDay myDay; // My Day object
        TasksState tasksState; // Tasks object
        AddTask addTask; // Add Task object   
        Settings settings; // Settings object 
        Calender calender; // Calendar object

        TaskList taskList; // Task List object
        
        
        void processEvents(); // Process events
        void update(); // Update the program state
        void render(); // Render the program
};