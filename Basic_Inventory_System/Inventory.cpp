/**********|**********|**********|
Program: Inventory.cpp
Course: Programming Fundamentals
Year: 2018/19 Trimester 1
Name: Boo Ee Kein Ivan
ID: 1161104032
Lecture Section: TC02
Tutorial Section: TT04
Email: 1161104032@student.mmu.edu.my
Phone: 017-3070870
**********|**********|**********/


//Required libraries for the code to work
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <vector>
#include "StoreItem.h"

using namespace std;

// Declare for main() use
string selection;

//Main user menu of the program, allowing users to select their wished function.
int main()
{
  StoreItem storeitem; //declaring class

        system("cls");
        // CMD interface for the main page of the inventory system
        cout << "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n";
        cout << "WELCOME TO YOUR IT INVENTORY MANAGEMENT PROGRAM\n";
        cout << "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n\n";
        cout << "<1> Insert New Record\n";
        cout << "<2> Update a Record's Data Field\n";
        cout << "<3> Delete a Record\n";
        cout << "<4> Display the Inventory\n";
        cout << "<5> Search Item in Inventory\n";
        cout << "<6> Exit Program\n\n";
        cout << "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n\n\n";
        cout << "Please select the function that you wish to use by entering the NUMBER indicating the function:\n";

        // Logic enabling user to input only valid choices.
        int case_counter=0;
        while(case_counter==0)
        {
            cin >> selection;

            //To check validity of selection input
            if (selection != "1" && selection != "2" && selection !="3" && selection !="4" && selection != "5" && selection != "6")
            {
              cout << "Please re-enter a valid choice! : \n\a";
            }
            else
            {
              case_counter++;
            }
        }
        if(selection == "1")
        {
          storeitem.insert_item(); //call insert_item()
        }
        if(selection == "2")
        {
          storeitem.update_item();//call update_item
        }
        if(selection == "3")
        {
          storeitem.delete_item();//call delete_item
        }
        if(selection == "4")
        {
          storeitem.display_item();//call display_item
        }
        if(selection == "5")
        {
          storeitem.search_item();//call search_item
        }
        if(selection == "6")
        {
          storeitem.exit_program();//call exit_program
        }

 return 0;
}
//End of Main Function
