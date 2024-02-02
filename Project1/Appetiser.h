//
//  Appetiser.hpp
//  AssessmentTwo
//
//  Created by Elle J Pacumbala on 01/12/2023.
//

#ifndef Appetiser_h
#define Appetiser_h

#include "Item.h"
#include <stdio.h>
#include <string>

//final code
class Appetiser : public Item
{
public:
    Appetiser();
    Appetiser(int itemNo);
    ~Appetiser() {};

    void toString() override;
    void cleanUpItemInfo() override;
    void getPosMain(std::vector<std::vector<std::string>> menuToUse);
    std::vector<std::vector<std::string>> appetiserMenuVector;

    //getters
    std::string getName();
    float getPrice();
    bool getTwoForOne();
    std::string getType();

    int _beginPosMain;

private:
    std::string type = "a";
    std::string name;
    float price;
    int calories;
    bool sharable; //in csv, y or n
    bool twoForOne = false; //in csv y or n
};

#endif /* Appetiser_hpp */
