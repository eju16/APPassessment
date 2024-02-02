//
//  Menu.cpp
//  AssessmentTwo
//
//  Created by Elle J Pacumbala on 01/12/2023.
//

#include "Menu.h"

//uses ItemList's constructor
//final code
std::string Menu::toString()
{
    //cout << "running to string\n";
    std::vector<std::vector<std::string>> menuToUse = this->_csvMenu; //csvMenu is empty
    //const int ROW_INDEX = 0;
    int innerPointer = 0;
    int outerPointer = 0;
    bool isAppetiser = false;
    bool isMain = false;
    bool isDrink = false;


    std::cout << "--------------" << std::endl;

    std::string concatenatedMenu = "";
    std::cout << "Type\t\t\t| Name\t\t| Price\t\t| Calories\t| Shareable\t| 2-4-1\t| Volume(ml)\t| Alcohol by Volume (ABV)" << std::endl;
    std::cout << "------------------------------------------------------------------------------------------------------------" << std::endl;


    for (const auto& ROW : menuToUse)
    {
        innerPointer = 0;
        isAppetiser = false; //reset values
        isMain = false;
        isDrink = false;

        for (const auto& CELL : ROW)
        {
            if (innerPointer == 0) //appetiser/main/beverage
            {
                if (CELL == "a")
                {
                    concatenatedMenu += "Appetiser: \t\t";
                    isAppetiser = true;
                }
                else if (CELL == "m")
                {
                    concatenatedMenu += "Main: \t\t\t";
                    isMain = true;
                }
                else if (CELL == "b")
                {
                    concatenatedMenu += "Beverage: \t\t";
                    isDrink = true;
                }
            }
            else if (innerPointer == 1) //item name
            {
                concatenatedMenu = concatenatedMenu + " (" + std::to_string(outerPointer + 1) + ") " + CELL + ", ";
            }
            else if (innerPointer == 2) //price
            {
                concatenatedMenu = concatenatedMenu + "£" + CELL + ", ";
            }

            else if (innerPointer == 3) //calories
            {
                if (isMain)
                {
                    concatenatedMenu = concatenatedMenu + CELL + " cal\n\n"; //goes new line for next item
                }
                else
                {
                    concatenatedMenu = concatenatedMenu + CELL + " cal, ";
                }
            }

            else if (innerPointer == 4) //shareable
            {

                if (CELL == "y" && isAppetiser)
                {
                    concatenatedMenu = concatenatedMenu + "(Shareable)\n\n"; //appetisers have values for 2-4-1, so new line not needed yet
                }
            }

            else if (innerPointer == 5 && isAppetiser) //two for one
            {
                //if (CELL.empty())
                //{
                    //concatenatedMenu = concatenatedMenu + "- , "; //+ CELL;
                //}
                if (CELL == "y" && isAppetiser)
                {
                    concatenatedMenu = concatenatedMenu + "2-4-1\n\n";
                }
            }

            else if (innerPointer == 6 && isDrink) //drink volume
            {
                if (CELL.empty())
                {
                    concatenatedMenu = concatenatedMenu + "- , ";
                }
                else
                {
                    concatenatedMenu = concatenatedMenu + " (" + CELL + "ml, ";
                }
            }

            else if (innerPointer == 7 && isDrink)
            {
                if (CELL.empty())
                {
                    concatenatedMenu = concatenatedMenu + "-\n";
                }
                else if (CELL >= "0")
                {
                    concatenatedMenu = concatenatedMenu + CELL + " ABV)\n\n";
                }
            }
            innerPointer = innerPointer + 1;
        }
        outerPointer = outerPointer + 1;
    }
    return concatenatedMenu;
};

Menu::~Menu()
{

}



