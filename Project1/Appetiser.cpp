//
//  Appetiser.cpp
//  AssessmentTwo
//
//  Created by Elle J Pacumbala on 01/12/2023.
//

#include "Appetiser.h"
//final code
Appetiser::Appetiser() : Item()
{

    appetiserMenuVector = readItemInfo("menu.csv");
    getPosMain(appetiserMenuVector);
};


Appetiser::Appetiser(int itemNo) : Item()
{

    std::vector<std::vector<std::string>> appetiserMenuVector = readItemInfo("menu.csv");

    cleanUpItemInfo();

    itemNo = itemNo - 1; //since vectors start at index 0

    //setting name
    name = appetiserMenuVector[itemNo][1];

    //setting price
    std::string priceString = appetiserMenuVector[itemNo][2];
    float convertedPrice = std::stof(priceString);
    price = convertedPrice;

    //setting calories
    std::string caloriesString = appetiserMenuVector[itemNo][3];
    int convertedCalories = std::stoi(caloriesString);
    calories = convertedCalories;

    //setting shareable and 2-4-1 values ---- EXCLUSIVE TO APPETISERS
    if (appetiserMenuVector[itemNo][3] == "y") //shareable
    {
        sharable = true;
    }
    else if (appetiserMenuVector[itemNo][3] == "n")
    {
        sharable = false;
    }

    if (appetiserMenuVector[itemNo][4] == "y") //2-4-1
    {
        twoForOne = true;
    }
    else if (appetiserMenuVector[itemNo][4] == "n")
    {
        twoForOne = false;
    }

};

void Appetiser::cleanUpItemInfo()
{
    std::vector<std::vector<std::string>> menuToUse = _fullMenu;
    std::vector<std::vector<std::string>> appetiserMenu;

    for (const std::vector<std::string>& row : _fullMenu)
    {
        if (!row.empty() && row[0] == "a")
        {
            std::vector<std::string> newRow;
            for (int i = 1; i < 4 && i < row.size(); ++i)
            {
                std::cout << "row[" << i << "]: " << row[i] << std::endl;
                newRow.push_back(row[i]);
            }
            appetiserMenu.push_back(newRow);
        }
    }

    appetiserMenuVector = appetiserMenu;

}

void Appetiser::toString()
{

    std::cout << name << ": " << "£" << price << ", " << calories << " cal";

    if (!twoForOne) //values are reversed for some reason, so conditions are like this
    {
        std::cout << " (2-4-1)" << std::endl;
    }
    else if (twoForOne)
    {
        std::cout << std::endl;
    }

};

std::string Appetiser::getName()  //issues with using Item's inherited methods with same name
{
    return name;
};

float Appetiser::getPrice()
{
    return price;
};

void Appetiser::getPosMain(std::vector<std::vector<std::string>> menuToUse)
{

    int mainStartPosition = 0;
    int indexPointer = 0;

    for (const auto& ROW : menuToUse)
    {
        for (const auto& CELL : ROW)
        {

            if (CELL == "a")
            {
                indexPointer = indexPointer + 1;
            }
            else if (CELL == "m")
            {
                indexPointer = indexPointer + 1;
                goto endLoop;
            }
        }
    }
endLoop:
    _beginPosMain = mainStartPosition;
};

bool Appetiser::getTwoForOne()
{
    if (twoForOne)
    {
        return true;
    }
    else
    {
        return false;
    }
};

std::string Appetiser::getType()
{
    return type;
}


