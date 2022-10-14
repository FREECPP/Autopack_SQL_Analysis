#include <iostream>
#include <string>

std::string generating_key(std::string &input)
{
    // String for Key
    // Creating a substring for Key
    std::string key = input.substr(0, 6);
    //std::cout << "Key: " << key << std::endl;
    return key;
}

int generating_value(std::string &input)
{
    // String for Value:
    // Getting the last Index before the Value
    std::size_t index_value = input.find_last_of(" ");
    
    // Getting the Size of the whole String (Size - last index_before_the_value - 1 should be the lenght of the value)
    std::size_t max_index_value = input.size();
    
    // Calculating the size of the value
    std::size_t lenght_value = max_index_value - (index_value + 1);

    // Calculating the start index of the substring
    std::size_t start_of_substr_value = index_value + 1;
    std::string value = input.substr(start_of_substr_value, lenght_value);
    
    // Turn the string "Value" into an int to allow operations
    int value_as_int = std::stoi(value);
    
    return value_as_int;
}

