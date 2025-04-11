#pragma once
#include "UIConfig.hpp"
#include "UIElement.hpp"

class UIButton : public UIElement
{       
    public:
        sf::RectangleShape buttonShape; // Shape of the button
        sf::Text buttonText; // Text displayed on the button
        sf::Font buttonFont; // Font used for the button text
        
        // Constructor
        UIButton();

        //  Destructor
        ~UIButton(); // Default destructor

        // Override UIElement methods
        void render(sf::RenderWindow& window) override; // Function to render the panel
        void update() override;  // Function to update the panel (if needed)
        void handleEvents(const sf::Event& event) override; // Function to handle events (if needed)
    
        // Load texture from file
        bool loadFromFile(const std::string& filename);
    
        // Getters for panel properties
        sf::Vector2f getSize() const override;
        void getPosition(sf::Vector2f& position) const override;
        sf::Color getColor() const override;
        sf::Color getOutlineColor() const override;
        float getOutlineThickness() const override;
        const sf::Vector2f& getOrigin() const override;
        const sf::Texture& getTexture() const;
        const sf::Text& getText() const; // Get the text in the button
    
        // Setters for panel properties
        void setSize(const sf::Vector2f& size) override;
        void setPosition(const sf::Vector2f& position) override;
        void setColor(const sf::Color& color) override;
        void setOutlineColor(const sf::Color& color) override;
        void setOutlineThickness(float thickness) override;
        void setOrigin(const sf::Vector2f& origin) override;
        void setTexture(const sf::Texture& texture, bool resetRect = false);
        void setText(const std::string& text); // Set the text in the button
};

