//
//  ItemList.cpp
//  AssessmentTwo
//
//  Created by Elle J Pacumbala on 01/12/2023.
//

#include "ItemList.h"
//final code
ItemList::ItemList(std::string fileName)
{
    _csvMenu = readItemListFile(fileName); //constructor uses readItemListFile method
}

std::vector<std::vector<std::string>> ItemList::readItemListFile(std::string& fileName)
{
    std::ifstream fin;
    std::vector<std::vector<std::string>> itemList;
    std::string line;

    //std::string absolutePath = std::filesystem::absolute(fileName).string();
    //absolutePath = "/Users/lj/Library/CloudStorage/OneDrive-UniversityofLincoln/SecondYear/Programming Paradigms/copy of assessment/AssessmentTwo/AssessmentTwo/menu.csv";
    //absolutePath = "/Users/lj/Library/CloudStorage/OneDrive-UniversityofLincoln/SecondYear/Programming Paradigms/Assessment/AssessmentTwo/AssessmentTwo/menu.csv";
    fin.open(fileName, std::ios::in);

    if (!fin.is_open()) {
        std::cerr << "Error opening file: " << fileName << ". Possible reasons: file does not exist, incorrect path, or insufficient permissions." << std::endl;
        return {};
    }

    while (getline(fin, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());

        std::istringstream sstream(line);
        std::vector<std::string> row;
        std::string cell;

        while (getline(sstream, cell, ',')) {
            row.push_back(cell);
        }

        itemList.push_back(row);
    }

    fin.close();
    return itemList;
}


