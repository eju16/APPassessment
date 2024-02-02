//
//  Beverage.hpp
//  AssessmentTwo
//
//  Created by Elle J Pacumbala on 01/12/2023.
//

#ifndef Beverage_h
#define Beverage_h

#include <stdio.h>
#include "Item.h"
#include <iostream>

//using namespace std;
//final code
class Beverage : public Item
{
public:
    std::vector<std::vector<std::string>> bevVector;
    int _amountOfBevs;
    int _beginPos;
    int _endPos;

    Beverage();
    Beverage(int itemNo);
    ~Beverage() {};

    void toString() override;
    void cleanUpItemInfo() override;
    int getBevsPos(std::vector<std::vector<std::string>> menuToUse);

    //getters
    std::string getName();
    float getPrice();
    std::string getType();
    bool isAlcoholic();

private:
    std::string type = "b";
    std::string name;
    float price;
    int calories;
    int volume;
    float abv;

    bool alcoholic;

};
#endif /* Beverage_hpp */
