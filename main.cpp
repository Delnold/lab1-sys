// Палієнко Дмитро TK-31 | Варіант - 8 | Знайти ті слова, що мають більше голосних ніж приголосних літер.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "functions.h"

int main() {
    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Unable to open the file." << std::endl;
        return 1;
    }

    std::string fileContent((std::istreambuf_iterator<char>(inputFile)), (std::istreambuf_iterator<char>()));
    inputFile.close();

    std::vector<std::string> parsedWords = getWords(fileContent);
    filterAndPrintWords(parsedWords);

    std::cin.get();

    return 0;
}
