#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP
#include <iostream>
#include <ifstream>


class FileHandler {
    private:
    ifstream file;
    string file_format;
    bool FileFinded();
    bool ValidFileFormat();
    public:
    FileHandler();
    ~FileHandler();
};

#endif