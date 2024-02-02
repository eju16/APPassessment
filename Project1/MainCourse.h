//
//  MainCourse.hpp
//  AssessmentTwo
//
//  Created by Elle J Pacumbala on 01/12/2023.
//

#ifndef MainCourse_h
#define MainCourse_h

#include <stdio.h>
#include "Item.h"
//final code
class MainCourse : public Item
{
public:
    std::vector<std::vector<std::string>> mainCourseVector;
    int _amountOfMains;
    int _beginPos;
    int _endPos;

    MainCourse();
    MainCourse(int itemNo);
    ~MainCourse() {};

    void toString() override;
    void cleanUpItemInfo() override;
    int getMainsPos(std::vector<std::vector<std::string>> menuToUse);

    //getters
    std::string getName();
    float getPrice();
    std::string getType();

private:
    std::string type = "m";
    std::string name;
    float price;
    int calories;
};
#endif /* MainCourse_hpp */
