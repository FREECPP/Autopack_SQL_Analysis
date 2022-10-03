#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::string test_string;
    std::string whole_input;
    std::ifstream input_stream_object;

    input_stream_object.open("t_data.txt");
    if (input_stream_object.is_open())
    {
        while (std::getline(input_stream_object, test_string))
        {
            whole_input += test_string + '\n';
        }
    }

    input_stream_object.close();

    std::cout << whole_input << std::endl;
    return 0;
}
