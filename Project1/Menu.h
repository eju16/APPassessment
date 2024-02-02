//
//  Menu.hpp
//  AssessmentTwo
//
//  Created by Elle J Pacumbala on 01/12/2023.
//

#ifndef Menu_h
#define Menu_h

//#include "Menu.hpp"
#include "ItemList.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//final code
class Menu : public ItemList
{
public:
    Menu(std::string fileName) : ItemList(fileName) {}; //inherits constructor of parent class
    ~Menu();

    std::string toString() override;
    std::vector<std::vector<std::string>> readMenuFile(std::string& fileName);

private:
    std::string fileName;
};

#endif /* Menu_hpp */
