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
    ~Indexer();

};

#endif