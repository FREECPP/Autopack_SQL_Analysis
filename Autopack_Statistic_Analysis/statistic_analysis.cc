/*
Vorgabe:
-In das fertige Programm soll später eine Tabelle eingefügt werden
-In Spalte 1 steht der Ort im Autopack an welchem es zu einem Fehler gekommen ist
-In Spalte 2 steht ein Counter welcher die Fehler verschiedener Orte hochzählt
-Ort und zugehöriger Counter stehen immer nebeneinander in der Tabelle

-Aus den Wertene von Spalte 1 und Spalte 2 soll ein "map"-objekt erstellt werden wobei Spalte 1 der Key ist und Spalte 2 der Value
-Ist der Key nach dem Einfügen noch nicht enthalten, soll ein neuer Key generiert werden
-Gibt es den Key bereits, soll lediglich der Counter erhöht werden

-Beim ersten Einfügen von Daten soll noch nichts analysiert werden
-Werden erneut Daten eingefügt, soll das Programm angeben ob ein entsprechender Counter steigt oder stagniert
-Steigt ein Counter soll unterschieden werden, ob er stark ansteigt oder weniger stark (+1 = wenig) (+2 oder größer = stark)
-Steigt ein Counter stark an, soll das Programm den vorherigen Wert mit Uhrzeit anzeigen, sowie den neuen Wert und die Prozentzahl der Steigerung (eventuell kann er auch eine Tagesprognose angeben, anhand dieser,könnte man prüfen ob sich mit einstellen eines Befüllplatzes die Tagesprognose bessert oder nicht)

-Funktionen sollen zur Übersichtlichkeit ausgelagert werden


Test-Case 1:
-Es werden zwei int-Values eingegeben, das Programm soll automatisch aus int_1 den Key und aus int_2 den dazugehörigen Value für das entprechende map_objekt erstellen

*/
#include <fstream>
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

int main()
{
    // Getting the input from a file
    std::string data_to_string;
    std::ifstream data_input;
    data_input.open("data.txt");
    if (data_input.is_open())
    {
        std::getline(data_input, data_to_string);
        std::cout << data_to_string << std::endl;
    }
    data_input.close();
    // Making two strings out of the whole data_to_string string:

    // String for Key
    // Creating a substring for Key
    std::string key = data_to_string.substr(0, 6);
    std::cout << "Key: " << key << std::endl;

    // String for Value:
    // Getting the last Index before the Value
    std::size_t index_value = data_to_string.find_last_of(" ");
    std::cout << "Index before Value: " << index_value << std::endl;

    // Getting the Size of the whole String (Size - last index_before_the_value - 1 should be the lenght of the value)
    std::size_t max_index_value = data_to_string.size();
    std::cout << "Max. Index: " << max_index_value << std::endl;

    // Calculating the size of the value
    std::size_t lenght_value = max_index_value - (index_value + 1);

    // Calculating the start index of the substring
    std::size_t start_of_substr_value = index_value + 1;

    std::string value = data_to_string.substr(start_of_substr_value, lenght_value);
    std::cout << "Value: " << value << std::endl;

    // Turn the string "Value" into an int to allow operations
    int value_as_int = std::stoi(value);
    std::cout << "Value as Int: " << value_as_int << std::endl;

    // Creating a map
    std::map<std::string, int> data_pair;
    data_pair[key] = value_as_int;

    print_map(data_pair);

    return 0;
}
