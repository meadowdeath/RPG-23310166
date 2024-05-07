//
// Created by meadowdeath on 05/05/2024.
//

#ifndef RPG_TABLES_H
#define RPG_TABLES_H

#endif //RPG_TABLES_H
#include <iostream>
#include <iomanip>

namespace tables_utils {
    void printLine(int width) {
        std::cout << "+";
        for (int i = 0; i < width+1; ++i) {
            std::cout << "-";
        }
        std::cout << "+" << std::endl;
    }

    void printCentered(std::string& text, int width) {
        int rightPadding = static_cast<int>((width - text.length()) / 2);
        int leftPadding = static_cast<int>(rightPadding + (width - text.length()) % 2);
        std::cout << "| " << std::setw(rightPadding) << "" << text << std::setw(leftPadding) << "" << "|" << std::endl;
        //std::cout << "| " << std::setw(rightPadding) << "" << text << std::setw(static_cast<int>(padding + (width - text.length()) % 2)) << " |" << std::endl;
    }

    void clearConsole() {
        #ifdef _WIN32
                std::system("cls"); // En Windows
        #else
                // En sistemas basados en UNIX (Linux o macOS)
                std::system("clear");
        #endif
    }
}