#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP
#include <iostream>
#include <string>
#include <fstream>
#include <memory>


class FileHandler {
    private:
    std::string filename;
    std::shared_ptr<std::ifstream> fileptr;
    std::string file_format;
    void OpenFile();
    bool FileFinded();
    bool ValidFileFormat();
    public:
    FileHandler();
    ~FileHandler();
};

#endif