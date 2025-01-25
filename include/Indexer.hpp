#ifndef INDEXER_HPP
#define INDEXER_HPP

#include <iostream>
#include <fstream>
#include <string>

class Indexer {
    private:
    std::string line;
    void AddLines();
    void AddSections();
    void AddData();
    public:
    Indexer();
    void getLine(std::string line);
    void getSection(int section_number, std::string section_part);
    void getData(float frecuency, bool section_case);
    ~Indexer();

};

#endif