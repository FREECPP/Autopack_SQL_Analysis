#include <iostream>
#include <map>
#include <string>

void print_map(std::map<std::string, int> &test_map)
{
    for (const auto &data : test_map)
    {
        std::cout << data.first << " " << data.second << std::endl;
    }
}