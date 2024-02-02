//
//  Item.cpp
//  AssessmentTwo
//
//  Created by Elle J Pacumbala on 01/12/2023.
//

#include "Item.h"
//final code
Item::Item(std::string fileName) //constructor
{
    _fullMenu = readItemInfo(fileName);
}

std::string Item::getName()
{
    return name;
}

float Item::getPrice()
{
    return price;
}

std::vector<std::vector<std::string>> Item::readItemInfo(const std::string& fileName)
{
    std::ifstream fin;
    std::vector<std::vector<std::string>> itemList;
    std::string line;

    //std::string absolutePath = std::filesystem::absolute(fileName).string();

    //absolutePath = "/Users/lj/Library/CloudStorage/OneDrive-UniversityofLincoln/SecondYear/Programming Paradigms/copy of assessment/AssessmentTwo/AssessmentTwo/menu.csv"; //will need to be changed

    fin.open(fileName, std::ios::in);

    if (!fin.is_open()) {
        std::cerr << "Error opening file: " << fileName << ". Possible reasons: file does not exist, incorrect path, or insufficient permissions." << std::endl;
        return {};
    }

    //reading lines from input and stores in itemList
    while (getline(fin, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end()); //for windows
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end()); //for mac (uses \r instead of \n)

        std::istringstream sstream(line);
        std::vector<std::string> row;
        std::string cell;

        while (getline(sstream, cell, ',')) //splits at commas, used in csv file
        {
            row.push_back(cell);
        }

        itemList.push_back(row);
    }

    fin.close();
    return itemList;
}

void Item::clearArray(std::vector<std::vector<std::string>> menu)
{
    for (auto& ROW : menu)
    {
        ROW.clear();
    }
    menu.clear();
};
