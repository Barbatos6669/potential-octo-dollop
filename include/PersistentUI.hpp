#pragma once   
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "iostream"
#include "UIConfig.hpp"
#include "UIButton.hpp"
#include "UIPanel.hpp"

#include "UITime.hpp"


class PersistentUI
{
    public:

        UIPanel leftPanel; // Left panel object
        UIPanel contentPanel; // Content panel object
        UIButton searchButton; // Search button object
        UIButton myDayButton; // My Day button object
        UIButton tasksButton; // Tasks button object
        UIButton newListButton; // New List button object
        UIButton addATaskButton; // Add a Task button object
        UIButton settingsButton; // Settings button object
        UIButton calendarButton; // Calendar button object        

        UITime timeDisplay; // Time display object
        sf::Texture backgroundTexture; // Background texture
        sf::Sprite backgroundSprite; // Background sprite
        // Constructor and Destructor
        PersistentUI();
        ~PersistentUI();

        void render(sf::RenderWindow& window); // Draw the UI elements
        void update(); // Update the UI elements
        void processEvents(sf::Event& event); // Process events related to the UI elements

};