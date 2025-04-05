#include "../include/SearchBar.hpp"

// Constructor to initialize the search bar
SearchBar::SearchBar(float width, float height, int posX, int posY) 
{
    // Set up the search bar background
    searchBarBackGround.setSize(sf::Vector2f(width, height)); // Set size to 1/10th of the window height
    searchBarBackGround.setFillColor(sf::Color(200, 200, 200)); // Dark gray color
    searchBarBackGround.setPosition(posX, posY); // Position at the top of the window

    // Set up the search bar input area
    searchBar.setSize(sf::Vector2f(width - 2, height -4)); // Slightly smaller than the background
    searchBar.setFillColor(sf::Color(20, 20, 20)); // Lighter gray color
    searchBar.setPosition(posX + 1, posY + 1); // Position with some padding from the edges

    font.loadFromFile("../assets/fonts/arial.ttf"); // Load font from file
    searchText.setFont(font); // Set the font for the text
    searchText.setCharacterSize(20); // Set character size
    searchText.setFillColor(sf::Color::White); // Set text color to white
    searchText.setPosition(posX + 6, posY + 5); // Position the text inside the search bar
    searchText.setString("Search..."); // Set default text

    searchIconTexture.loadFromFile("../assets/icons/SearchIcon.png"); // Load search icon texture

    searchIcon.setTexture(searchIconTexture); // Set the texture for the search icon
    searchIcon.setScale(0.5f, 0.5f); // Scale the icon to fit the search bar
    searchIcon.setPosition(posX + width - 40, posY + 4); // Position the search icon inside the search bar

}

// Destructor
SearchBar::~SearchBar() 
{
    // Cleanup if necessary
}

// Method to draw the search bar on the window
void SearchBar::draw(sf::RenderWindow& window) 
{
    // Draw the search bar background and input area
    window.draw(searchBarBackGround);
    window.draw(searchBar);
    window.draw(searchText); // Draw the search text1
    window.draw(searchIcon); // Draw the search icon
}