#include "../include/GUI.hpp"
#include <filesystem> // for std::filesystem::exists

// Constructor

GUI::GUI(TaskManager& taskManager) 
    : window(sf::VideoMode(windowWidth, windowHeight), "To Do List"), 
    taskManager(taskManager),
    searchBar(windowWidth / 3 - 16, 40.f, 10, 6),
    panelButtonNewList(windowWidth / 3 - 16, 40.f, 10, windowHeight - 46, "New List", "../assets/icons/icon_area_meteo.png", sf::Color(20, 20, 20, 10)),
    panelButtonTodayList(windowWidth / 3 - 16, 40.f, 10, 50, "Due Today", "../assets/icons/icon_star.png", sf::Color(20, 20, 20, 10)),
    panelButtonMyTasks(windowWidth / 3 - 16, 40.f, 10, 100, "My Tasks", "../assets/icons/icon_map.png", sf::Color(20, 20, 20, 10)),
    panelButtonAddTask(windowWidth / 2 + 130, 40.f, windowWidth / 3 + 10, windowHeight - 46, "Add a Task", "../assets/icons/icon_particle.png", sf::Color(20, 20, 20, 200)), 
    dateTimeDisplay(windowWidth / 2 + 120, 80.f, windowWidth / 3 + 10, 6, "Date", "Time", sf::Color(20, 20, 20, 200))

{
    window.setFramerateLimit(60);   
    
    rightPanel.setSize(sf::Vector2f(windowWidth, windowHeight));
    rightPanel.setFillColor(sf::Color(20, 20, 20)); // Light gray color
    
    listPanel.setSize(sf::Vector2f(windowWidth / 1.5, windowHeight));
    listPanel.setFillColor(sf::Color(50, 50, 50)); // Dark gray color
    listPanel.setPosition(windowWidth / 3, 5); // Position the list panel to the right

    backgroundTexture.loadFromFile("../assets/backgrounds/Background.png"); // Load background texture
    backgroundSprite.setTexture(backgroundTexture); // Set the texture for the background sprite
    backgroundSprite.setScale(0.5f, 0.5f); // Scale the background sprite to fit the window
    backgroundSprite.setPosition(windowWidth / 3, 5); // Position the background sprite at the top-left corner

    panelButtonAddTask.setButtonColor(sf::Color(20, 20, 20, 200)); // Set the button color
    
    dateTimeDisplay.setColor(sf::Color(20, 20, 20, 10)); // Set the date and time display color
}

// Destructor
GUI::~GUI() 
{
    // Cleanup if necessary
}

// Render the GUI
void GUI::render(const std::vector<Task>& tasks) 
{
    window.clear(); 
    window.draw(rightPanel);
    window.draw(listPanel);
    window.draw(backgroundSprite); // Draw the background sprite

    // Draw the search bar
    searchBar.draw(window);
    // Draw the panel button
    panelButtonNewList.draw(window);
    panelButtonTodayList.draw(window);
    panelButtonMyTasks.draw(window);
    panelButtonAddTask.draw(window);
    // Draw the date and time display
    dateTimeDisplay.draw(window);
    // Display the window
    window.display();


}

void GUI::handleInput() 
{   
    sf::Event event;
    while (window.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed) 
        {
            window.close();
        }
        // Handle other events here
        if (event.type == sf::Event::KeyPressed) 
        {
            if (event.key.code == sf::Keyboard::Escape) 
            {
                window.close();
            }
            // Handle other key events here
        }
        int mouseX = sf::Mouse::getPosition(window).x;
        int mouseY = sf::Mouse::getPosition(window).y;

        // Handle mouse events
        panelButtonMyTasks.processEvent(event, mouseX, mouseY);
        panelButtonNewList.processEvent(event, mouseX, mouseY);
        panelButtonTodayList.processEvent(event, mouseX, mouseY);
        panelButtonAddTask.processEvent(event, mouseX, mouseY);

    }
}

void GUI::updateDisplay() 
{
    window.getSize();

    // Update the date and time display
    dateTimeDisplay.updateDate(dateTimeDisplay.displayTextStringDate);
}

