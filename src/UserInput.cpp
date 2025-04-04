#include "../include/UserInput.hpp"

string UserInput::convertUserInputLowercase(const string& str) 
{
    string lowerStr = str;
    for (char& c : lowerStr) 
    {
        c = tolower(c); // Convert each character to lowercase
    }
    return lowerStr;
}

string UserInput::trimUserInput(const string& str) 
{
    size_t first = str.find_first_not_of(' '); // Find the first non-space character
    size_t last = str.find_last_not_of(' '); // Find the last non-space character
    return (first == string::npos) ? "" : str.substr(first, (last - first + 1)); // Return the trimmed string
}
