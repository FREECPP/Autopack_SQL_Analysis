#include "from_inputstring_to_key_and_value.h"
#include "print_map.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

namespace fs = std::filesystem;

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
    // creating the ouput file
    std::ofstream output;

    // creating a while-loop to make sure an output-file is created
    bool while_condition = true;
    while (while_condition == true)
    {
        // checking if the output file already exists
        output.open("output.txt");
        if (output.is_open())
        {
            // loop to iterate over the whole map
            for (const auto &data : map_2)
            {
                auto search = map_1.find(data.first);
                // Key of map_2 was found in map_1
                if (search != map_1.end())
                {
                    // compare value of map_2 with value of map_1
                    if (data.second > map_1[data.first])
                    {
                        // case if error count has increased
                        output << data.first << " before: " << map_1[data.first] << " after: " << data.second << '\n';
                    }
                    else
                    {
                        // case if error count hasn't been increased

                        // empty but code possible
                    }
                }
                // Key of map_2 was not found in map_1
                else
                {
                    output << "New Error:  " << data.first << ":" << data.second << '\n';
                }
            }
            // ending the while-loop
            while_condition = false;
        }
        else
        {
            fs::create_directory("Testen_von_Funktionen/test_for_comparing/output.txt");
        }
    }

    return 0;
}