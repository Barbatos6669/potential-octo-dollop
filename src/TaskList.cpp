#include "../include/TaskList.hpp"
#include <thread> // Required for std::this_thread

// Constructor with default values
TaskList::TaskList(int width, int height, int x, int y)
{

    // Initialize task items (example: adding 5 task items)
    // for (int i = 0; i < 5; ++i) {
    //     TaskItem taskItem(width - 20, 50, 450 + 10, 100 + 10 + i * 60, "Task " + std::to_string(i + 1)); // Create a new TaskItem
    //     taskItems.push_back(taskItem); // Add to the vector of task items
    // }

}

// Destructor
TaskList::~TaskList() {
    // Destructor implementation (if needed)
}

void TaskList::render(sf::RenderWindow& window) 
{
    // Draw each TaskItem
    for (auto& task : taskItems) 
    {
        task.render(window); // Call the render function of each task
    }
}

void TaskList::update() 
{
    // Update each TaskItem (if needed)
    for (auto& task : taskItems) 
    {
        // Update logic for each task item can be added here
    }
}

void TaskList::processEvents(const sf::Event& event) 
{
    if (event.type == sf::Event::MouseButtonPressed) 
    {
        float mouseX = event.mouseButton.x;
        float mouseY = event.mouseButton.y;

        bool removed = false;

        for (auto it = taskItems.begin(); it != taskItems.end(); ++it) {
            if (it->isClicked(mouseX, mouseY)) {
                taskItems.erase(it);
                std::cout << "Task item clicked and removed." << std::endl;
                removed = true;
                break; // stop iterating after removal
            }
        }

        if (removed) {
            // Now reposition safely after removal
            int y = 120;
            for (auto& task : taskItems) {
                task.setPosition(450, y);
                y += 60;

                std::cout << "Task item repositioned." << std::endl;

                std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Uncomment this line to see the repositioning effect


            }
        }
    }
}

void TaskList::loadFromFile(const std::string& filename) 
{
    std::ifstream file(filename); // Open the file for reading
    if (!file.is_open()) 
    {
        std::cerr << "Error opening file: " << filename << std::endl; // Handle file open error
        return;
    }

    taskItems.clear(); // Clear existing task items

    std::string line;
    int y = 120; // Initialize y position for task items
    while (std::getline(file, line)) 
    { 
        std::cout << line << std::endl; // Print each line (for debugging purposes)
        // Create a new TaskItem for each line in the file
        TaskItem taskItem(200, 50, 450, y, line); // Adjust width and height as needed
        taskItems.push_back(taskItem); // Add to the vector of task items
        y += 60; // Increment y position for the next task item
    }
}

void TaskList::saveToFile(const std::string& filename) 
{
    std::ofstream file(filename); // Open the file for writing
    if (!file.is_open()) 
    {
        std::cerr << "Error opening file: " << filename << std::endl; // Handle file open error
        return;
    }

    for (const auto& task : taskItems) 
    {
        // Write task details to the file (example: task name)
        file << "Task details here" << std::endl; // Replace with actual task details
    }
}
