#include "Seeker.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <memory>


Seeker::Seeker(std::shared_ptr<std::ifstream> fileptr_){
    fileptr = fileptr_;
    SearchWord();
}

void Seeker::SearchWord(){
    bool valid_condition = false;
    while(!valid_condition){
        std::cout<<"Type the word you want to search for: "; std::cin>>word;
        if(word != " "){
            valid_condition = true;
        } else {
            std::cout<<"Invalid word, please make sure to write someting"<<std::endl;
        }
        
    }
    int temp = 0;
    while (std::getline(*fileptr, line)) {
        std::cout << line << std::endl;
        std::cout<<temp<<"\n";
        temp++;
    }
}

int Seeker::SendData(){
    return 1;
}

Seeker::~Seeker(){
}
