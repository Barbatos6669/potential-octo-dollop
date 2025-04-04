#include "../include/Time.hpp"

string Time::getCurrentDateTime() 
{
    auto now = chrono::system_clock::now(); // Get the current time
    auto in_time_t = chrono::system_clock::to_time_t(now); // Convert to time_t

    stringstream ss;
    ss << put_time(localtime(&in_time_t), "%Y-%m-%d %X"); // Format the time
    return ss.str(); // Return the formatted time as a string
}

string Time::getCurrentDate() 
{
    auto now = chrono::system_clock::now(); // Get the current time
    auto in_time_t = chrono::system_clock::to_time_t(now); // Convert to time_t

    stringstream ss;
    ss << put_time(localtime(&in_time_t), "%Y-%m-%d"); // Format the date
    return ss.str(); // Return the formatted date as a string
}

string Time::getCurrentTime() 
{
    auto now = chrono::system_clock::now(); // Get the current time
    auto in_time_t = chrono::system_clock::to_time_t(now); // Convert to time_t

    stringstream ss;
    ss << put_time(localtime(&in_time_t), "%X"); // Format the time
    return ss.str(); // Return the formatted time as a string
}

