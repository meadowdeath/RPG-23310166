//
// Created by meadowdeath on 08/05/2024.
//

#ifndef RPG_FILEHANDLER_H
#define RPG_FILEHANDLER_H
#include <fstream>

class FileHandler {
private:
    std::ifstream readStream;
    std::ofstream writeStream;
    std::string fileName;

public:

    explicit FileHandler(std::string  filename);

    bool fileExists() const;

    bool openForRead();
    bool openForWrite();
    void closeRead();
    void closeWrite();

    template<typename T>
    void write(const T& data);

    template<typename T>
    void read(T& data);

};

#endif //RPG_FILEHANDLER_H
