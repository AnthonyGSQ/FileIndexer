#include "FileHandler.hpp"
#include "Seeker.hpp"
#include <iostream>
#include <string>
#include <fstream>

   
FileHandler::FileHandler(){
    if(OpenFile()){
        Seeker seeker(fileptr, format);
    }
    //do nothing
}

bool FileHandler::OpenFile(){
    std::cout<<"Hello! Please write the route and name of the file: ";
    std::cin>>filename;
    size_t pos = filename.find('.');
    if(pos == std::string::npos){
        std::cout<<"Not a valid file name!, please make sure to write the name propedly"<<std::endl;
        return false;
    }
    fileptr = std::make_shared<std::ifstream>(filename);
    if(!ValidFileFormat()){
        std::cout<<"Invalid file format!, This program only has support for .csv, log and .txt files"<<std::endl;
        return false;
    }
    if(!FileFinded()){
        std::cout<<"File not found!, Make sure to write the route and name propedly"<<std::endl;
        return false;
    }
    return true;
}

bool FileHandler::FileFinded(){
    if(fileptr->is_open()){
        std::cout<<"File finded!"<<std::endl;
        return true;
    }
    return false;
}

bool FileHandler::ValidFileFormat(){
    size_t pos = filename.rfind('.');
    format = filename.substr(pos+1);
    std::cout<<"File format: "<<format<<std::endl;
    if(format == "txt" || format == "csv" || format == "log"){
        return true;
    }
    return false;
}

FileHandler::~FileHandler(){
    //nothing
}