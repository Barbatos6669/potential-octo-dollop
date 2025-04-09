#pragma once
#include <SFML/Graphics.hpp>

#include "UIConfig.hpp"

class TaskItem 
{
    public:
        /// Constructor with parameters for width, height, position, and task string
        /// \param width Width of the task item
        /// \param height Height of the task item
        /// \param x X position of the task item
        /// \param y Y position of the task item
        /// \param taskString String representing the task
        /// \note The constructor initializes the task item with the specified parameters and sets the default font and colors.
        TaskItem(float width, float height, float x, float y, const std::string& taskString);

        /// @brief Destructor for TaskItem
        /// \note The destructor cleans up any resources used by the task item.
        ~TaskItem(); // Destructor

        /// @brief Render the task item on the given window
        /// \param window The window to render the task item on
        /// \note This function draws the task item on the specified window using SFML graphics.
        void render(sf::RenderWindow& window);

        /// @brief Update the task item (if needed)
        /// \note This function can be used to update the task item state or properties if needed.
        void setPosition(float x, float y);// Set the position of the task item

        /// @brief Set the task string for the task item
        /// \param taskString The new task string to set
        bool isClicked(float mouseX, float mouseY) const; // Check if the item is clicked

    private:
        sf::RectangleShape background;
        sf::Text taskText; // Text for the task item
        sf::Font taskFont; // Font for the task item text
    std::string taskString; // String for the task item text

};
