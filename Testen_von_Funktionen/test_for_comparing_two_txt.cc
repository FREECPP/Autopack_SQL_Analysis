#include "from_inputstring_to_key_and_value.h"
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
    std::string key;
    // creating int for value
    int value;

    input_1.open("t_data.txt");
    if (input_1.is_open())
    {
        while (std::getline(input_1, str_1))
        {
            key = generating_key(str_1);
            value = generating_value(str_1);

            map_1[key] = value;
                }
    }
}