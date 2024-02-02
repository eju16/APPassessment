//
//  Item.hpp
//  AssessmentTwo
//
//  Created by Elle J Pacumbala on 01/12/2023.

//PARENT CLASS
//final code
#ifndef Item_h
#define Item_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


class Item
{
public:
    Item() {}; //constructor
    Item(std::string fileName);
    ~Item() {}; //destructor
    std::vector<std::vector<std::string>> readItemInfo(const std::string& fileName);


    void clearArray(std::vector<std::vector<std::string>> menu);
    std::string getName();
    float getPrice();
    virtual void toString() = 0;

    virtual void cleanUpItemInfo() = 0;
    std::vector<std::vector<std::string>> _fullMenu;

private: //attributes
    int calories;
    std::string name;
    float price;

};


#endif /* Item_hpp */
