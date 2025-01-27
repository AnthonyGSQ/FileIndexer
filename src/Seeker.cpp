#include "Seeker.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <unordered_set>


Seeker::Seeker(std::shared_ptr<std::ifstream> fileptr_, std::string format){
    fileptr = fileptr_;
    if(format == "csv"){
        has_sections = true;
    }
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
    LinesSeeker();
    return;
}

int Seeker::SectionsSeeker(std::string line, std::unordered_set<int> & section_dictionary){
    std::stringstream allsections(line);
    std::string section;
    int section_number = 0;
    int sections_with_word = 0;
    size_t position;
    while(getline(allsections,section,'\t')){
        section_number++;
        position = section.find(word);
        if(position != std::string::npos){
            std::cout<<"=========================\n";
            std::cout<<"Word finded on the section "<<section_number<<std::endl;
            std::cout<<"=========================\n";
            indexer.getSection(section_number,section);
        }
        section_dictionary.insert(section_number);
    }
    return section_number;
}

void Seeker::LinesSeeker(){
    size_t position;
    int number_of_lines = 0;
    bool finded = false;
    int lines_with_word = 0;
    int total_sections = 0;
    int temp = 0;
    while (std::getline(*fileptr, line)) {
        number_of_lines++;
        position = line.find(word);
        if(position != std::string::npos){
            std::cout<<"=========================\n";
            std::cout<<"Word finded on the line "<<number_of_lines<<std::endl;
            std::cout<<"=========================\n";
            std::cout << line << std::endl;
            //TODO: logica para enviar la linea/seccion a indexer
            indexer.getLine(line);
            lines_with_word++;
        }
        if(has_sections){
            std::unordered_set<int> section_dictionary;
            temp = SectionsSeeker(line, section_dictionary);
            if(temp > total_sections){
                total_sections = temp;
            }
            temp = section_dictionary.size();
            SendData(total_sections, temp, true);
        }
    }
    SendData(number_of_lines, lines_with_word, false);
}

void Seeker::SendData(int total, int total_with_word, bool section_case){
    float frecuency;
    
    frecuency = total_with_word/total;
    indexer.getData(frecuency, section_case);
    return;
}

Seeker::~Seeker(){
}
