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

class Time
{
public:
    int year; ///< The year of the date.
    int month; ///< The month of the date.
    int day; ///< The day of the date.

    int hour; ///< The hour of the time.
    int minute; ///< The minute of the time.
    int second; ///< The second of the time.

    /// @brief Gets the current date and time.
    /// @details This function returns the current date and time as a string.
    /// @return The current date and time in the format "YYYY-MM-DD HH:MM:SS".
    /// @note This function is used to display the current date and time.
    string getCurrentDateTime(); 

    /// @brief Gets the current date.
    /// @details This function returns the current date as a string.
    /// @param None
    /// @return The current date in the format "YYYY-MM-DD".
    /// @note This function is used to display the current date.
    string getCurrentDate(); ///< The current date in the format "YYYY-MM-DD".

    /// @brief Gets the current time.
    /// @details This function returns the current time as a string.
    /// @return The current time in the format "HH:MM:SS".
    /// @note This function is used to display the current time.
    string getCurrentTime(); ///< The current time in the format "HH:MM:SS".
};