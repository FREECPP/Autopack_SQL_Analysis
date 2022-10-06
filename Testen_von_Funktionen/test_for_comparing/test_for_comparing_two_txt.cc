#include "from_inputstring_to_key_and_value.h"
#include "print_map.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>

int main()
{
    // creating input-stream-objects
    std::ifstream input_1;
    std::ifstream input_2;
    // creating strings to push data into
    std::string str_1;
    std::string str_2;

    // creating first map
    std::map<std::string, int> map_1;
    // creating string for key
    std::string key_1;
    // creating int for value
    int value_1;

    // creating second map
    std::map<std::string, int> map_2;
    // creating string for key
    std::string key_2;
    // creating int for value
    int value_2;

    input_2.open("data_2.txt");
    if (input_2.is_open())
    {
        while (std::getline(input_2, str_2))
        {
            key_2 = generating_key(str_2);
            value_2 = generating_value(str_2);

            map_2[key_2] = value_2;
        }
    }
    input_2.close();

    input_1.open("data_1.txt");
    if (input_1.is_open())
    {
        while (std::getline(input_1, str_1))
        {
            key_1 = generating_key(str_1);
            value_1 = generating_value(str_1);

            map_1[key_1] = value_1;
        }
    }
    input_1.close();

    for (const auto &data : map_2)
    {
        auto search = map_1.find(data.first);
        // Key of map_2 was found in map_1
        if (search != map_1.end())
        {
            std::cout << "Found" << std::endl;
        }
        // Key of map_2 was not found in map_1
        else
        {
            std::cout << "Not found" << std::endl;
        }
    }

    return 0;
}