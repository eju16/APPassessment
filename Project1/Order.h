//
//  Order.hpp
//  AssessmentTwo
//
//  Created by Elle J Pacumbala on 01/12/2023.
//

#ifndef Order_h
#define Order_h

#include <stdio.h>
#include "ItemList.h"
#include "Menu.h"
#include <iostream>
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"
//#include <vector>

//using namespace std;
//final code
class Order : public ItemList
{
public:
    Order();
    ~Order();
    void printReceipt();
    std::string toString() override;

    void add(int index); //returns recalculated total value
    void remove(int index); //returns recalculated total value
    float calculateTotal();
    bool checkOut();


    float addPrice(float toAdd);
    float removePrice(float toRemove);
    float addSavings(float toAdd);
    float removeSavings(float toRemove);



    bool removeAppetiser(int index);
    bool removeMainCourse(int index);
    bool removeBeverage(int index);

    void clearOrder();

private:
    bool twoForOneAdded = false;
    int counter241 = 0;
    std::vector<Appetiser> appetiserList;
    std::vector<MainCourse> mainCourseList;
    std::vector<Beverage> beverageList;

    float savings; //savings from 241 items
    float totalOrderCost; //total for customer to pay
};
#endif /* Order_hpp */
