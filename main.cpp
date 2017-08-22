#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>

bool check_arguments(int argc, char** argv);

int main(int argc, char** argv)
{
    srand(time(0));
    if (check_arguments(argc, argv))
    {
        std::ifstream file(argv[1]);
        int lineCount = std::count(std::istreambuf_iterator<char>(file),
                   std::istreambuf_iterator<char>(), '\n');

        file.clear();
        file.seekg(0);

        int randLine = rand() % lineCount;

        std::string line;
        for (int i = 0; i < randLine; i++)
        {
            std::getline(file, line);
        }

        std::cout << "Resultant line is: " << line << std::endl;
    }

    return 0;
}

bool check_arguments(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " FILENAME" << std::endl;
        return false;
    }

    return true;
}
