#ifndef SEEKER_HPP
#define SEEKER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

class Seeker {
    private:
    std::shared_ptr<std::ifstream> fileptr;
    std::string word;
    std::string line;
    void SearchWord();
    int SendData();
    public:
    Seeker(std::shared_ptr<std::ifstream> fileptr_);
    ~Seeker();

};

#endif