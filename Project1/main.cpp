#define _CRT_SECURE_NO_WARNINGS


#include "Menu.h"
#include "Order.h"
#include "Item.h"
#include "Appetiser.h"
#include "MainCourse.h"

#include <iostream>
#include <vector>
#include <cstring>

//final code
int main()
{
    std::string userCommand;
    std::vector <std::string> parameters;
    bool exitProgram = false;

    // Create a menu object from a CSV file
    Menu menu = Menu("menu.csv");

    // Create an order object
    Order order = Order();

    std::cout << "Type 'help' to see list of commands." << std::endl;

    while (!exitProgram)
    {

        std::cout << "Enter command\n> ";
        getline(std::cin, userCommand);

        if (userCommand == "exit")
        {
            exitProgram = true; // Set the flag to exit the program
        }
        else
        {
            char* cstr = new char[userCommand.length() + 1];
            strcpy(cstr, userCommand.c_str());

            char* token;
            token = strtok(cstr, " ");

            while (token != NULL)
            {
                parameters.push_back(token);
                token = strtok(NULL, " ");
            }

            std::string command = parameters[0];

            if (command.compare("menu") == 0) {
                std::cout << menu.toString(); //output the menu

            }
            else if (command.compare("add") == 0)
            {

                int itemNo;
                std::cout << "Enter item(s) no.\n> ";
                std::cin >> itemNo;

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clears initial input to prevent 'add' code looping


                order.add(itemNo);

                order.printReceipt();



            }
            else if (command.compare("remove") == 0)
            {

                int itemNo;
                std::cout << "Enter item(s) no.\n> ";
                std::cin >> itemNo;



                order.remove(itemNo);

                order.printReceipt();

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            }
            else if (command.compare("checkout") == 0)
            {

                bool paid = order.checkOut(); //assuming when checking out, the order gets paid (no code for making payment)

                order.printReceipt();

                if (paid)
                {

                    order.clearOrder(); //reset order
                    paid = false; //resets value
                }

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clears input
            }
            else if (command.compare("help") == 0)
            {
                //outputting list of commands with short description
                std::cout << "\n------------------\nList of commands:\nmenu\t\tDisplays the menu.\nadd\t\tAdd a single item\nremove\t\tRemove the item in the list by its position in the order list.\ncheckout\t\tCalculates order and creates receipt.\nhelp\t\tView commands.\nexit\t\tExit.\n------------------\n";
            }

            parameters.clear();
        }

    }


    std::cout << "Press any key to quit...";
    std::getchar();

}
