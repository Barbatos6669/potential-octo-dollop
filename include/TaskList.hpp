#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "TaskItem.hpp"



class TaskList
{
    public:
        /// @brief Constructor for the TaskList class.
        /// @details This constructor initializes the TaskList with a specified width, height, and position.
        /// @param width Width of the task list.
        /// @param height Height of the task list.
        /// @param x X position of the task list.
        /// @param y Y position of the task list.
        /// @note The constructor sets the size and position of the task list, as well as the font and text for the title.
        TaskList(int width, int height, int x, int y); // Constructor with default values

        /// @brief Destructor for the TaskList class.
        /// @details Cleans up resources used by the TaskList class.
        /// @note The destructor is responsible for releasing any resources allocated during the lifetime of the TaskList.
        /// @note The destructor is virtual to ensure proper cleanup of derived classes.
        ~TaskList(); // Destructor

        /// @brief Render the TaskList state.
        /// @details This method draws the task list and its items on the provided render window.
        /// @param window 
        void render(sf::RenderWindow& window); // Render function to draw task items

        /// @brief Update the TaskList state.
        /// @details This method updates the state of the task list and its items.
        /// @note The update method may include logic for refreshing the task list's content or handling animations.
        void update(); // Update function to handle task item updates

        /// @brief Process events related to the TaskList state.
        /// @details This method handles user input events such as mouse clicks or keyboard presses.
        /// @param event 
        void processEvents(const sf::Event& event); // Process events related to task items

        /// @brief Add a new task item to the task list.
        /// @param taskString The string representing the task to be added.
        /// @details This method creates a new TaskItem and adds it to the task list.
        /// @note The task item is initialized with the specified task string and default position.        
        void loadFromFile(const std::string& filename); // Load task items from a file

        /// @brief Save the current task items to a file.
        /// @param filename The name of the file to save the task items to.
        /// @details This method writes the current task items to a file in a specific format.
        /// @note The task items are saved in a way that can be loaded back into the application later.
        void saveToFile(const std::string& filename); // Save task items to a file    

    private:
        std::vector<TaskItem> taskItems; // Vector to hold task items    
};