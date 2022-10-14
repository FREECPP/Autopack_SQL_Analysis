#include "filling_map.h"
#include "from_inputstring_to_key_and_value.h"
#include "print_map.h"
#include <fstream>
#include <map>
#include <string>

int main()
{
    std::ios_base::openmode base_object = std::ios_base::in;
    std::string filename = "test.txt";
    std::map<std::string, int> test_map = filling_map(base_object, filename);
    print_map(test_map);
}