#ifndef SEEKER_HPP
#define SEEKER_HPP
#include "Indexer.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <unordered_set>

class Seeker {
    private:
    Indexer indexer;
    std::shared_ptr<std::ifstream> fileptr;
    std::string word;
    std::string line;
    bool has_sections = false;
    void SearchWord();
    void SendData(int number_of_lines, int lines_with_word, bool has_sections);
    void LinesSeeker();
    int SectionsSeeker(std::string line, std::unordered_set<int> & section_dictionary);
    public:
    Seeker(std::shared_ptr<std::ifstream> fileptr_, std::string format);
    ~Seeker();

};

#endif