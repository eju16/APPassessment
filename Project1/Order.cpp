//
//  Order.cpp
//  AssessmentTwo
//
//  Created by Elle J Pacumbala on 01/12/2023.
//

#include "Order.h"


//final code
Order::Order() {
    //Constructor
}

void Order::printReceipt()
{
    std::cout << "-----Order------\n";
    for (auto& item : appetiserList)
    {
        item.toString();
    }
    for (auto& item : mainCourseList)
    {
        item.toString();
    }
    for (auto& item : beverageList)
    {
        item.toString();
    }

    std::cout << "---------------\nSavings: £" << savings << "\nTotal: £" << totalOrderCost << "\n";
};

std::string Order::toString()
{
    /***
    std::string orderString = "";
    orderString += "-----Order------\n";
    //std::cout << "-----Order------\n";
    for (auto& item : appetiserList)
        {
        orderString = orderString + item.toString() + "\n";
        //item.toString();
        }
    for (auto& item : mainCourseList)
        {
        orderString = orderString + item.toString() + "\n";
        //item.toString();
        }
    for (auto& item : beverageList)
        {
        orderString = orderString + item.toString() + "\n";
        //item.toString();
        }

    orderString = orderString + "---------------\nSavings: \nTotal: " << totalOrderCost << "\n";
    //std::cout << "---------------\nSavings: \nTotal: " << totalOrderCost << "\n";

    return orderString;
     **/
    return "";
};


void Order::add(int index)
{

    //means this won't work for any menu, just this specific one, unless it has same amounts of appetisers/mains/beverages
        //but can be changed to use size of each list to calculate/figure out how much items are in each for the menu
    int _mainStart = 4;
    int _bevStart = 8;
    int _bevEnd = 12;

    //need to make items get pushed to a order vector
    if (index > 0 && index < _mainStart)
    {
        Appetiser appItem = Appetiser(index);

        if (!appItem.getTwoForOne()) //twoForOne values are reversed for some reason, so 0=241 included, 1=241 not included.
        {

            if (counter241 % 2 == 0)
            {

                std::cout << "\nAdding " << appItem.getName() << "." << std::endl;
                appetiserList.push_back(appItem);
                totalOrderCost = addPrice(appItem.getPrice());
                //add price
                counter241 = counter241 + 1;


            }

            else if (counter241 % 2 == 1)
            {
                //should just push the item without adding onto the price

                std::cout << "\nAdding " << appItem.getName() << "." << std::endl;
                appetiserList.push_back(appItem);
                savings = addSavings(appItem.getPrice());
                //push item but don't add price
                //add instead to savings
                //reset counter to 0
                counter241 = counter241 + 1;
            }
        }
        else //add item as normal if not included in 2-4-1
        {
            std::cout << "\nAdding " << appItem.getName() << "." << std::endl;
            appetiserList.push_back(appItem);
            totalOrderCost = addPrice(appItem.getPrice());
        }
    }

    else if (index >= _mainStart && index < _bevStart) //for mains
    {

        MainCourse mainItem = MainCourse(index);
        std::cout << "\nAdding " << mainItem.getName() << "." << std::endl;
        mainCourseList.push_back(mainItem);
        totalOrderCost = addPrice(mainItem.getPrice());
    }

    else if (index >= _bevStart && index <= _bevEnd) //for beverages
    {
        Beverage bevItem = Beverage(index);
        std::cout << "\nAdding " << bevItem.getName() << "." << std::endl;
        beverageList.push_back(bevItem);
        totalOrderCost = addPrice(bevItem.getPrice());
    }

    else //for invalid inputs
    {
        std::cout << "Invalid item no." << std::endl;
    }

};

void Order::remove(int index)
{
    //int _mainStart = 4;
   // int _bevStart = 8;
    //int _bevEnd = 12;

    index = index - 1;
    int appSize = appetiserList.size();

    int mainSize = mainCourseList.size();

    int bevSize = beverageList.size();


    if (index >= 0 && index < appSize && appSize != 0)
    {
        if (!appetiserList[index].getTwoForOne()) //twoForOne values are reversed for some reason, so 0=241 included, 1=241 not included.
        {
            if (counter241 % 2 == 0 && counter241 > 0) //two 241 items -> 1 item removed
            {
                std::cout << "IN REMOVE, COUNTER241 = 0" << std::endl;

                removeAppetiser(index);

                //just remove item as normal

                savings = removeSavings(appetiserList[index].getPrice());
                counter241 = counter241 - 1;
            }

            else if (counter241 % 2 == 1) //
            {
                bool removeFlag = removeAppetiser(index);

                if (removeFlag)
                {
                    totalOrderCost = removePrice(appetiserList[index].getPrice());
                    counter241 = counter241 - 1;
                }
                else
                {
                    //std::cout << "error msg rem counter241= 1"<< std::endl;
                }
                //savings = removeSavings(appItem.getPrice());
                //push item but don't add price
                //add instead to savings
                //reset counter to 0
                //counter241 = 0;
            }
        }
        else
        {
            bool removeFlag = removeAppetiser(index); //flag checks if the items in the list to allow price to be adjusted

            if (removeFlag)
            {
                totalOrderCost = removePrice(appetiserList[index].getPrice());
            }
            else
            {
                std::cout << "remove price app error msg" << std::endl;
            }
            //totalOrderCost = removePrice(appItem.getPrice());
        }

    }
    else if (index >= appSize && index <= appSize + mainSize && mainSize != 0)
    {
        float toRemove = mainCourseList[index].getPrice();

        bool removeFlag = removeMainCourse(index);

        if (removeFlag)
        {
            totalOrderCost = removePrice(mainCourseList[index].getPrice());
        }
        else
        {
            //std::cout << "remove price main error msg" << std::endl;
        }
        //totalOrderCost = removePrice(mainItem.getPrice());
    }
    else if (index >= appSize + mainSize && index <= appSize + mainSize + bevSize && bevSize != 0)
    {
        bool removeFlag = removeBeverage(index);

        if (removeFlag)
        {
            totalOrderCost = removePrice(beverageList[index].getPrice());
        }
        else
        {
            std::cout << "remove price bev error msg" << std::endl;
        }
        //totalOrderCost = removePrice(bevItem.getPrice());
    }
};

float Order::addPrice(float toAdd)
{
    totalOrderCost = totalOrderCost + toAdd;
    return totalOrderCost;
};

float Order::removePrice(float toRemove)
{
    totalOrderCost = totalOrderCost - toRemove;
    return totalOrderCost;
};

float Order::addSavings(float toAdd)
{
    savings = savings + toAdd;
    return savings;
};

float Order::removeSavings(float toRemove)
{
    savings = savings - toRemove;
    return savings;
};

bool Order::checkOut() //true = paid, false = unpaid
{
    bool checkoutResult = false;

    while (true)
    {
        std::string input = "";
        std::cout << "Would you like to checkout? y/n\n> ";
        std::cin >> input;

        if (input == "y")
        {

            printReceipt();

            checkoutResult = true;
            break;

        }
        else if (input == "n")
        {

            std::cout << "Continuing with order...\n" << std::endl;

            checkoutResult = false;
            break;
        }
        else
        {
            std::cout << "Invalid or unexpected input, try again.\n" << std::endl;

        }
    }

    return checkoutResult;

};


void Order::clearOrder()
{
    //resetting all vectors and attributes/order details
    appetiserList.clear();
    mainCourseList.clear();
    beverageList.clear();
    savings = 0.0f;
    totalOrderCost = 0.0f;
    twoForOneAdded = false;
    counter241 = 0;
}

bool Order::removeAppetiser(int index)
{

    index = index - 1;
    //std::cout << "index in remove appetiser: " << index << std::endl;
    if (index >= 0 && index < appetiserList.size())
    {
        std::cout << "\nRemoving " << appetiserList[index].getName() << "." << std::endl;

        appetiserList.erase(appetiserList.begin() + index);

        return true;
    }
    else
    {
        std::cout << "Invalid index. Unable to remove item.\n";
        return false;
    }
};

bool Order::removeMainCourse(int index)
{
    //converting index from whole order to index for mainCourseList
    index = index - appetiserList.size() -1;


    if (index >= 0 && index < mainCourseList.size())
    {
        std::cout << "\nRemoving " << mainCourseList[index].getName() << "." << std::endl;

        //remove the item at the specified index
        mainCourseList.erase(mainCourseList.begin() + index);
        return true;
    }
    else
    {
        std::cout << "Invalid index. Unable to remove item.\n";
        return false;
    }
};

bool Order::removeBeverage(int index)
{
    index = index - appetiserList.size() - mainCourseList.size()-1;
    //std::cout << "index in remove bev: " << index << std::endl;
    if (index >= 0 && index < beverageList.size())
    {
        std::cout << "\nRemoving " << beverageList[index].getName() << "." << std::endl;

        //remove the item at the specified index
        beverageList.erase(beverageList.begin() + index);
        return true;
    }
    else
    {
        std::cout << "Invalid index. Unable to remove item.\n";
        return false;
    }
};


Order::~Order()
{
    clearOrder();
}
