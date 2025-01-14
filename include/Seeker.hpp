#ifndef SEEKER_HPP
#define SEEKER_HPP

#include <iostream>
#include <ifstream>
#include <string>

class Seeker {
    private:
    unique_ptr<ifstream> fileptr;
    string word;
    string line;
    void SearchWord();
    int SendData();
    public:
    Seeker();
    ~Seeker();

};

#endif