#include "../include/ProgramManager.hpp"

// Constructor
ProgramManager::ProgramManager() 
    : window(sf::VideoMode(UIConfig::baseWidth, UIConfig::baseHeight), "To Do List", sf::Style::Close), // Initialize the window with the base width and height from UIConfig,
    leftPanel(std::make_unique<UIPanel>()), 
    rightPanel(std::make_unique<UIPanel>()), 
    searchBar(std::make_unique<UISearchBar>()), 
    buttonMyDay(std::make_unique<UIButton>()) // Initialize the UI elements
{
    setupWindow(); // Setup the window properties
    setupPanels(); // Setup the panels properties
    setupSearchBar(); // Setup the search bar properties
    setupButtons(); // Setup the buttons properties 
    
}

// Destructor
ProgramManager::~ProgramManager() 
{
    // Destructor logic (if any) can be added here
}

void ProgramManager::run() 
{
    while (window.isOpen()) 
    {
        processEvents(); // Process events
        update(); // Update the program state
        render(); // Render the program
    }
}

void ProgramManager::setupWindow() 
{
    // Set the window properties
    window.setFramerateLimit(60); // Set the frame rate limit
    window.setVerticalSyncEnabled(true); // Enable vertical sync

    std::cout << "Window setup complete." << std::endl; // Log message
    std::cout << "Window size: " << window.getSize().x << "x" << window.getSize().y << std::endl; // Log the window size
}

void ProgramManager::setupPanels() 
{
    leftPanel->setSize(sf::Vector2f(UIConfig::panelWidth, UIConfig::panelHeight)); // Set the panel size   
    leftPanel->setPosition(sf::Vector2f(UIConfig::anchorTopLeft.x, UIConfig::anchorTopLeft.y)); // Set the panel position
    leftPanel->setColor(UIConfig::globalPrimaryColor); // Set the panel color
    leftPanel->setOutlineColor(UIConfig::globalAccentColor); // Set the panel outline color
    leftPanel->setOutlineThickness(UIConfig::globalLinePadding); // Set the panel outline thickness

    rightPanel->setSize(sf::Vector2f(UIConfig::baseWidth - UIConfig::panelWidth, UIConfig::panelHeight)); // Set the panel size
    rightPanel->setPosition(sf::Vector2f(UIConfig::anchorTopLeft.x + UIConfig::panelWidth, UIConfig::anchorTopLeft.y)); // Set the panel position
    rightPanel->setColor(UIConfig::globalTextColor); // Set the panel color
    rightPanel->setOutlineColor(UIConfig::globalAccentColor); // Set the panel outline color
    rightPanel->setOutlineThickness(UIConfig::globalLinePadding); // Set the panel outline thickness
    rightPanel->loadFromFile("assets/backgrounds/climber-9491285_1280.png"); // Load the texture for the right panel
    rightPanel->panelShape.setTexture(&rightPanel->panelTexture); // Set the texture for the right panel shape

    std::cout << "Panels setup complete." << std::endl; // Log message
    std::cout << "Left panel size: " << leftPanel->getSize().x << "x" << leftPanel->getSize().y << std::endl; // Log the left panel size
    std::cout << "Right panel size: " << rightPanel->getSize().x << "x" << rightPanel->getSize().y << std::endl; // Log the right panel size
}

void ProgramManager::setupSearchBar() 
{
    // Setup the search bar properties
    searchBar->setSize(sf::Vector2f(UIConfig::panelWidth - 20, UIConfig::panelButtonHeight)); // Set the search bar size
    searchBar->setPosition(sf::Vector2f(UIConfig::anchorTopLeft.x + 10, UIConfig::anchorTopLeft.y + 10)); // Set the search bar position
    searchBar->setColor(UIConfig::globalPrimaryColor); // Set the search bar color
    searchBar->setOutlineColor(UIConfig::globalAccentColor); // Set the search bar outline color
    searchBar->setOutlineThickness(UIConfig::globalLinePadding); // Set the search bar outline thickness
}

void ProgramManager::setupButtons() 
{
    // Setup the button properties
    buttonMyDay->setSize(sf::Vector2f(UIConfig::panelWidth - 20, UIConfig::panelButtonHeight)); // Set the button size
    buttonMyDay->setPosition(sf::Vector2f(UIConfig::anchorTopLeft.x + 10, UIConfig::anchorTopLeft.y + 10 + UIConfig::panelButtonHeight + 10)); // Set the button position
    buttonMyDay->setColor(UIConfig::globalPrimaryColor); // Set the button color
    buttonMyDay->setOutlineColor(UIConfig::globalAccentColor); // Set the button outline color
    buttonMyDay->setOutlineThickness(UIConfig::globalLinePadding); // Set the button outline thickness
    
}

void ProgramManager::processEvents() 
{
    sf::Event event;
    while (window.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed) 
        {
            window.close(); // Close the window if the close event is triggered
        }

        // Handle events for the panels and search bar
        leftPanel->handleEvents(event); // Handle events for the left panel
        rightPanel->handleEvents(event); // Handle events for the right panel
        searchBar->handleEvents(event); // Handle events for the search bar
        buttonMyDay->handleEvents(event); // Handle events for the button
    }    
}

void ProgramManager::update() 
{
    // Update logic 
}

void ProgramManager::render() 
{
    window.clear(sf::Color::Black); // Clear the window with a black color

    leftPanel->render(window); // Render the panel
    rightPanel->render(window); // Render the panel
    searchBar->render(window); // Render the search bar
    buttonMyDay->render(window); // Render the button

    window.display(); // Display the contents of the window
}

