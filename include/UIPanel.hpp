#pragma once
#include "UIConfig.hpp"
#include "UIElement.hpp"

class UIPanel : public UIElement
{
public:
    sf::RectangleShape panelShape; // Shape of the panel
    sf::Texture panelTexture;      // Texture of the panel
    std::string texturePath;       // Path to the texture file

    // Constructor
    UIPanel(const sf::Vector2f& size = sf::Vector2f(200, 200), const sf::Color& color = sf::Color::White);

    // Destructor
    ~UIPanel();

    // Override UIElement methods
    void render(sf::RenderWindow& window) override; // Function to render the panel
    void update() override;                         // Function to update the panel (if needed)
    void handleEvents(const sf::Event& event) override; // Corrected signature    // Function to handle events (if needed)

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

    // Setters for panel properties
    void setSize(const sf::Vector2f& size) override;
    void setPosition(const sf::Vector2f& position) override;
    void setColor(const sf::Color& color) override;
    void setOutlineColor(const sf::Color& color) override;
    void setOutlineThickness(float thickness) override;
    void setOrigin(const sf::Vector2f& origin) override;
    void setTexture(const sf::Texture& texture, bool resetRect = false);

private:
    // Private members (if any)
};

