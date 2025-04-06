// filepath: todo-list-app/todo-list-app/include/GUI.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "Task.hpp"
#include <iostream>
#include "TaskManager.hpp"
#include "searchBar.hpp"
#include "PanelButton.hpp"
#include "DateTimeDisplay.hpp"
#include "SettingsInterfaceScreen.hpp"

using namespace std;

class GUI {
public:

    enum class InterfaceScreen {
        SETTINGS,
        HELP,
        TASKS,
        TODAY
    };

    int currentScreen = 0;

    int windowWidth = 1080;
    int windowHeight = 720;

    GUI(TaskManager& taskManager);
    ~GUI();

    void render(const std::vector<Task>& tasks);
    void handleInput();
    void updateDisplay();
    void baseSetup();

private:
    sf::RenderWindow window;
    TaskManager& taskManager;

    // GUI elements
    SearchBar searchBar;
    PanelButton panelButtonNewList;
    PanelButton panelButtonTodayList;
    PanelButton panelButtonMyTasks;
    PanelButton panelButtonAddTask;
    PanelButton panelButtonSettings;
    PanelButton PanelButtonHelp;
    DateTimeDisplay dateTimeDisplay; 

    // SettingsInterfaceScreen settingsInterfaceScreen;
    SettingsInterfaceScreen settingsInterfaceScreen;


    // PanelButton panelButtonSettings;
    
    sf::Font font;
    sf::Text text;
    // Additional GUI elements can be added here

    sf::RectangleShape rightPanel;
    sf::RectangleShape taskPanel;
    sf::RectangleShape listBackgroundPanel;
    sf::RectangleShape listForeGroundPanel;


    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
};