#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <array>
#include <chrono>
#include <ctime>

using namespace std;

class UserInput 
{
public:    
    /// @brief Converts user input to lowercase.
    /// @details This function takes a string and converts all characters to lowercase.
    /// @param str 
    /// @return The lowercase version of the input string.
    /// @note This function is used to standardize user input for comparison.
    string convertUserInputLowercase(const string& str);

    /// @brief Trims leading and trailing whitespace from user input.
    /// @details This function takes a string and removes any leading or trailing whitespace characters.
    /// @param str 
    /// @return The trimmed version of the input string.
    /// @note This function is used to clean up user input before processing.
    string trimUserInput(const string& str);
};