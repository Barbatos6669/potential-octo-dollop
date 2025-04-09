/********************************************************************************************/
/*  AppState.hpp                                                                            */
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

/// @brief This file defines the AppState enum class, which represents the different states of the application.
/// @details The AppState enum class is used to manage the current state of the application, allowing for easy switching between different UI states.
/// @note The enum class includes states such as MyDay, Calendar, Tasks, Settings, NewList, AddTask, and Search.
/// @note This enum class is part of a larger application that manages tasks and events.
enum class AppState 
{
    MyDay,
    Calendar,
    Tasks,
    Settings,
    NewList,
    AddTask,
    Search,
};