#include "file_operations.h"

void csvread(std::string filename) {
    std::ifstream fin;
    std::string line;

    std::uint8_t lineNumber = 0;
    std::uint8_t string_start = 0;
    std::uint8_t string_end = 0;
    std::string date[240];
    std::uint16_t usage[240];
    std::string instrument[240];

    // Open file 
    fin.open(filename, std::ios::in);

    // Check for error
    if (fin.fail())
    {
        std::cerr << "Could not open file\n";
        exit(1);
    }
    

    while (!fin.eof())
    {
        std::getline(fin, line, '\n');

        if (lineNumber != 0){   // Skip header
            // Date
            string_start = 0;
            string_end = line.find(',');
            date[lineNumber-1] = line.substr(string_start, string_end - string_start);

            // Usage
            string_start = string_end+1;
            string_end = line.find(',', string_start);
            usage[lineNumber-1] = stoi(line.substr(string_start, string_end - string_start));

            // Source
            string_start = string_end+1;
            string_end = line.find('\r', string_start);
            instrument[lineNumber-1] = line.substr(string_start, string_end - string_start);

        }

        lineNumber++;
    }

    fin.close();

}