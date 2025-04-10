/********************************************************************************************/
/*  PersistentUI.cpp                                                                        */
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
#include "../include/PersistentUI.hpp"

// Constructor
PersistentUI::PersistentUI() 
    : leftPanel(), // Initialize leftPanel
    contentPanel(), // Initialize contentPanel
    searchButton(UIConfig::panelButtonWidth, UIConfig::panelButtonHeight, 0, 0, UIConfig::accentColor, "Search...", "../assets/icons/icon_search.png"), 
    myDayButton(UIConfig::panelButtonWidth, UIConfig::panelButtonHeight, 0, 0, UIConfig::accentColor, "My Day", "../assets/icons/icon_star.png"),
    tasksButton(UIConfig::panelButtonWidth, UIConfig::panelButtonHeight, 0, 0, UIConfig::accentColor, "Tasks", "../assets/icons/icon_text_panel.png"),
    newListButton(UIConfig::panelButtonWidth, UIConfig::panelButtonHeight, 0, 0, UIConfig::accentColor, "New List", "../assets/icons/icon_file.png"),
    addATaskButton(UIConfig::panelButtonWidth, UIConfig::panelButtonHeight, 0, 0, UIConfig::accentColor, "Add a Task", "../assets/icons/icon_brush.png"),
    settingsButton(UIConfig::panelButtonWidth, UIConfig::panelButtonHeight, 0, 0, UIConfig::accentColor, "", "../assets/icons/icon_gear.png"),
    calendarButton(UIConfig::panelButtonWidth, UIConfig::panelButtonHeight, 0, 0, UIConfig::accentColor, "", "../assets/icons/icon_grid.png"),
    timeDisplay(0, 0, 200, 50, UIConfig::textColor) // Initialize timeDisplay with default values
    
{
    // Set the position of the search button
    searchButton.buttonShape.setPosition(UIConfig::spacing, UIConfig::spacing); // Set the position of the button
    searchButton.buttonShape.setFillColor(UIConfig::primaryColor); // Set the color of the button
    searchButton.buttonText.setFillColor(UIConfig::textColor); // Set the text color
    searchButton.buttonText.setPosition(20, 15); // Set the position of the text
    searchButton.buttonIconSprite.setPosition(UIConfig::panelButtonWidth - 30 , UIConfig::panelButtonHeight / 2 - 5); // Set the position of the icon sprite    
    searchButton.buttonIconSprite.setScale(1.5f, 1.5f); // Scale the icon sprite

    // Set the position of the My Day button
    myDayButton.buttonShape.setPosition(UIConfig::spacing, UIConfig::panelButtonHeight + UIConfig::spacing * 2 + UIConfig::spacing); // Set the position of the button
    myDayButton.buttonShape.setFillColor(UIConfig::primaryColor); // Set the color of the button
    myDayButton.buttonText.setFillColor(UIConfig::textColor); // Set the text color
    myDayButton.buttonText.setPosition(50, UIConfig::panelButtonHeight + UIConfig::spacing * 2 + 15); // Set the position of the text
    myDayButton.buttonIconSprite.setPosition(20 , UIConfig::panelButtonHeight + UIConfig::spacing * 2 + 20); // Set the position of the icon sprite
    myDayButton.buttonIconSprite.setScale(1.5f, 1.5f); // Scale the icon sprite

    // Set the position of the Tasks button
    tasksButton.buttonShape.setPosition(UIConfig::spacing, UIConfig::panelButtonHeight * 2 + UIConfig::spacing * 3 + UIConfig::spacing); // Set the position of the button
    tasksButton.buttonShape.setFillColor(UIConfig::primaryColor); // Set the color of the button
    tasksButton.buttonText.setFillColor(UIConfig::textColor); // Set the text color
    tasksButton.buttonText.setPosition(50, UIConfig::panelButtonHeight * 2 + UIConfig::spacing * 3 + 15); // Set the position of the text
    tasksButton.buttonIconSprite.setPosition(20 , UIConfig::panelButtonHeight * 2 + UIConfig::spacing * 3 + 20); // Set the position of the icon sprite
    tasksButton.buttonIconSprite.setScale(1.5f, 1.5f); // Scale the icon sprite

    // Set the position of the New List button
    newListButton.buttonShape.setPosition(UIConfig::spacing, UIConfig::WINDOW_HEIGHT - UIConfig::panelButtonHeight); // Set the position of the button
    newListButton.buttonShape.setFillColor(UIConfig::primaryColor); // Set the color of the button
    newListButton.buttonText.setFillColor(UIConfig::textColor); // Set the text color
    newListButton.buttonText.setPosition(50, UIConfig::WINDOW_HEIGHT - 40); // Set the position of the text
    newListButton.buttonIconSprite.setPosition(20 , UIConfig::WINDOW_HEIGHT - 35); // Set the position of the icon sprite
    newListButton.buttonIconSprite.setScale(1.5f, 1.5f); // Scale the icon sprite

    // Set the position of the Add a Task button
    addATaskButton.buttonShape.setPosition(UIConfig::panelWidth + UIConfig::spacing * 10, UIConfig::WINDOW_HEIGHT - UIConfig::panelButtonHeight * 2); // Set the position of the button
    addATaskButton.buttonShape.setSize(sf::Vector2f(UIConfig::WINDOW_WIDTH / 2, UIConfig::panelButtonHeight)); // Set the size of the button
    addATaskButton.buttonShape.setFillColor(UIConfig::primaryColor); // Set the color of the button
    addATaskButton.buttonText.setFillColor(UIConfig::textColor); // Set the text color
    addATaskButton.buttonText.setPosition(UIConfig::panelWidth + UIConfig::spacing * 25, UIConfig::WINDOW_HEIGHT - 90); // Set the position of the text
    addATaskButton.buttonIconSprite.setPosition(UIConfig::panelWidth + UIConfig::spacing * 20, UIConfig::WINDOW_HEIGHT - 85); // Set the position of the icon sprite
    addATaskButton.buttonIconSprite.setScale(1.5f, 1.5f); // Scale the icon sprite

    // Set the position of the Settings button
    settingsButton.buttonShape.setPosition(UIConfig::WINDOW_WIDTH - UIConfig::iconSize - UIConfig::spacing, UIConfig::spacing); // Set the position of the button
    settingsButton.buttonShape.setSize(sf::Vector2f(UIConfig::iconSize, UIConfig::iconSize)); // Set the size of the button
    settingsButton.buttonShape.setFillColor(UIConfig::primaryColor); // Set the color of the button
    settingsButton.buttonText.setFillColor(UIConfig::textColor); // Set the text color
    settingsButton.buttonText.setPosition(UIConfig::panelWidth + UIConfig::spacing + 50, UIConfig::WINDOW_HEIGHT - 40); // Set the position of the text
    settingsButton.buttonIconSprite.setPosition(UIConfig::WINDOW_WIDTH - UIConfig::iconSize + 9, UIConfig::spacing + 13); // Set the position of the icon sprite
    settingsButton.buttonIconSprite.setScale(1.5f, 1.5f); // Scale the icon sprite

    // Set the position of the Calendar button
    calendarButton.buttonShape.setPosition(UIConfig::WINDOW_WIDTH - UIConfig::iconSize - UIConfig::spacing -  UIConfig::iconSize - UIConfig::spacing, UIConfig::spacing); // Set the position of the button
    calendarButton.buttonShape.setSize(sf::Vector2f(UIConfig::iconSize, UIConfig::iconSize)); // Set the size of the button
    calendarButton.buttonShape.setFillColor(UIConfig::primaryColor); // Set the color of the button
    calendarButton.buttonText.setFillColor(UIConfig::textColor); // Set the text color
    calendarButton.buttonText.setPosition(UIConfig::panelWidth + UIConfig::spacing + 60, UIConfig::WINDOW_HEIGHT - 90); // Set the position of the text
    calendarButton.buttonIconSprite.setPosition(UIConfig::WINDOW_WIDTH - UIConfig::iconSize * 2, UIConfig::spacing + 13); // Set the position of the icon sprite
    calendarButton.buttonIconSprite.setScale(1.5f, 1.5f); // Scale the icon sprite

    // Set the position of the time display
    timeDisplay.dayText.setPosition(UIConfig::panelWidth + UIConfig::spacing * 2, UIConfig::spacing); // Set the position of the day text
    timeDisplay.timeText.setPosition(UIConfig::panelWidth + UIConfig::spacing + 100, UIConfig::spacing); // Set the position of the time text
    timeDisplay.dateText.setPosition(UIConfig::panelWidth + UIConfig::spacing + 200, UIConfig::spacing); // Set the position of the date text

    // Set the font and color of the time display text
    timeDisplay.dayText.setFillColor(UIConfig::textColor); // Set the color of the day text
    timeDisplay.timeText.setFillColor(UIConfig::textColor); // Set the color of the time text
    timeDisplay.dateText.setFillColor(UIConfig::textColor); // Set the color of the date text
    timeDisplay.dayText.setCharacterSize(24); // Set the character size for day text
    timeDisplay.timeText.setCharacterSize(24); // Set the character size for time text
    timeDisplay.dateText.setCharacterSize(24); // Set the character size for date text

    // Set the font for the time display text
    timeDisplay.dayText.setFont(timeDisplay.font); // Set the font of the day text
    timeDisplay.timeText.setFont(timeDisplay.font); // Set the font of the time text
    timeDisplay.dateText.setFont(timeDisplay.font); // Set the font of the date text
    
    // Set the position of the left panel
    contentPanel.windowPanel.setPosition(UIConfig::panelWidth + UIConfig::spacing, 0); // Set the position of the content panel
    contentPanel.windowPanel.setSize(sf::Vector2f(UIConfig::WINDOW_WIDTH - UIConfig::panelWidth, UIConfig::WINDOW_HEIGHT)); // Set the size of the content panel
    contentPanel.windowPanel.setFillColor(UIConfig::secondaryColor); // Set the color of the content panel

    // Set the position of the left panel
    contentPanel.backgroundTexture.loadFromFile("../assets/backgrounds/climber-9491285_1280.png"); // Load the background texture
    contentPanel.backgroundSprite.setTexture(contentPanel.backgroundTexture); // Set the texture of the background sprite
    contentPanel.backgroundSprite.setPosition(UIConfig::panelWidth + UIConfig::spacing, 0); // Set the position of the background sprite
    contentPanel.backgroundSprite.setScale(
        float(UIConfig::WINDOW_WIDTH - UIConfig::panelWidth) / contentPanel.backgroundTexture.getSize().x,
        float(UIConfig::WINDOW_HEIGHT) / contentPanel.backgroundTexture.getSize().y
    ); // Scale the background sprite to fit the content panel

    std::cout << "PersistentUI initialized." << std::endl;
}

// Destructor
PersistentUI::~PersistentUI() 
{
    // Clean up resources here if needed
    std::cout << "PersistentUI destroyed." << std::endl;
}

// Draw the UI elements
void PersistentUI::render(sf::RenderWindow& window) 
{
    // Draw the left panel
    leftPanel.draw(window); // Draw the left panel
    contentPanel.draw(window); // Draw the content panel
    searchButton.render(window); // Draw the search button
    myDayButton.render(window); // Draw the My Day button
    tasksButton.render(window); // Draw the Tasks button
    newListButton.render(window); // Draw the New List button
    addATaskButton.render(window); // Draw the Add a Task button
    settingsButton.render(window); // Draw the Settings button
    calendarButton.render(window); // Draw the Calendar button
    timeDisplay.render(window); // Draw the time display    
}

// Update the UI elements
void PersistentUI::update() 
{
    // Update the UI elements here if needed
    leftPanel.update(); // Update the left panel
    searchButton.update(); // Update the search button
    myDayButton.update(); // Update the My Day button
    tasksButton.update(); // Update the Tasks button
    newListButton.update(); // Update the New List button
    addATaskButton.update(); // Update the Add a Task button
    settingsButton.update(); // Update the Settings button
    calendarButton.update(); // Update the Calendar button
    timeDisplay.update(); // Update the time display
}

// Process events
void PersistentUI::processEvents(sf::Event& event) 
{
    // Process events related to the UI elements here if needed
    searchButton.processEvents(event); // Process events for the search button
    myDayButton.processEvents(event); // Process events for the My Day button
    tasksButton.processEvents(event); // Process events for the Tasks button
    newListButton.processEvents(event); // Process events for the New List button
    addATaskButton.processEvents(event); // Process events for the Add a Task button
    settingsButton.processEvents(event); // Process events for the Settings button
    calendarButton.processEvents(event); // Process events for the Calendar button
    timeDisplay.processEvents(event); // Process events for the time display
}