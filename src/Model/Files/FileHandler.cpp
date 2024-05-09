//
// Created by meadowdeath on 08/05/2024.
//

#include <utility>
#include "../../../include/Model/Files/FileHandler.h"


FileHandler::FileHandler(std::string  filename) : fileName(std::move(filename)) {}

bool FileHandler::fileExists() const {
    std::ifstream file(fileName);
    return file.good();
}

bool FileHandler::openForRead() {
    readStream.open(fileName);
    return readStream.is_open();
}

bool FileHandler::openForWrite() {
    writeStream.open(fileName);
    return writeStream.is_open();
}

void FileHandler::closeRead() {
    if (readStream.is_open())
        readStream.close();
}

void FileHandler::closeWrite() {
    if (writeStream.is_open())
        writeStream.close();
}

template<typename T>
void FileHandler::write(const T& data) {
    if (writeStream.is_open())
        writeStream << data << "\n";
}

template<typename T>
void FileHandler::read(T& data) {
    if (readStream.is_open())
        readStream >> data;
}
