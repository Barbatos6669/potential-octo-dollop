#pragma once
#include "UIConfig.hpp"
#include "UIElement.hpp"

class UISearchBar : public UIElement
{
public:
    // Member variables
    sf::RectangleShape searchbarShape; // Shape of the search bar
    sf::Text searchbarText;            // Text displayed in the search bar
    sf::Font searchbarFont;            // Font used for the text

    std::string searchbarTextString;   // String to hold the text input
    bool isActive;                     // Flag to indicate if the search bar is active

    bool isFocused;                    // Flag to indicate if the search bar is focused
    bool isHovered;                    // Flag to indicate if the search bar is hovered
    bool isClicked;                    // Flag to indicate if the search bar is clicked
    bool isTextEntered;                // Flag to indicate if text is entered
    bool isTextDeleted;                // Flag to indicate if text is deleted
    bool isTextCleared;                // Flag to indicate if text is cleared

    // Constructor
    UISearchBar();

    // Destructor
    ~UISearchBar();

    // Override UIElement methods
    sf::Vector2f getSize() const override;
    void getPosition(sf::Vector2f& position) const override;
    sf::Color getColor() const override;
    sf::Color getOutlineColor() const override;
    float getOutlineThickness() const override;
    const sf::Vector2f& getOrigin() const override;

    void setSize(const sf::Vector2f& size) override;
    void setPosition(const sf::Vector2f& position) override;
    void setColor(const sf::Color& color) override;
    void setOutlineColor(const sf::Color& color) override;
    void setOutlineThickness(float thickness) override;
    void setOrigin(const sf::Vector2f& origin) override;

    // Additional methods specific to UISearchBar
    void setText(const std::string& text); // Set the text in the search bar
    std::string getText() const;          // Get the text from the search bar
    void clearText();                     // Clear the text in the search bar

    void render(sf::RenderWindow& window) override; // Render the search bar
    void update() override;                         // Update the search bar (if needed)
    void handleEvents(const sf::Event& event) override; 
};