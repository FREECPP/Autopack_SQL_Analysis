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
#include "from_inputstring_to_key_and_value.h"
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
    // Creating a map
    std::map<std::string, int> data_pair;

    data_input.open("data.txt");
    if (data_input.is_open())
    {
        while (std::getline(data_input, data_to_string))
        {
            std::cout << data_to_string << std::endl;
            // Making two strings out of the whole data_to_string string:

            // String for Key
            // Creating a substring for Key
            std::string key = generating_key(data_to_string);

            // String for Value:

            int value_as_int = generating_value(data_to_string);

            // Putting values in map

            data_pair[key] = value_as_int;
            print_map(data_pair);
        }
    }
    data_input.close();

    return 0;
}
