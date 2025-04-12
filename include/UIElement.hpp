#pragma once
#include <SFML/Graphics.hpp>

class UIElement
{
public:
    // Virtual destructor for proper cleanup of derived classes
    virtual ~UIElement() {}

    // Pure virtual functions to be implemented by derived classes
    virtual sf::Vector2f getSize() const = 0;
    virtual void getPosition(sf::Vector2f& position) const = 0;
    virtual sf::Color getColor() const = 0;
    virtual sf::Color getOutlineColor() const = 0;
    virtual float getOutlineThickness() const = 0;
    virtual const sf::Vector2f& getOrigin() const = 0;

    // Setters for UIElement properties
    virtual void setSize(const sf::Vector2f& size) = 0;
    virtual void setPosition(const sf::Vector2f& position) = 0;
    virtual void setColor(const sf::Color& color) = 0;
    virtual void setOutlineColor(const sf::Color& color) = 0;
    virtual void setOutlineThickness(float thickness) = 0;
    virtual void setOrigin(const sf::Vector2f& origin) = 0;

    // Set texture for UIElement
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void update() = 0;
    virtual void handleEvents(const sf::Event& event) = 0;
};