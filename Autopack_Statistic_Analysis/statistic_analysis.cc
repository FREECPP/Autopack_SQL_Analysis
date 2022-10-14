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
#include "filling_map.h"
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
    // creating an input file stream object for
    std::ifstream data_input;
    // Creating output file stream object
    std::fstream comparing_file;
    // Creating a map
    std::map<std::string, int> data_pair;
    // Creating second map
    std::map<std::string, int> data_pair_2;
    // declare an openmode object to specifiy the openmode
    std::ios_base::openmode openmode_in = std::ios_base::in;

    std::string input_1 = "data.txt";
    data_pair = filling_map(openmode_in, input_1);

    if (fs::exists("comparing_file.txt"))
    {

        std::string comp_input = "comparing_file.txt";
        data_pair_2 = filling_map(openmode_in, comp_input);

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
                for (const auto &data : data_pair)
                {
                    auto search = data_pair_2.find(data.first);
                    // Key of map_2 was found in map_1
                    if (search != data_pair_2.end())
                    {
                        // compare value of map_2 with value of map_1
                        if (data.second > data_pair_2[data.first])
                        {
                            // case if error count has increased
                            output << data.first << " before: " << data_pair_2[data.first] << " after: " << data.second << '\n';
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
                fs::create_directory("Autopack_Statistic_Analysis/output.txt");
            }
        }
    }
    // maybe put content of else part into a library
    else
    {

        comparing_file.open("comparing_file.txt", std::ios_base::app);
        if (comparing_file.is_open())
        {
            std::string input_for_comparing_file;
            std::string cache_string_f_c;
            data_input.open("data.txt");
            if (data_input.is_open())
            {
                while (std::getline(data_input, cache_string_f_c))
                {
                    input_for_comparing_file += cache_string_f_c + '\n';
                }
            }
            data_input.close();

            comparing_file << input_for_comparing_file;
        }

        comparing_file.close();
    }

    return 0;
}
