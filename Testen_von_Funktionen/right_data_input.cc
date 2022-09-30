#include <fstream>
#include <iostream>
#include <string>

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