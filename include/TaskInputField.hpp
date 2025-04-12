#pragma once
#include "UIConfig.hpp"
#include "UIElement.hpp"
#include "SFML/Graphics.hpp"

class TaskInputField : public UIElement
{
    public:
        // Member variables
        sf::RectangleShape inputFieldShape; // Shape of the input field
        sf::Text inputFieldText; // Text displayed in the input field
        sf::Font inputFieldFont; // Font used for the text

        std::string inputFieldTextString; // String to hold the text input

        bool isActive; // Flag to indicate if the input field is active
        bool isFocused; // Flag to indicate if the input field is focused        

        // Constructor
        TaskInputField();

        // Destructor
        ~TaskInputField();

        // Override UIElement methods
        sf::Vector2f getSize() const override;
        void getPosition(sf::Vector2f& position) const override;
        sf::Color getColor() const override;
        sf::Color getOutlineColor() const override;
        float getOutlineThickness() const override;
        const sf::Vector2f& getOrigin() const override;

        // Setters for UIElement properties
        void setSize(const sf::Vector2f& size) override;
        void setPosition(const sf::Vector2f& position) override;
        void setColor(const sf::Color& color) override;
        void setOutlineColor(const sf::Color& color) override;
        void setOutlineThickness(float thickness) override;
        void setOrigin(const sf::Vector2f& origin) override;

        // Additional methods specific to TaskInputField
        void setText(const std::string& text); // Set the text in the input field
        std::string getText() const; // Get the text from the input field
        void clearText(); // Clear the text in the input field

        void render(sf::RenderWindow& window) override; // Render the input field
        void update() override; // Update the input field (if needed)
        void handleEvents(const sf::Event& event) override; // Handle events for the input field
};
