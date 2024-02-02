//
//  ItemList.hpp
//  AssessmentTwo
//
//  Created by Elle J Pacumbala on 01/12/2023.

//PARENT CLASS

#ifndef ItemList_h
#define ItemList_h


#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
//#include "Menu.hpp"
//using namespace std;
//final code
class ItemList
{
public:
    ItemList() {};
    ItemList(std::string fileName);
    virtual std::string toString() = 0;
    std::vector<std::vector<std::string>> readItemListFile(std::string& fileName);
    ~ItemList() {};

    std::vector<std::vector<std::string>> _csvMenu;
private:
    std::vector<std::vector<std::string>> listOfItems;
    std::string items;
};
#endif /* ItemList_hpp */
