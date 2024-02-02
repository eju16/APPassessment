//
//  Beverage.cpp
//  AssessmentTwo
//
//  Created by Elle J Pacumbala on 01/12/2023.
//

#include "Beverage.h"
//final code
Beverage::Beverage()
{

};

Beverage::Beverage(int itemNo) : Item()
{
    std::vector<std::vector<std::string>> bevVector = readItemInfo("menu.csv");

    _amountOfBevs = getBevsPos(bevVector);

    cleanUpItemInfo();

    itemNo = itemNo - 1;

    name = bevVector[itemNo][1];

    //setting price
    std::string priceString = bevVector[itemNo][2];
    float convertedPrice = std::stof(priceString);
    price = convertedPrice;

    //setting calories
    std::string caloriesString = bevVector[itemNo][3];
    int convertedCalories = std::stoi(caloriesString);
    calories = convertedCalories;

    //setting volume ----bev exclusive
    std::string volumeString = bevVector[itemNo][6];
    int convertedVolume = std::stoi(volumeString);
    volume = convertedVolume;

    //setting abv ----bev exclusive
    std::string abvString = bevVector[itemNo][7];
    float convertedAbv = std::stof(abvString);
    abv = convertedAbv;
};

bool Beverage::isAlcoholic()
{
    if (abv > 0)
    {
        alcoholic = true;
    }
    else
    {
        alcoholic = false;
    }
    return alcoholic;
};

int Beverage::getBevsPos(std::vector<std::vector<std::string>> menuToUse)
{

    int vectorSize = menuToUse.size();
    bool firstBev = false;
    int mainStartPosition = 0;
    int mainEndPosition = vectorSize;
    int indexPointer = 0;

    for (const auto& ROW : menuToUse)
    {
        for (const auto& CELL : ROW)
        {
            //std::cout << "OUTSIDE CELL: " << CELL << std::endl;
            if (CELL == "a")
            {
                indexPointer = indexPointer + 1;
            }
            else if (CELL == "b" && !firstBev)
            {
                firstBev = true;
                //std::cout << CELL << std::endl;
                mainStartPosition = indexPointer;
                //std::cout << "inside m if: " << mainStartPosition << std::endl;

                //std::cout << "before increment: " << indexPointer << std::endl;
                indexPointer = indexPointer + 1;
                //std::cout << "after increment: " << indexPointer << std::endl;
            }
            else if (CELL == "b")
            {
                indexPointer = indexPointer + 1;
            }
        }
    }
endLoop:
    mainEndPosition = mainEndPosition - 1;
    int _amountOfBevs = mainEndPosition - mainStartPosition;
    _beginPos = mainStartPosition;
    _endPos = mainEndPosition;

    return _amountOfBevs;
};

void Beverage::toString()
{
    std::cout << name << ": " << "£" << price << ", " << calories << " cal, " << volume << " ml, " << abv << " ABV\n";
};

void Beverage::cleanUpItemInfo()
{
    for (const std::vector<std::string>& row : _fullMenu)
    {
        if (!row.empty() && row[0] == "b")
        {
            std::vector<std::string> newRow;
            for (int i = 1; i < 7 && i < row.size(); ++i)
            {
                newRow.push_back(row[i]);
            }
            bevVector.push_back(newRow);
        }
    }

};

std::string Beverage::getName()
{
    return name;
}

float Beverage::getPrice()
{
    return price;
}

std::string Beverage::getType()
{
    return type;
}
