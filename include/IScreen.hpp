#pragma once
#include <SFML/Graphics.hpp>

/// @brief Interface for all screen types.
/// @details Each screen (main menu, task list, add task, etc.) must implement this interface.
class IScreen {
public:
    virtual ~IScreen() = default;

    /// @brief Handle events like clicks, keypresses, etc.
    virtual void handleEvent(const sf::Event& event) = 0;

    /// @brief Update logic (animations, transitions, etc).
    virtual void update() = 0;

    /// @brief Render screen elements.
    /// @param window The window to draw to.
    virtual void render(sf::RenderWindow& window) = 0;
};
