
#pragma Once 
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include "UIConfig.hpp"
#include "UIPanel.hpp"
#include "UISearchBar.hpp"
#include "UIButton.hpp"

class ProgramManager
{
    public:
        ProgramManager(); // Constructor
        ~ProgramManager(); // Destructor

        void run(); // Main loop of the program   
        void setupWindow(); // Setup the window properties
        void setupPanels(); // Setup the panels properties
        void setupSearchBar(); // Setup the search bar properties  
        void setupButtons(); // Setup the buttons properties   

    private:
        sf::RenderWindow window; // SFML window object


        std::unique_ptr<UIPanel> leftPanel; // UI panel object.
        std::unique_ptr<UIPanel> rightPanel; // UI panel object.
        std::unique_ptr<UISearchBar> searchBar; // UI search bar object.
        std::unique_ptr<UIButton> buttonMyDay; // UI button object.
        
        void processEvents(); // Process events
        void update(); // Update the program state
        void render(); // Render the program
};