//
//  MainCourse.cpp
//  AssessmentTwo
//
//  Created by Elle J Pacumbala on 01/12/2023.
//

#include "MainCourse.h"
//final code
MainCourse::MainCourse() : Item()
{
    mainCourseVector = readItemInfo("menu.csv");
    getMainsPos(mainCourseVector);
}

MainCourse::MainCourse(int itemNo) : Item()
{
    std::vector<std::vector<std::string>> mainCourseVector = readItemInfo("menu.csv");

    _amountOfMains = getMainsPos(mainCourseVector);
    //int _amountOfMains = range;

    cleanUpItemInfo();

    itemNo = itemNo - 1; //change for main courses

    name = mainCourseVector[itemNo][1];


    std::string priceString = mainCourseVector[itemNo][2];
    float convertedPrice = std::stof(priceString);
    price = convertedPrice;


    std::string caloriesString = mainCourseVector[itemNo][3];
    int convertedCalories = std::stoi(caloriesString);
    calories = convertedCalories;
}

int MainCourse::getMainsPos(std::vector<std::vector<std::string>> menuToUse)
{
    //for when adding item to order since full menu position != only mains menu position
    int vectorSize = menuToUse.size();
    bool firstMain = false;
    int mainStartPosition = 0;
    int mainEndPosition = vectorSize;
    int indexPointer = 0;

    for (const auto& ROW : menuToUse)
    {
        for (const auto& CELL : ROW)
        {
            if (CELL == "a")
            {
                indexPointer = indexPointer + 1;
            }
            else if (CELL == "m" && !firstMain)
            {
                firstMain = true;

                mainStartPosition = indexPointer;

                indexPointer = indexPointer + 1;

            }
            else if (CELL == "m")
            {
                indexPointer = indexPointer + 1;

            }
            else if (CELL == "b") //bev indication means end of mains
            {
                mainEndPosition = indexPointer;
                goto endLoop;
            }
        }
    }
endLoop:
    mainEndPosition = mainEndPosition - 1;
    int _amountOfMains = mainEndPosition - mainStartPosition;
    _beginPos = mainStartPosition;
    _endPos = mainEndPosition;

    clearArray(menuToUse);

    return _amountOfMains;
};

void MainCourse::toString()
{
    std::cout << name << ": " << "£" << price << ", " << calories << " cal\n";
};

void MainCourse::cleanUpItemInfo()
{
    for (const std::vector<std::string>& row : _fullMenu)
    {
        if (!row.empty() && row[0] == "m")
        {
            std::vector<std::string> newRow;
            for (int i = 1; i < 3 && i < row.size(); ++i)
            {
                //std::cout << "row[" << i << "]: " << row[i] << std::endl;
                newRow.push_back(row[i]);
            }
            mainCourseVector.push_back(newRow);
        }
    }
};

std::string MainCourse::getName()
{
    return name;
}

float MainCourse::getPrice()
{
    return price;
}

std::string MainCourse::getType()
{
    return type;
}


