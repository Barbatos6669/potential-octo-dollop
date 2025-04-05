#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class SearchBar 
{
    public:  
    
        float searchBarWidth = 400.f; // Width of the search bar
        float searchBarHeight = 40.f; // Height of the search bar
        int searchBarPosX = 0; // X position of the search bar
        int searchBarPosY = 0; // Y position of the search bar
        
        // Constructor to initialize the search bar
        SearchBar(float width, float height, int posX, int posY);
        
        // Destructor
        ~SearchBar();

        // Method to draw the search bar on the window
        void draw(sf::RenderWindow& window);

        // Method to handle input events for the search bar
        void handleInput(sf::Event event); 

    private:
        sf::RectangleShape searchBarBackGround; // Rectangle shape for the search bar
        sf::RectangleShape searchBar; // Rectangle shape for the search bar input area 
        sf::Text searchText; // Text object for displaying the search text
        sf::Font font; // Font for the search text
        sf::Sprite searchIcon; // Sprite for the search icon (if needed)
        sf::Texture searchIconTexture; // Texture for the search icon (if needed)
};