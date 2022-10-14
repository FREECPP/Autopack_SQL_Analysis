
// filling up a map after reading a .txt file as an input

#include "from_inputstring_to_key_and_value.h"
#include <fstream>
#include <map>
#include <string>

std::map<std::string, int> filling_map(std::ios_base::openmode openmode, std::string filename)
{
    std::fstream f_stream_object;
    std::map<std::string, int> data_pair;
    f_stream_object.open(filename, std::ios_base::in);
    if (f_stream_object.is_open())
    {
        std::string data_to_string;

        while (std::getline(f_stream_object, data_to_string))
        {
            // String for Key
            std::string key = generating_key(data_to_string);

            // String for Value:

            int value_as_int = generating_value(data_to_string);

            // Putting values in map

            data_pair[key] = value_as_int;
        }
    }
    f_stream_object.close();
    return data_pair;
}