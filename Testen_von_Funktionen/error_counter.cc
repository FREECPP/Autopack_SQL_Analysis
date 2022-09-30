#include <fstream>
#include <iostream>
#include <map>
#include <string>

void error_counter(std::map<std::string, int> &test_map)
{
    for (const auto &entry : test_map)
    {
    }
}

int main()
{
    std::ifstream data_input;
    std::string raw_data_to_string;
    data_input.open("t_data.txt");
    if (data_input.is_open())
    {
        while (getline(data_input, raw_data_to_string))
        {
            std::cout << raw_data_to_string << std::endl;
        }
    }

    data_input.close();

    return 0;
}
