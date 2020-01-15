/**********|**********|**********|
Program: StoreItem.cpp
Course: Programming Fundamentals
Year: 2018/19 Trimester 1
Name: Boo Ee Kein Ivan
ID: 1161104032
Lecture Section: TC02
Tutorial Section: TT04
Email: 1161104032@student.mmu.edu.my
Phone: 017-3070870
**********|**********|**********/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <vector>
#include <algorithm>
#include "StoreItem.h"

using namespace std;

//Global Variables//
string ID, Item_ID, Name, Description, Category, Manufacturer, exit_option, restart_func_option;
int YearIntro, MonthIntro, DayIntro, Units_Store, Units_Sold, option;
float SellPrice, CostPrice;

string StoreItem::Lowercase(string text)
{
	for (int i = 0; i < text.length();i++)
	{
		text[i] = tolower(text[i]); //make letters to lowercase
  }
	return text;
}

int StoreItem::Find(string A, string B)
{
	A = Lowercase(A);
	B = Lowercase(B);

	for (int i = 0; i <= A.size() - B.size(); ++i) //loop to find a letter in a word
	{
		if (A.substr(i, B.size()) == B)
			return i;
	}

	return -1;
}

void StoreItem::insert_item() // insert_item() Fuction (To insert a new item in inventory)
{
  system("cls");
  //Local variables for insert_item() function
  string Item_ID, Item_Name, Item_Manufacturer, Item_Description, Item_Category, Item_sellprice, Item_costprice,
  Item_units_stored, Item_units_sold,Item_year_intro, Item_month_intro, Item_day_intro;
  int counter=0;
  bool item_id_valid, exist=true;

	//initializing input and output for inventory.txt
	ofstream DataIn;
  ifstream read;
  DataIn.open("inventory.txt",std::ios::app);
  read.open("inventory.txt", std::ios::app);

  //initialzing vector
  vector<string> ItemList;
  //***Reading inventory.txt into the vector file***
  string item;
  while (getline(read,item))
  {
    stringstream ss(item);

    while (getline(ss, item,','))
    {
      ItemList.push_back(item);
    }
  }
	//


  //Loop for user to input the data fields for an item
  while(!item_id_valid)
  {
		cout <<"--------------------------------------\n";
    cout << "<<< TO INSERT A NEW RECORD >>>\n";
		cout <<"--------------------------------------\n\n";

    cout << "Please enter the Item ID:\n";
    cin >> Item_ID;

    for(int i=0; i < ItemList.size(); i+=12) //To check if Item ID exist in the inventory.txt
    {
      if (ItemList[i] == Item_ID)
      {
        cout << "\nItem ID exist! Please try again!\n\n\a";
        exist = false;
      }
    }

    if(!exist)
    {
      break;
    }

		//getting new inputs of data fields from the user
    cout << " \n";
    cout << "Please enter the Item Name:\n";
    cin.ignore();
    getline(cin, Item_Name);
    cout << " \n";
    cout << "Please enter the Item Description:\n";
    getline(cin, Item_Description);
    cout << " \n";
    cout << "Please enter the Category:\n";
    getline(cin, Item_Category);
    cout << " \n";
    cout << "Please enter the Manufacturer:\n";
    getline(cin, Item_Manufacturer);
    cout << "\n";
    cout << "Please enter the Selling Price:\n";
    cin >> Item_sellprice;
    cout << " \n";
    cout << "Please enter the Cost Price:\n";
    cin >> Item_costprice;
    cout << " \n";
    cout << "Please enter the Unit(s) in Store:\n";
    cin >> Item_units_stored;
    cout << " \n";
    cout << "Please enter the Unit(s) sold:\n";
    cin >> Item_units_sold;
    cout << " \n";
    cout << "Please enter the Year of Date First Introduced:\n";
    cin >> Item_year_intro;
    cout << " \n";
    cout << "Please enter the Month of Date First Introduced:\n";
    cin >> Item_month_intro;
    cout << " \n";
    cout << "Please enter the Day of the Date First Introduced:\n";
    cin >> Item_day_intro;
    cout << " \n\n";


		//Reading all the data fields into the inventory.txt
    DataIn << Item_ID << ","<< Item_Name << "," << Item_Description << "," << Item_Category << ","<< Item_Manufacturer
            <<"," << Item_sellprice << "," << Item_costprice << "," << Item_units_stored << "," << Item_units_sold
            << "," << Item_year_intro << "," << Item_month_intro << "," << Item_day_intro << "," << endl;

  cout << "Item successfully saved!\n\n\a";
  item_id_valid = true;
  }



  DataIn.close();
  read.close();
  cout << "Do you wish to go back to the main page or exit the program?\nEnter 'y' to go back to main page, 'n' to quit the program.\n";

  //Loop for user to choose if user wants to restart main() function
  while(counter==0)
  {
      cin >> exit_option;

      if(exit_option == "y")
      {
        main();
        counter++;
      }

      else if (exit_option == "n")
      {
        exit_program();
        counter++;
      }

      else
      {
        cout << "Please enter a valid choice!\n\n";
      }
  }
}
// End of insert_item() function

void StoreItem::update_item() // function fo user to update an item's data field without changing the ID
{
  // Local Variables
  system("cls");
  string Item_ID, Item_Name, Item_Manufacturer, Item_Description, Item_Category, item_to_update, Valitem_to_update,Item_sellprice, Item_costprice,
  Item_units_stored, Item_units_sold,Item_year_intro, Item_month_intro, Item_day_intro;
  int  counter=0, counter2=0;
  bool item_exist = false;
  ofstream readin;
  ifstream readout;


  while(!item_exist)
  {
    readin.open("update.txt",std::ios::app);
    readout.open("inventory.txt", std::ios::app);

    //initialzing vector
    vector<string> ItemList;
    //***Reading inventory.txt into the vector file***
    string item;
    while (getline(readout,item))
    {
      stringstream ss(item);

      while (getline(ss, item,','))
      {
        ItemList.push_back(item);
      }
    }

		cout <<"--------------------------------------\n";
    cout << "<<< TO UPDATE A RECORD >>>\n";
		cout <<"--------------------------------------\n\n";
    cout << "Would you like to -->\n"
    << "<1> Update an entire record\n"
    << "<2> Update a selected data field of a record\n\n"
    <<"Please choose a function:\n";

    int choice;
    cin >> choice;

    //if choice not in function, then it will exit
    if(choice < 1 || choice > 2)
    {
      cout << "Invalid Choice!\n\a\n";
      cout << "Returning to the main menu...\n";
      system("PAUSE");
      main();
    }

    if(choice == 1)
    {
      cout << "Please enter the Item ID:\n";
      cin >> Item_ID;

      for(int i=0; i<ItemList.size(); i+=12)
      {
        if(ItemList[i] == Item_ID)
        {
					//getting inputsof data field from user
          cout << "\nPlease enter the Item Name:\n";
          cin.ignore();
          getline(cin, Item_Name);
          cout << " \n";
          cout << "Please enter the Item Description:\n";
          getline(cin, Item_Description);
          cout << " \n";
          cout << "Please enter the Category:\n";
          getline(cin, Item_Category);
          cout << " \n";
          cout << "Please enter the Manufacturer:\n";
          getline(cin, Item_Manufacturer);
          cout << "\n";
          cout << "Please enter the Selling Price:\n";
          cin >> Item_sellprice;
          cout << " \n";
          cout << "Please enter the Cost Price:\n";
          cin >> Item_costprice;
          cout << " \n";
          cout << "Please enter the Unit(s) in Store:\n";
          cin >> Item_units_stored;
          cout << " \n";
          cout << "Please enter the Unit(s) sold:\n";
          cin >> Item_units_sold;
          cout << " \n";
          cout << "Please enter the Year of Date First Introduced:\n";
          cin >> Item_year_intro;
          cout << " \n";
          cout << "Please enter the Month of Date First Introduced:\n";
          cin >> Item_month_intro;
          cout << " \n";
          cout << "Please enter the Day of the Date First Introduced:\n";
          cin >> Item_day_intro;
          cout << " \n\n";

          ItemList[i+1] = Item_Name;
          ItemList[i+2] = Item_Description;
          ItemList[i+3] = Item_Category;
          ItemList[i+4] = Item_Manufacturer;
          ItemList[i+5] = Item_sellprice;
          ItemList[i+6] = Item_costprice;
          ItemList[i+7] = Item_units_stored;
          ItemList[i+8] = Item_units_sold;
          ItemList[i+9] = Item_year_intro;
          ItemList[i+10] = Item_month_intro;
          ItemList[i+11] = Item_day_intro;

          cout << "Item succesfully updated! \n";
          item_exist = true;
        }
      }

      for(int i=0; i < ItemList.size(); i++) //saving the data into the save file
      {
        readin << ItemList[i] << ",";
      }

			//closing the file and establishing the new inventory file
      readin.close();
      readout.close();
      remove("inventory.txt");
      rename("update.txt","inventory.txt");
    }

    if(choice == 2)
    {
        cout << "Please enter the Item ID that you want to update:\n";
        cin >> item_to_update;

        cout << "Please choose which data field do you want to update?\n\n";
        cout << "<1> Item Name\n";
        cout << "<2> Item Description\n";
        cout << "<3> Item Category\n";
        cout << "<4> Manufacturer\n";
        cout << "<5> Selling Price\n";
        cout << "<6> Cost Price\n";
        cout << "<7> Units in store\n";
        cout << "<8> Units sold\n";
        cout << "<9> Year of Date first introduced\n";
        cout << "<10> Month of Date first introduced\n";
        cout << "<11> Day of Date first introduced\n";
        cin >> choice;

        //if choice not in function, then it will exit
        if(choice < 1 || choice > 11)
        {
          cout << "Invalid Choice!\n\a\n";
          cout << "Returning to the main menu...\n";
          system("PAUSE");
          main();
        }

        cout << "\n Please input a new value:";
        cin >> Valitem_to_update;

        for(int i = 0; i < ItemList.size(); i+=12)
        {
          if (item_to_update == ItemList[i])
          {
            ItemList[i+choice] = Valitem_to_update;
            cout << "Item succesfully updated! \n";
            item_exist = true;
          }
        }

        for(int i = 0; i < ItemList.size(); i++)//saving the data into the save file
        {
          readin << ItemList[i] << ",";
        }

        readin.close();
        readout.close();
        remove("inventory.txt");
        rename("update.txt","inventory.txt");
    }
    break;
  }

  if(!item_exist)
  {
    cout << "Item does not exist!\n\n";
  }


   //prompt user tochoose to return to main() or exit the program
  cout << "\nDo you wish to go back to the main page or exit the program? Enter 'y' to go back to main page, 'n' to quit the program.\n";
  while(counter2==0)
  {
      cin >> exit_option;

      if(exit_option == "y")
      {
        main();
        counter2++;
      }

      else if (exit_option == "n")
      {
        exit_program();
        counter2++;
      }

      else
      {
        cout << "Please enter a valid choice!\n\n";
      }
  }
} // End of update_item()
///

void StoreItem::delete_item() // delete_item() for user to delete an item
{
  system("cls");

  //local variable
  string Item_ID, Item_Name, Item_Description, Item_Manufacturer, Item_Category,
  Item_sellprice, Item_costprice, Item_units_stored, Item_units_sold, Item_year_intro,
  Item_month_intro, Item_day_intro, item_to_delete, restart_func_option;
  int counter=0, counter2 = 0, x=0;
  bool item_delete_exist = false;

	//opening the file for input and ouput
  ofstream readin;
  ifstream readout;
  readout.open("inventory.txt",std::ios::app);
  readin.open("deletionfile.txt", std::ios::app);

  //initialzing vector
  vector<string> ItemList;
  //***Reading inventory.txt into the vector file***
  string item;
  while (getline(readout,item))
  {
    stringstream ss(item);

    while (getline(ss, item,','))
    {
      ItemList.push_back(item);
    }
  }

  //Interface of delete_item() while letting user to input an item ID that user wished to delete.
	cout <<"--------------------------------------\n";
	cout << "<<<TO DELETE A RECORD>>>\n";
	cout <<"--------------------------------------\n\n";
  cout << "Would you like to -->\n"
  << "<1> Delete an entire record\n"
  << "<2> Delete a selected data field of a record\n\n"
  <<"Please choose a function:\n";

  int choice;
  cin >> choice; // Get user's choice for functions

  //if choice not in function, then it will exit
  if(choice < 1 || choice > 2)
  {
    cout << "Invalid Choice!\n\a\n";
    cout << "Returning to the main menu...\n";
    system("PAUSE");
    main();
  }
  //****//

  if(choice == 1)
  {
    cout << "Please enter the Item ID that you want to delete:\n";
    cin >> item_to_delete;

    for(int i = 0; i < ItemList.size(); i+=12) //check the itemID to delete
    {
      if (item_to_delete == ItemList[i])
      {
        ItemList.erase(ItemList.begin()+i, ItemList.begin()+(i+12));
        cout << "Item succesfully deleted! \n";
        item_delete_exist = true;
      }
    }

    for(int i = 0; i < ItemList.size(); i++)//saving the rest of the file back
    {
      readin << ItemList[i] << ",";
    }

    readout.close();
    readin.close();
    remove("inventory.txt");
    rename("deletionfile.txt","inventory.txt");
  }
  else if(choice = 2)
  {
    cout << "Please enter the Item ID that you want to delete:\n";
    cin >> item_to_delete;

    cout << "Please choose which data field do you want to delete?\n\n";
    cout << "<1> Item Name\n";
    cout << "<2> Item Description\n";
    cout << "<3> Item Category\n";
    cout << "<4> Manufacturer\n";
    cout << "<5> Selling Price\n";
    cout << "<6> Cost Price\n";
    cout << "<7> Units in store\n";
    cout << "<8> Units sold\n";
    cout << "<9> Year of Date first introduced\n";
    cout << "<10> Month of Date first introduced\n";
    cout << "<11> Day of Date first introduced\n";
    cin >> choice;

    //if choice not in function, then it will exit
    if(choice < 1 || choice > 11)
    {
      cout << "Invalid Choice! Unable to proceed to the next step.\n\a\n";
			cout << "\nTo restart function, enter 'y'. \nTo proceed to exit of function, enter 'n'.\n";
			while(counter==0)
			{
					cin >> restart_func_option;

					if(restart_func_option == "y")
					{
						delete_item();
						counter++;
					}
					else if (restart_func_option == "n")
					{
						main();
						counter++;
					}
					else
					{
						cout << "Please enter a valid choice!\n\n";
					}

    	}
		}

    for(int i = 0; i < ItemList.size(); i+=12) // checking the correct item ID to delete the specific data field
    {
      if (item_to_delete == ItemList[i])
      {
        ItemList[i+choice]="-1";
        cout << "\n Item succesfully deleted! \n";
        item_delete_exist = true;
      }
    }

    for(int i = 0; i < ItemList.size(); i++)
    {
      readin << ItemList[i] << ",";
    }

    readout.close();
    readin.close();
    remove("inventory.txt");
    rename("deletionfile.txt","inventory.txt");

  }


  if(!item_delete_exist) // check if itemID does not exit, then it will ignore the delete procedure
  {
    readout.close();
    readin.close();

    remove("inventory.txt");
    rename("deletionfile.txt","inventory.txt");

    cout << "\nItem ID cannot be found or deletion process could not be completed!\n\n";

    //prompt user to choose to restart delete_item() or to continue to proceed
    cout << "\nTo restart function, enter 'y'. \nTo proceed to exit of function, enter 'n'.\n";
    while(counter==0)
    {
        cin >> restart_func_option;

        if(restart_func_option == "y")
        {
          delete_item();
          counter++;
        }
        else if (restart_func_option == "n")
        {
          counter++;
        }
        else
        {
          cout << "Please enter a valid choice!\n\n";
        }
    }
  }

	//promt user to restart the function or to exit
	cout << "\nTo restart function, enter 'y'. \nTo proceed to exit of function, enter 'n'.\n";
	while(counter==0)
	{
			cin >> restart_func_option;

			if(restart_func_option == "y")
			{
				delete_item();
				counter++;
			}
			else if (restart_func_option == "n")
			{
				counter++;
			}
			else
			{
				cout << "Please enter a valid choice!\n\n";
			}
	}
  //prompt user to choose toreturn to main() or exit the program
  cout << "\nDo you wish to go back to the main page or exit the program? \nEnter 'y' to go back to main page, 'n' to quit the program.\n";
  while(counter2==0)
  {
      cin >> exit_option;

      if(exit_option == "y")
      {
        main();
        counter2++;
      }

      else if (exit_option == "n")
      {
        exit_program();
        counter2++;
      }

      else
      {
        cout << "Please enter a valid choice!\n\n";
      }
  }
}//end of delete_item()

void StoreItem::display_item() //display_item() function to display data fields of the record
{
  system("cls");
	cout <<"-----------------------------------------\n";
	cout << "<<<TO DISPLAY AN ITEM IN YOUR INVENTORY>>>\n";
	cout <<"-----------------------------------------\n\n";

  // Local Variable;
  int counter =0 ,counter2 = 0, counter3 = 0;
  string itemID, Item_ID, Item_Name, Item_Description, Item_Manufacturer, Item_Category,
  Item_sellprice, Item_costprice, Item_units_stored, Item_units_sold, Item_year_intro, Item_month_intro, Item_day_intro, choice, choice2;
  bool choice_value;

  //interface for user to choose a data field to display
  cout << "Please choose which data field do you want to view?\n\n";
  cout << "<1> Item ID\n";
  cout << "<2> Item Name\n";
  cout << "<3> Item Description\n";
  cout << "<4> Item Category\n";
  cout << "<5> Manufacturer\n";
  cout << "<6> Selling Price\n";
  cout << "<7> Cost Price\n";
  cout << "<8> Units in store\n";
  cout << "<9> Units sold\n";
  cout << "<10> Date of first introduced\n";
  cout << setw(7) << "OR" << setw(15)<< endl;
  cout << "<11> Display an item's whole record\n";
  cin >> choice;

  system("cls");

  ifstream read;
  read.open("inventory.txt",std::ios::app); //opening file for input and output

  //initialzing vector
	vector<int> SortItemNumber;
	vector<int> SortItemNumber2;
	vector<int> SortItemNumber3;
	vector<string> SortItemName;
  vector<string> ItemList;

  //***Reading inventory.txt into the vector file***
  string item;
  while (getline(read,item))
  {
    stringstream ss(item);

    while (getline(ss, item,','))
    {
      ItemList.push_back(item);
    }
  }




  //logic for data field to display after a number is selected
  while(true)
  {
    if (choice == "1")
    {
			cout << "\n--------------\n";
      cout << "Item ID\n";
			cout << "--------------\n";

      for(int i=0; i < ItemList.size(); i+=12)
      {
        if(ItemList[i] != "-1")
        {
					SortItemName.push_back(ItemList[i]);
          cout << ItemList[i] << endl;

        }
        choice_value = true;
      }

			//To sort the display
			cout << "\nDo you want to sort the ID displayed?\nEnter 'A' to sort by ascending order,'D' to sort by descending order, or any other input to exit.\n\n";
			cin >> choice2;
			if(choice2 == "A") //Sort by ascending order
			{
				sort(SortItemName.begin(),SortItemName.end());
				cout << "\nAfter Sorting:\n\n";
				for(int j=0; j<SortItemName.size(); j++)
				{
					cout << SortItemName[j] << endl;
				}
			}
			else if (choice2 == "D")//Sort by descending order
			{
				sort(SortItemName.rbegin(),SortItemName.rend());
				cout << "\nAfter Sorting:\n\n";
				for(int j=0; j<SortItemName.size(); j++)
				{
					cout << SortItemName[j] << endl;
				}
			}
			else
			{
				break;
			}
			//sort end

    }
    else if (choice == "2")
    {
			cout << "\n--------------\n";
      cout << "Item Name\n";
			cout << "--------------\n";

      for(int i=0; i < ItemList.size(); i+=12)
      {
        if(ItemList[i+1] != "-1")
        {
					SortItemName.push_back(ItemList[i+1]);
          cout <<ItemList[i+1] << endl;
        }
        choice_value = true;
      }

			//Sort
			cout << "\nDo you want to sort the ID displayed?\nEnter 'A' to sort by ascending order,'D' to sort by descending order, or any other input to exit.\n\n";
			cin >> choice2;
			if(choice2 == "A")//Sort by ascending order
			{
				sort(SortItemName.begin(),SortItemName.end());
				cout << "\nAfter Sorting:\n\n";
				for(int j=0; j<SortItemName.size(); j++)
				{
					cout << SortItemName[j] << endl;
				}
			}
			else if (choice2 == "D")//Sort by descending order
			{
				sort(SortItemName.rbegin(),SortItemName.rend());
				cout << "\nAfter Sorting:\n\n";
				for(int j=0; j<SortItemName.size(); j++)
				{
					cout << SortItemName[j] << endl;
				}
			}
			else
			{
				break;
			}
			//sort end

    }
    else if (choice == "3")
    {
			cout << "\n----------------\n";
      cout << "Item Description\n";
			cout << "----------------\n";

      for(int i=0; i < ItemList.size(); i+=12)
      {
        if(ItemList[i+2] != "-1")
        {
					SortItemName.push_back(ItemList[i+2]);
          cout <<ItemList[i+2] << endl;
        }
        choice_value = true;
      }

			//Sort
			cout << "\nDo you want to sort the ID displayed?\nEnter 'A' to sort by ascending order,'D' to sort by descending order, or any other input to exit.\n\n";
			cin >> choice2;
			if(choice2 == "A")//Sort by ascending order
			{
				sort(SortItemName.begin(),SortItemName.end());
				cout << "\nAfter Sorting:\n\n";
				for(int j=0; j<SortItemName.size(); j++)
				{
					cout << SortItemName[j] << endl;
				}
			}
			else if (choice2 == "D")//Sort by descending order
			{
				sort(SortItemName.rbegin(),SortItemName.rend());
				cout << "\nAfter Sorting:\n\n";
				for(int j=0; j<SortItemName.size(); j++)
				{
					cout << SortItemName[j] << endl;
				}
			}
			else
			{
				break;
			}
			//sort end
    }
    else if (choice == "4")
    {
			cout << "\n-----------------\n";
      cout << "Item Category\n";
			cout << "-----------------\n";

      for(int i=0; i < ItemList.size(); i+=12)
      {
        if(ItemList[i+3] != "-1")
        {
					SortItemName.push_back(ItemList[i+3]);
          cout <<ItemList[i+3] << endl;
        }
        choice_value = true;
      }
			//Sort
			cout << "\nDo you want to sort the ID displayed?\nEnter 'A' to sort by ascending order,'D' to sort by descending order, or any other input to exit.\n\n";
			cin >> choice2;
			if(choice2 == "A")//Sort by ascending order
			{
				sort(SortItemName.begin(),SortItemName.end());
				cout << "\nAfter Sorting:\n\n";
				for(int j=0; j<SortItemName.size(); j++)
				{
					cout << SortItemName[j] << endl;
				}
			}
			else if (choice2 == "D")//Sort by descending order
			{
				sort(SortItemName.rbegin(),SortItemName.rend());
				cout << "\nAfter Sorting:\n\n";
				for(int j=0; j<SortItemName.size(); j++)
				{
					cout << SortItemName[j] << endl;
				}
			}
			else
			{
				break;
			}
			//sort end
    }
    else if (choice == "5")
    {
			cout << "\n-----------------\n";
      cout << "Item Manufacturer\n";
			cout << "-----------------\n";
      for(int i=0; i < ItemList.size(); i+=12)
      {
        if(ItemList[i+4] != "-1")
        {
					SortItemName.push_back(ItemList[i+4]);
          cout<<ItemList[i+4] << endl;
        }
        choice_value = true;
      }
			//Sort
			cout << "\nDo you want to sort the ID displayed?\nEnter 'A' to sort by ascending order,'D' to sort by descending order, or any other input to exit.\n\n";
			cin >> choice2;
			if(choice2 == "A")//Sort by ascending order
			{
				sort(SortItemName.begin(),SortItemName.end());
				cout << "\nAfter Sorting:\n\n";
				for(int j=0; j<SortItemName.size(); j++)
				{
					cout << SortItemName[j] << endl;
				}
			}
			else if (choice2 == "D")//Sort by descending order
			{
				sort(SortItemName.rbegin(),SortItemName.rend());
				cout << "\nAfter Sorting:\n\n";
				for(int j=0; j<SortItemName.size(); j++)
				{
					cout << SortItemName[j] << endl;
				}
			}
			else
			{
				break;
			}
			//sort end
    }
    else if (choice == "6")
    {
			cout << "\n-----------------\n";
      cout << "Selling Price\n";
			cout << "-----------------\n";
      for(int i=0; i < ItemList.size(); i+=12)
      {
        if(ItemList[i+5] != "-1")
        {
					stringstream value(ItemList[i+5]);
	        int values = 0;
	        value >> values;

					SortItemNumber.push_back(values);
          cout <<"RM " << ItemList[i+5] << endl;
        }
        choice_value = true;
      }

			//Sort
			cout << "\nDo you want to sort the ID displayed?\nEnter 'A' to sort by ascending order,'D' to sort by descending order, or any other input to exit.\n\n";
			cin >> choice2;
			if(choice2 == "A")//Sort by ascending order
			{
				sort(SortItemNumber.begin(),SortItemNumber.end());
				cout << "\nAfter Sorting:\n\n";
				for(int j=0; j<SortItemNumber.size(); j++)
				{
					cout << "RM "<< SortItemNumber[j] << endl;
				}
			}
			else if (choice2 == "D")//Sort by descending order
			{
				sort(SortItemNumber.rbegin(),SortItemNumber.rend());
				cout << "\nAfter Sorting:\n\n";
				for(int j=0; j<SortItemNumber.size(); j++)
				{
					cout <<"RM "<<  SortItemNumber[j] << endl;
				}
			}
			else
			{
				break;
			}
			//sort end

    }
    else if (choice == "7")
    {
			cout << "\n-----------------\n";
      cout << "Cost Price\n";
			cout << "-----------------\n";

      for(int i=0; i < ItemList.size(); i+=12)
      {
        if(ItemList[i+6] != "-1")
        {
					stringstream value(ItemList[i+6]);
					int values = 0;
					value >> values;

					SortItemNumber.push_back(values);
          cout << "RM " << ItemList[i+6] << endl;
        }
        choice_value = true;
      }

			//Sort
			cout << "\nDo you want to sort the ID displayed?\nEnter 'A' to sort by ascending order,'D' to sort by descending order, or any other input to exit.\n\n";
			cin >> choice2;
			if(choice2 == "A")//Sort by ascending order
			{
				sort(SortItemNumber.begin(),SortItemNumber.end());
				cout << "\nAfter Sorting:\n\n";
				for(int j=0; j<SortItemNumber.size(); j++)
				{
					cout << "RM " << SortItemNumber[j] << endl;
				}
			}
			else if (choice2 == "D")//Sort by descending order
			{
				sort(SortItemNumber.rbegin(),SortItemNumber.rend());
				cout << "\nAfter Sorting:\n\n";
				for(int j=0; j<SortItemNumber.size(); j++)
				{
					cout << "RM " << SortItemNumber[j] << endl;
				}
			}
			else
			{
				break;
			}
			//sort end
    }
    else if (choice == "8")
    {
			cout << "\n-----------------\n";
      cout << "Units in Store\n";
			cout << "-----------------\n";
      for(int i=0; i < ItemList.size(); i+=12)
      {
        if(ItemList[i+7] != "-1")
        {
					stringstream value(ItemList[i+7]);
					int values = 0;
					value >> values;

					SortItemNumber.push_back(values);
          cout <<ItemList[i+7] << endl;
        }
        choice_value = true;
      }

			//Sort
			cout << "\nDo you want to sort the ID displayed?\nEnter 'A' to sort by ascending order,'D' to sort by descending order, or any other input to exit.\n\n";
			cin >> choice2;
			if(choice2 == "A")//Sort by ascending order
			{
				sort(SortItemNumber.begin(),SortItemNumber.end());
				cout << "\nAfter Sorting:\n\n";
				for(int j=0; j<SortItemNumber.size(); j++)
				{
					cout << SortItemNumber[j] << endl;
				}
			}
			else if (choice2 == "D")//Sort by descending order
			{
				sort(SortItemNumber.rbegin(),SortItemNumber.rend());
				cout << "\nAfter Sorting:\n\n";
				for(int j=0; j<SortItemNumber.size(); j++)
				{
					cout << SortItemNumber[j] << endl;
				}
			}
			else
			{
				break;
			}
			//sort end
    }
    else if (choice == "9")
    {
			cout << "\n-----------------\n";
      cout << "Units Sold\n";
			cout << "-----------------\n";
      for(int i=0; i < ItemList.size(); i+=12)
      {
        if(ItemList[i+8] != "-1")
        {
					stringstream value(ItemList[i+8]);
					int values = 0;
					value >> values;

					SortItemNumber.push_back(values);
          cout <<ItemList[i+8] << endl;
        }
        choice_value = true;
      }

			//Sort
			cout << "\nDo you want to sort the ID displayed?\nEnter 'A' to sort by ascending order,'D' to sort by descending order, or any other input to exit.\n\n";
			cin >> choice2;
			if(choice2 == "A")//Sort by ascending order
			{
				sort(SortItemNumber.begin(),SortItemNumber.end());
				cout << "\nAfter Sorting:\n\n";
				for(int j=0; j<SortItemNumber.size(); j++)
				{
					cout << SortItemNumber[j] << endl;
				}
			}
			else if (choice2 == "D")//Sort by descending order
			{
				sort(SortItemNumber.rbegin(),SortItemNumber.rend());
				cout << "\nAfter Sorting:\n\n";
				for(int j=0; j<SortItemNumber.size(); j++)
				{
					cout << SortItemNumber[j] << endl;
				}
			}
			else
			{
				break;
			}
			//sort end

    }
    else if (choice == "10")
    {
			cout << "\n----------------------\n";
      cout << "Date of Introduction: \n";
			cout << "----------------------\n";
      for(int i=0; i < ItemList.size(); i+=12)
      {
        if(ItemList[i+9] != "-1" && ItemList[i+10] != "-1" && ItemList[i+11] != "-1")
        {
					stringstream value(ItemList[i+9]);
					int values = 0;
					value >> values;

					stringstream value2(ItemList[i+10]);
					int values2 = 0;
					value2 >> values2;

					stringstream value3(ItemList[i+11]);
					int values3 = 0;
					value3 >> values3;

					SortItemNumber.push_back(values);
					SortItemNumber2.push_back(values2);
					SortItemNumber3.push_back(values3);

          cout << ItemList[i+9] << "-" <<ItemList[i+10] << "-" << ItemList[i+11] << endl;
        }
        choice_value = true;
				//sort end
      }


			//Sort
			cout << "\nDo you want to sort the ID displayed?\nEnter 'A' to sort by ascending order,'D' to sort by descending order, or any other input to exit.\n\n";
			cin >> choice2;
			if(choice2 == "A")//Sort by ascending order
			{
				sort(SortItemNumber.begin(),SortItemNumber.end());
				cout << "\nAfter Sorting:\n";
				cout << "\nYear\n";
				for(int j=0; j<SortItemNumber.size(); j++)
				{
					cout << SortItemNumber[j] << endl;
				}

				sort(SortItemNumber2.begin(),SortItemNumber2.end());
				cout << "\n\nMonth\n";
				for(int j=0; j<SortItemNumber2.size(); j++)
				{
					cout << SortItemNumber2[j] << endl;
				}

				sort(SortItemNumber3.begin(),SortItemNumber3.end());
				cout << "\n\nDay\n";
				for(int j=0; j<SortItemNumber3.size(); j++)
				{
					cout << SortItemNumber3[j] << endl;
				}
			}
			else if (choice2 == "D")//Sort by descending order
			{
				sort(SortItemNumber.rbegin(),SortItemNumber.rend());
				cout << "\nAfter Sorting:\n";
				cout << "\nYear\n";
				for(int j=0; j<SortItemNumber.size(); j++)
				{
					cout << SortItemNumber[j] << endl;
				}

				sort(SortItemNumber2.rbegin(),SortItemNumber2.rend());
				cout << "\n\nMonth\n";
				for(int j=0; j<SortItemNumber2.size(); j++)
				{
					cout << SortItemNumber2[j] << endl;
				}

				sort(SortItemNumber3.rbegin(),SortItemNumber3.rend());
				cout << "\n\nDay\n";
				for(int j=0; j<SortItemNumber3.size(); j++)
				{
					cout << SortItemNumber3[j] << endl;
				}
			}
			else
			{
				break;
			}
    }
    else if (choice == "11") //showing the whole record of an item
    {
      choice_value = true;
      cout << "\nPlease enter the Item ID:\n";
      cin >> itemID;

      for(int i=0; i < ItemList.size(); i+=12)
        {
          if(ItemList[i] == itemID)
          {
            cout << "\nItem ID: "<< ItemList[i] << endl;
            cout << "Item Name: " << ItemList[i+1] << endl;
            cout << "Item Description: " << ItemList[i+2] <<endl;
            cout << "Item Category: " << ItemList[i+3] << endl;
            cout << "Item Manufacturer: "<< ItemList[i+4] << endl;
            cout << "Selling Price: " <<"RM" << ItemList[i+5]<< endl;
            cout << "Cost Price: " << "RM" << ItemList[i+6] << endl;
            cout << "Units in Store: "<< ItemList[i+7] << endl;
            cout << "Units Sold: " << ItemList[i+8] << endl;
            cout << "Date of Introduction: " << ItemList[i+9] << "-" <<ItemList[i+10] << "-" << ItemList[i+11] << endl;
            break;
          }
          else
          {
            cout << "\nITEM ID INVALID! \a\n";
            break;
          }
        }
      }
      break;
    }
    read.close();

    if(!choice_value)
    {
      cout << "Choice does not exist!!" << endl;
    }




  //prompt user to choose to restart display_item() function or continue to proceed
  cout <<"\nWould you like to check another item? Enter 'y' to check another item. \nEnter 'n' to proceed to exit.\n";
  while(counter2==0)
  {
      cin >> restart_func_option;

      if(restart_func_option == "y")
      {
        display_item();
        counter2++;
      }

      else if (restart_func_option == "n")
      {
        counter2++;
      }

      else
      {
        cout << "Please enter a valid choice!\n\n";
      }
  }

  //prompt user to choose toreturn to main() or exit the program
	cout << "\nDo you wish to go back to the main page or exit the program? \nEnter 'y' to go back to main page, 'n' to quit the program.\n";
	while(counter3==0)
	{
			cin >> exit_option;

			if(exit_option == "y")
			{
				main();
				counter3++;
			}

			else if (exit_option == "n")
			{
				exit_program();
				counter3++;
			}

			else
			{
				cout << "Please enter a valid choice!\n\n";
			}

	}
} //End of display_item() function

void StoreItem::search_item()
{
  system("cls");

  // Local Variable;
  int counter =0 ,counter2 = 0, counter3 = 0;
  string itemID, Item_ID, Item_Name, Item_Description, Item_Manufacturer, Item_Category, word,
  Item_sellprice, Item_costprice, Item_units_stored, Item_units_sold, Item_year_intro, Item_month_intro, Item_day_intro, choice;
  bool choice_value, item_exist;


  ifstream read;
  read.open("inventory.txt",std::ios::app);//opening for a file for output

  //initialzing vector
  vector<string> ItemList;

  //***Reading inventory.txt into the vector file***
  string item;
  while (getline(read,item))
  {
    stringstream ss(item);

    while (getline(ss, item,','))
    {
      ItemList.push_back(item);
    }
  }

  cout << "\n<<< TO SEARCH AN ITEM IN THE INVENTORY >>>\n";
	cout <<"----------------------------------------------\n";
  cout << "<1> Search words \n";
	cout << "	> Item ID\n";
	cout << "	> Item Name\n";
	cout << "	> Item Description\n";
	cout << "	> Item Category\n";
	cout << "	> Item Manufacturer\n\n";
  cout << "<2> Search values\n";
	cout << "	> Selling Price \n";
	cout << "	> Cost Price \n";
	cout << "	> Units In Store \n";
	cout << "	> Units Sold\n";
	cout << "	> Year of Item First Introduced \n";
	cout << "	> Month of Item First Introduced\n";
	cout << "	> Day Of Item First Introduced\n\n";
	cout << "Please enter the number of the option that you wish to start: ";
  cin >> choice;

  if(choice =="1") //for user to search by word
  {
		cout << "\n------------------\n";
		cout << "OPTIONS AVAILABLE: \n";
		cout << "------------------\n";
    cout << "<1> Item ID\n";
    cout << "<2> Item Name\n";
    cout << "<3> Item Description\n";
    cout << "<4> Item Category\n";
    cout << "<5> Item Manufacturer\n";

    int choice2;
    cin >> choice2;

    if(choice2 == 1) //search Item ID
    {
      cout << "Enter the ID that you wish to find: \n";
      cin.ignore();
      getline(cin,word);
      cout << "\nResults:\n";
      for(int i=0; i<ItemList.size();i+=12)
      {
        string A, B;
      	A = ItemList[i];
      	B = word;

      	int index = Find(A, B); //calling Find()
      	if (index >= 0) //cout the Item Found
        {
          cout << "\n[Item ID]: "<< ItemList[i] << endl;
          cout << "Item Name: " << ItemList[i+1] << endl;
          cout << "Item Description: " << ItemList[i+2] <<endl;
          cout << "Item Category: " << ItemList[i+3] << endl;
          cout << "Item Manufacturer: "<< ItemList[i+4] << endl;
          cout << "Selling Price: " <<"RM" << ItemList[i+5]<< endl;
          cout << "Cost Price: " << "RM" << ItemList[i+6] << endl;
          cout << "Units in Store: "<< ItemList[i+7] << endl;
          cout << "Units Sold: " << ItemList[i+8] << endl;
          cout << "Date of Introduction: " << ItemList[i+9] << "-" <<ItemList[i+10] << "-" << ItemList[i+11] << endl;
          item_exist = true;
        }
      }
    }

    if(choice2 == 2)// search Item Name
    {
      cout << "Enter the Name that you wish to find: \n";
      cin.ignore();
      getline(cin,word);
      cout << "\nResults:\n";
      for(int i=1; i<ItemList.size();i+=12)
      {
        string A, B;
      	A = ItemList[i];
      	B = word;

      	int index = Find(A, B);
      	if (index >= 0) //cout the item found
        {
          cout << "\nItem ID: "<< ItemList[i-1] << endl;
          cout << "[Item Name]: " << ItemList[i] << endl;
          cout << "Item Description: " << ItemList[i+1] <<endl;
          cout << "Item Category: " << ItemList[i+2] << endl;
          cout << "Item Manufacturer: "<< ItemList[i+3] << endl;
          cout << "Selling Price: " <<"RM" << ItemList[i+4]<< endl;
          cout << "Cost Price: " << "RM" << ItemList[i+5] << endl;
          cout << "Units in Store: "<< ItemList[i+6] << endl;
          cout << "Units Sold: " << ItemList[i+7] << endl;
          cout << "Date of Introduction: " << ItemList[i+8] << "-" <<ItemList[i+9] << "-" << ItemList[i+10] << endl;
          item_exist = true;
        }
      }
    }

    if(choice2 == 3)
    {
      cout << "Enter the Description that you wish to find: \n";
      cin.ignore();
      getline(cin,word);
      cout << "\nResults:\n";
      for(int i=2; i<ItemList.size();i+=12)
      {
        string A, B;
      	A = ItemList[i];
      	B = word;

      	int index = Find(A, B);
      	if (index >= 0)//cout the item found
        {
          cout << "\nItem ID: "<< ItemList[i-2] << endl;
          cout << "Item Name: " << ItemList[i-1] << endl;
          cout << "[Item Description]: " << ItemList[i] <<endl;
          cout << "Item Category: " << ItemList[i+1] << endl;
          cout << "Item Manufacturer: "<< ItemList[i+2] << endl;
          cout << "Selling Price: " <<"RM" << ItemList[i+3]<< endl;
          cout << "Cost Price: " << "RM" << ItemList[i+4] << endl;
          cout << "Units in Store: "<< ItemList[i+5] << endl;
          cout << "Units Sold: " << ItemList[i+6] << endl;
          cout << "Date of Introduction: " << ItemList[i+7] << "-" <<ItemList[i+8] << "-" << ItemList[i+9] << endl;
          item_exist = true;
        }
      }
    }

    if(choice2 == 4)
    {
      cout << "Enter the Category that you wish to find: \n";
      cin.ignore();
      getline(cin,word);
      cout << "\nResults:\n";
      for(int i=3; i<ItemList.size();i+=12)
      {
        string A, B;
      	A = ItemList[i];
      	B = word;

      	int index = Find(A, B);
      	if (index >= 0)//cout the item found
        {
          cout << "\nItem ID: "<< ItemList[i-3] << endl;
          cout << "Item Name: " << ItemList[i-2] << endl;
          cout << "Item Description: " << ItemList[i-1] <<endl;
          cout << "[Item Category]: " << ItemList[i] << endl;
          cout << "Item Manufacturer: "<< ItemList[i+1] << endl;
          cout << "Selling Price: " <<"RM" << ItemList[i+2]<< endl;
          cout << "Cost Price: " << "RM" << ItemList[i+3] << endl;
          cout << "Units in Store: "<< ItemList[i+4] << endl;
          cout << "Units Sold: " << ItemList[i+5] << endl;
          cout << "Date of Introduction: " << ItemList[i+6] << "-" <<ItemList[i+7] << "-" << ItemList[i+8] << endl;
          item_exist = true;
        }
      }
    }

    if(choice2 == 5)
    {
      cout << "Enter the Manufacturer that you wish to find: \n";
      cin.ignore();
      getline(cin,word);
      cout << "\nResults:\n";
      for(int i=4; i<ItemList.size();i+=12)
      {
        string A, B;
      	A = ItemList[i];
      	B = word;

      	int index = Find(A, B);
      	if (index >= 0)//cout the item found
        {
          cout << "\nItem ID: "<< ItemList[i-4] << endl;
          cout << "Item Name: " << ItemList[i-3] << endl;
          cout << "Item Description: " << ItemList[i-2] <<endl;
          cout << "Item Category: " << ItemList[i-1] << endl;
          cout << "[Item Manufacturer]: "<< ItemList[i] << endl;
          cout << "Selling Price: " <<"RM" << ItemList[i+1]<< endl;
          cout << "Cost Price: " << "RM" << ItemList[i+2] << endl;
          cout << "Units in Store: "<< ItemList[i+3] << endl;
          cout << "Units Sold: " << ItemList[i+4] << endl;
          cout << "Date of Introduction: " << ItemList[i+5] << "-" <<ItemList[i+6] << "-" << ItemList[i+7] << endl;
          item_exist = true;
        }
      }
    }

    if(!item_exist)
    {
      cout << "There is no such record.\n";
    }

  }
	else if(choice =="2") //search by number
  {
		cout << "\n------------------\n";
		cout << "OPTIONS AVAILABLE: \n";
		cout << "------------------\n";
    cout << "<a> Selling Price \n";
    cout << "<b> Cost Price \n";
    cout << "<c> Units In Store \n";
    cout << "<d> Units Sold\n";
    cout << "<e> Year of Item First Introduced \n";
		cout << "<f> Month of Item First Introduced\n";
		cout << "<g> Day Of Item First Introduced\n\n";
    cout << "Operators available: > (more than), < (less than), = (equals to)\n\n";

    string choice1, choice2;
    int choice3;
    cout << "Please enter the an option:";
    cin >> choice1;
		cout << "Please enter an operator: ";
		cin >> choice2;
		cout << "Please enter a value: ";
		cin >> choice3;

		cout << "------------------\n";
		cout << "Results:\n";
		cout << "------------------\n";

    if(choice1 == "a")
    {

      for(int i=5; i<ItemList.size(); i+=12)
      {
        stringstream value(ItemList[i]);
        int values = 0;
        value >> values;

				//checking item if its more than, equal or less then cout the results
        if(choice2 == ">")
        {
            if(values > choice3)
            {
							cout << "\nItem ID: "<< ItemList[i-5] << endl;
		          cout << "Item Name: " << ItemList[i-4] << endl;
		          cout << "Item Description: " << ItemList[i-3] <<endl;
		          cout << "Item Category: " << ItemList[i-2] << endl;
		          cout << "Item Manufacturer]: "<< ItemList[i-1] << endl;
		          cout << "[Selling Price]: " <<"RM" << ItemList[i]<< endl;
		          cout << "Cost Price: " << "RM" << ItemList[i+1] << endl;
		          cout << "Units in Store: "<< ItemList[i+2] << endl;
		          cout << "Units Sold: " << ItemList[i+3] << endl;
		          cout << "Date of Introduction: " << ItemList[i+4] << "-" <<ItemList[i+5] << "-" << ItemList[i+6] << endl;
		          item_exist = true;
            }
        }

        if(choice2 == "<")
        {
            if(values < choice3)
            {
							cout << "\nItem ID: "<< ItemList[i-5] << endl;
		          cout << "Item Name: " << ItemList[i-4] << endl;
		          cout << "Item Description: " << ItemList[i-3] <<endl;
		          cout << "Item Category: " << ItemList[i-2] << endl;
		          cout << "Item Manufacturer: "<< ItemList[i-1] << endl;
		          cout << "[Selling Price]: " <<"RM" << ItemList[i]<< endl;
		          cout << "Cost Price: " << "RM" << ItemList[i+1] << endl;
		          cout << "Units in Store: "<< ItemList[i+2] << endl;
		          cout << "Units Sold: " << ItemList[i+3] << endl;
		          cout << "Date of Introduction: " << ItemList[i+4] << "-" <<ItemList[i+5] << "-" << ItemList[i+6] << endl;
		          item_exist = true;
            }
        }

        if(choice2 == "=")
        {
            if(values == choice3)
            {
							cout << "\nItem ID: "<< ItemList[i-5] << endl;
		          cout << "Item Name: " << ItemList[i-4] << endl;
		          cout << "Item Description: " << ItemList[i-3] <<endl;
		          cout << "Item Category: " << ItemList[i-2] << endl;
		          cout << "Item Manufacturer: "<< ItemList[i-1] << endl;
		          cout << "[Selling Price]: " <<"RM" << ItemList[i]<< endl;
		          cout << "Cost Price: " << "RM" << ItemList[i+1] << endl;
		          cout << "Units in Store: "<< ItemList[i+2] << endl;
		          cout << "Units Sold: " << ItemList[i+3] << endl;
		          cout << "Date of Introduction: " << ItemList[i+4] << "-" <<ItemList[i+5] << "-" << ItemList[i+6] << endl;
		          item_exist = true;
            }
        }
      }
			if(!item_exist)
	    {
	      cout << "There is no such record.\n";
	    }
    }

    if(choice1 == "b")
    {

      for(int i=6; i<ItemList.size(); i+=12)
      {
        stringstream value(ItemList[i]);
        int values = 0;
        value >> values;
				//checking item if its more than, equal or less then cout the results
        if(choice2 == ">")
        {
            if(values > choice3)
            {
							cout << "\nItem ID: "<< ItemList[i-6] << endl;
		          cout << "Item Name: " << ItemList[i-5] << endl;
		          cout << "Item Description: " << ItemList[i-4] <<endl;
		          cout << "Item Category: " << ItemList[i-3] << endl;
		          cout << "Item Manufacturer: "<< ItemList[i-2] << endl;
		          cout << "Selling Price: " <<"RM" << ItemList[i-1]<< endl;
		          cout << "[Cost Price]: " << "RM" << ItemList[i] << endl;
		          cout << "Units in Store: "<< ItemList[i+1] << endl;
		          cout << "Units Sold: " << ItemList[i+2] << endl;
		          cout << "Date of Introduction: " << ItemList[i+3] << "-" <<ItemList[i+4] << "-" << ItemList[i+5] << endl;
		          item_exist = true;
            }
        }

        if(choice2 == "<")
        {
            if(values < choice3)
            {
							cout << "\nItem ID: "<< ItemList[i-6] << endl;
		          cout << "Item Name: " << ItemList[i-5] << endl;
		          cout << "Item Description: " << ItemList[i-4] <<endl;
		          cout << "Item Category: " << ItemList[i-3] << endl;
		          cout << "Item Manufacturer: "<< ItemList[i-2] << endl;
		          cout << "Selling Price: " <<"RM" << ItemList[i-1]<< endl;
		          cout << "[Cost Price]: " << "RM" << ItemList[i] << endl;
		          cout << "Units in Store: "<< ItemList[i+1] << endl;
		          cout << "Units Sold: " << ItemList[i+2] << endl;
		          cout << "Date of Introduction: " << ItemList[i+3] << "-" <<ItemList[i+4] << "-" << ItemList[i+5] << endl;
		          item_exist = true;
            }
        }

        if(choice2 == "=")
        {
            if(values == choice3)
            {
							cout << "\nItem ID: "<< ItemList[i-6] << endl;
		          cout << "Item Name: " << ItemList[i-5] << endl;
		          cout << "Item Description: " << ItemList[i-4] <<endl;
		          cout << "Item Category: " << ItemList[i-3] << endl;
		          cout << "Item Manufacturer: "<< ItemList[i-2] << endl;
		          cout << "Selling Price: " <<"RM" << ItemList[i-1]<< endl;
		          cout << "[Cost Price]: " << "RM" << ItemList[i] << endl;
		          cout << "Units in Store: "<< ItemList[i+1] << endl;
		          cout << "Units Sold: " << ItemList[i+2] << endl;
		          cout << "Date of Introduction: " << ItemList[i+3] << "-" <<ItemList[i+4] << "-" << ItemList[i+5] << endl;
		          item_exist = true;
            }
        }


      }
			if(!item_exist)
	    {
	      cout << "There is no such record.\n";
	    }
    }

    if(choice1 == "c")
    {

      for(int i=7; i<ItemList.size(); i+=12)
      {
        stringstream value(ItemList[i]);
        int values = 0;
        value >> values;
				//checking item if its more than, equal or less then cout the results
        if(choice2 == ">")
        {
            if(values > choice3)
            {
							cout << "\nItem ID: "<< ItemList[i-7] << endl;
		          cout << "Item Name: " << ItemList[i-6] << endl;
		          cout << "Item Description: " << ItemList[i-5] <<endl;
		          cout << "Item Category: " << ItemList[i-4] << endl;
		          cout << "Item Manufacturer: "<< ItemList[i-3] << endl;
		          cout << "Selling Price: " <<"RM" << ItemList[i-2]<< endl;
		          cout << "Cost Price: " << "RM" << ItemList[i-1] << endl;
		          cout << "[Units in Store]: "<< ItemList[i] << endl;
		          cout << "Units Sold: " << ItemList[i+1] << endl;
		          cout << "Date of Introduction: " << ItemList[i+2] << "-" <<ItemList[i+3] << "-" << ItemList[i+4] << endl;
		          item_exist = true;
            }
        }

        if(choice2 == "<")
        {
            if(values < choice3)
            {
							cout << "\nItem ID: "<< ItemList[i-7] << endl;
		          cout << "Item Name: " << ItemList[i-6] << endl;
		          cout << "Item Description: " << ItemList[i-5] <<endl;
		          cout << "Item Category: " << ItemList[i-4] << endl;
		          cout << "Item Manufacturer: "<< ItemList[i-3] << endl;
		          cout << "Selling Price: " <<"RM" << ItemList[i-2]<< endl;
		          cout << "Cost Price: " << "RM" << ItemList[i-1] << endl;
		          cout << "[Units in Store]: "<< ItemList[i] << endl;
		          cout << "Units Sold: " << ItemList[i+1] << endl;
		          cout << "Date of Introduction: " << ItemList[i+2] << "-" <<ItemList[i+3] << "-" << ItemList[i+4] << endl;
		          item_exist = true;
            }
          }


        if(choice2 == "=")
        {
            if(values == choice3)
            {
							cout << "\nItem ID: "<< ItemList[i-7] << endl;
		          cout << "Item Name: " << ItemList[i-6] << endl;
		          cout << "Item Description: " << ItemList[i-5] <<endl;
		          cout << "Item Category: " << ItemList[i-4] << endl;
		          cout << "Item Manufacturer: "<< ItemList[i-3] << endl;
		          cout << "Selling Price: " <<"RM" << ItemList[i-2]<< endl;
		          cout << "Cost Price: " << "RM" << ItemList[i-1] << endl;
		          cout << "[Units in Store]: "<< ItemList[i] << endl;
		          cout << "Units Sold: " << ItemList[i+1] << endl;
		          cout << "Date of Introduction: " << ItemList[i+2] << "-" <<ItemList[i+3] << "-" << ItemList[i+4] << endl;
		          item_exist = true;
            }
            }
        }


			if(!item_exist)
	    {
	      cout << "There is no such record.\n";
	    }
    }

    if(choice1 == "d")
    {

      for(int i=8; i<ItemList.size(); i+=12)
      {
        stringstream value(ItemList[i]);
        int values = 0;
        value >> values;
				//checking item if its more than, equal or less then cout the results
        if(choice2 == ">")
        {
            if(values > choice3)
            {
							cout << "\nItem ID: "<< ItemList[i-8] << endl;
		          cout << "Item Name: " << ItemList[i-7] << endl;
		          cout << "Item Description: " << ItemList[i-6] <<endl;
		          cout << "Item Category: " << ItemList[i-5] << endl;
		          cout << "Item Manufacturer: "<< ItemList[i-4] << endl;
		          cout << "Selling Price: " <<"RM" << ItemList[i-3]<< endl;
		          cout << "Cost Price: " << "RM" << ItemList[i-2] << endl;
		          cout << "Units in Store: "<< ItemList[i-1] << endl;
		          cout << "[Units Sold]: " << ItemList[i] << endl;
		          cout << "Date of Introduction: " << ItemList[i+1] << "-" <<ItemList[i+2] << "-" << ItemList[i+3] << endl;
		          item_exist = true;
            }
        }

        if(choice2 == "<")
        {
					if(values < choice3)
					{
						cout << "\nItem ID: "<< ItemList[i-8] << endl;
						cout << "Item Name: " << ItemList[i-7] << endl;
						cout << "Item Description: " << ItemList[i-6] <<endl;
						cout << "Item Category: " << ItemList[i-5] << endl;
						cout << "Item Manufacturer: "<< ItemList[i-4] << endl;
						cout << "Selling Price: " <<"RM" << ItemList[i-3]<< endl;
						cout << "Cost Price: " << "RM" << ItemList[i-2] << endl;
						cout << "Units in Store: "<< ItemList[i-1] << endl;
						cout << "[Units Sold]: " << ItemList[i] << endl;
						cout << "Date of Introduction: " << ItemList[i+1] << "-" <<ItemList[i+2] << "-" << ItemList[i+3] << endl;
						item_exist = true;
					}
        }

        if(choice2 == "=")
        {
					if(values > choice3)
					{
						cout << "\nItem ID: "<< ItemList[i-8] << endl;
						cout << "Item Name: " << ItemList[i-7] << endl;
						cout << "Item Description: " << ItemList[i-6] <<endl;
						cout << "Item Category: " << ItemList[i-5] << endl;
						cout << "Item Manufacturer: "<< ItemList[i-4] << endl;
						cout << "Selling Price: " <<"RM" << ItemList[i-3]<< endl;
						cout << "Cost Price: " << "RM" << ItemList[i-2] << endl;
						cout << "Units in Store: "<< ItemList[i-1] << endl;
						cout << "[Units Sold]: " << ItemList[i] << endl;
						cout << "Date of Introduction: " << ItemList[i+1] << "-" <<ItemList[i+2] << "-" << ItemList[i+3] << endl;
						item_exist = true;
					}
        }

      }
			if(!item_exist)
	    {
	      cout << "There is no such record.\n";
	    }
    }

    if(choice1 == "e")
    {

      for(int i=9; i<ItemList.size(); i+=12)
      {
        stringstream value(ItemList[i]);
        int values = 0;
        value >> values;
				//checking item if its more than, equal or less then cout the results
        if(choice2 == ">")
        {
            if(values > choice3)
            {
							cout << "\nItem ID: "<< ItemList[i-9] << endl;
		          cout << "Item Name: " << ItemList[i-8] << endl;
		          cout << "Item Description: " << ItemList[i-7] <<endl;
		          cout << "Item Category: " << ItemList[i-6] << endl;
		          cout << "Item Manufacturer: "<< ItemList[i-5] << endl;
		          cout << "Selling Price: " <<"RM" << ItemList[i-4]<< endl;
		          cout << "Cost Price: " << "RM" << ItemList[i-3] << endl;
		          cout << "Units in Store: "<< ItemList[i-2] << endl;
		          cout << "Units Sold: " << ItemList[i-1] << endl;
		          cout << "Date of Introduction: " <<"[" << ItemList[i]<<"]" << "-" <<ItemList[i+1] << "-" << ItemList[i+2] << endl;
		          item_exist = true;
            }
        }

        if(choice2 == "<")
        {
					if(values < choice3)
					{
						cout << "\nItem ID: "<< ItemList[i-9] << endl;
						cout << "Item Name: " << ItemList[i-8] << endl;
						cout << "Item Description: " << ItemList[i-7] <<endl;
						cout << "Item Category: " << ItemList[i-6] << endl;
						cout << "Item Manufacturer: "<< ItemList[i-5] << endl;
						cout << "Selling Price: " <<"RM" << ItemList[i-4]<< endl;
						cout << "Cost Price: " << "RM" << ItemList[i-3] << endl;
						cout << "Units in Store: "<< ItemList[i-2] << endl;
						cout << "Units Sold: " << ItemList[i-1] << endl;
						cout << "Date of Introduction: " <<"[" << ItemList[i]<<"]" << "-" <<ItemList[i+1] << "-" << ItemList[i+2] << endl;
						item_exist = true;
					}
        }

        if(choice2 == "=")
        {
					if(values == choice3)
					{
						cout << "\nItem ID: "<< ItemList[i-9] << endl;
						cout << "Item Name: " << ItemList[i-8] << endl;
						cout << "Item Description: " << ItemList[i-7] <<endl;
						cout << "Item Category: " << ItemList[i-6] << endl;
						cout << "Item Manufacturer: "<< ItemList[i-5] << endl;
						cout << "Selling Price: " <<"RM" << ItemList[i-4]<< endl;
						cout << "Cost Price: " << "RM" << ItemList[i-3] << endl;
						cout << "Units in Store: "<< ItemList[i-2] << endl;
						cout << "Units Sold: " << ItemList[i-1] << endl;
						cout << "Date of Introduction: " <<"[" << ItemList[i]<<"]" << "-" <<ItemList[i+1] << "-" << ItemList[i+2] << endl;
						item_exist = true;
					}
        }

      }
			if(!item_exist)
	    {
	      cout << "There is no such record.\n";
	    }
    }

		if(choice1 == "f")
    {

      for(int i=10; i<ItemList.size(); i+=12)
      {
        stringstream value(ItemList[i]);
        int values = 0;
        value >> values;
				//checking item if its more than, equal or less then cout the results
        if(choice2 == ">")
        {
            if(values > choice3)
            {
							cout << "\nItem ID: "<< ItemList[i-10] << endl;
		          cout << "Item Name: " << ItemList[i-9] << endl;
		          cout << "Item Description: " << ItemList[i-8] <<endl;
		          cout << "Item Category: " << ItemList[i-7] << endl;
		          cout << "Item Manufacturer: "<< ItemList[i-6] << endl;
		          cout << "Selling Price: " <<"RM" << ItemList[i-5]<< endl;
		          cout << "Cost Price: " << "RM" << ItemList[i-4] << endl;
		          cout << "Units in Store: "<< ItemList[i-3] << endl;
		          cout << "Units Sold: " << ItemList[i-2] << endl;
		          cout << "Date of Introduction: " << ItemList[i-1] << "-" <<"[" <<ItemList[i]<<"]" << "-" << ItemList[i+1] << endl;
		          item_exist = true;
            }
        }

        if(choice2 == "<")
        {
            if(values < choice3)
            {
							cout << "\nItem ID: "<< ItemList[i-10] << endl;
		          cout << "Item Name: " << ItemList[i-9] << endl;
		          cout << "Item Description: " << ItemList[i-8] <<endl;
		          cout << "Item Category: " << ItemList[i-7] << endl;
		          cout << "Item Manufacturer: "<< ItemList[i-6] << endl;
		          cout << "Selling Price: " <<"RM" << ItemList[i-5]<< endl;
		          cout << "Cost Price: " << "RM" << ItemList[i-4] << endl;
		          cout << "Units in Store: "<< ItemList[i-3] << endl;
		          cout << "Units Sold: " << ItemList[i-2] << endl;
		          cout << "Date of Introduction: " << ItemList[i-1] << "-" <<"[" <<ItemList[i]<<"]" << "-" << ItemList[i+1] << endl;
		          item_exist = true;
            }
        }

        if(choice2 == "=")
        {
            if(values == choice3)
            {
							cout << "\nItem ID: "<< ItemList[i-10] << endl;
		          cout << "Item Name: " << ItemList[i-9] << endl;
		          cout << "Item Description: " << ItemList[i-8] <<endl;
		          cout << "Item Category: " << ItemList[i-7] << endl;
		          cout << "Item Manufacturer: "<< ItemList[i-6] << endl;
		          cout << "Selling Price: " <<"RM" << ItemList[i-5]<< endl;
		          cout << "Cost Price: " << "RM" << ItemList[i-4] << endl;
		          cout << "Units in Store: "<< ItemList[i-3] << endl;
		          cout << "Units Sold: " << ItemList[i-2] << endl;
		          cout << "Date of Introduction: " << ItemList[i-1] << "-" <<"[" <<ItemList[i]<<"]" << "-" << ItemList[i+1] << endl;
		          item_exist = true;
            }
        }

      }
			if(!item_exist)
	    {
	      cout << "There is no such record.\n";
	    }
    }

		if(choice1 == "g")
    {

      for(int i=11; i<ItemList.size(); i+=12)
      {
        stringstream value(ItemList[i]);
        int values = 0;
        value >> values;
				//checking item if its more than, equal or less then cout the results
        if(choice2 == ">")
        {
					if(values > choice3)
					{
						cout << "\nItem ID: "<< ItemList[i-11] << endl;
						cout << "Item Name: " << ItemList[i-10] << endl;
						cout << "Item Description: " << ItemList[i-9] <<endl;
						cout << "Item Category: " << ItemList[i-8] << endl;
						cout << "Item Manufacturer: "<< ItemList[i-7] << endl;
						cout << "Selling Price: " <<"RM" << ItemList[i-6]<< endl;
						cout << "Cost Price: " << "RM" << ItemList[i-5] << endl;
						cout << "Units in Store: "<< ItemList[i-4] << endl;
						cout << "Units Sold: " << ItemList[i-3] << endl;
						cout << "Date of Introduction: " << ItemList[i-2] << "-"  <<ItemList[i-1]<< "-" <<"["<< ItemList[i]<<"]"  << endl;
						item_exist = true;
					}
        }

        if(choice2 == "<")
        {
					if(values < choice3)
					{
						cout << "\nItem ID: "<< ItemList[i-11] << endl;
						cout << "Item Name: " << ItemList[i-10] << endl;
						cout << "Item Description: " << ItemList[i-9] <<endl;
						cout << "Item Category: " << ItemList[i-8] << endl;
						cout << "Item Manufacturer: "<< ItemList[i-7] << endl;
						cout << "Selling Price: " <<"RM" << ItemList[i-6]<< endl;
						cout << "Cost Price: " << "RM" << ItemList[i-5] << endl;
						cout << "Units in Store: "<< ItemList[i-4] << endl;
						cout << "Units Sold: " << ItemList[i-3] << endl;
						cout << "Date of Introduction: " << ItemList[i-2] << "-"  <<ItemList[i-1]<< "-" <<"["<< ItemList[i]<<"]"  << endl;
						item_exist = true;
					}
        }

        if(choice2 == "=")
        {
					if(values == choice3)
					{
						cout << "\nItem ID: "<< ItemList[i-11] << endl;
						cout << "Item Name: " << ItemList[i-10] << endl;
						cout << "Item Description: " << ItemList[i-9] <<endl;
						cout << "Item Category: " << ItemList[i-8] << endl;
						cout << "Item Manufacturer: "<< ItemList[i-7] << endl;
						cout << "Selling Price: " <<"RM" << ItemList[i-6]<< endl;
						cout << "Cost Price: " << "RM" << ItemList[i-5] << endl;
						cout << "Units in Store: "<< ItemList[i-4] << endl;
						cout << "Units Sold: " << ItemList[i-3] << endl;
						cout << "Date of Introduction: " << ItemList[i-2] << "-"  <<ItemList[i-1]<< "-" <<"["<< ItemList[i]<<"]"  << endl;
						item_exist = true;
					}
        }

      }
			if(!item_exist) //if item is not found
	    {
	      cout << "There is no such record.\n";
	    }
    }
  }
	else
	{
		cout << "\n\aUnknown option had been entered. Unable to proceed!\n";
	}

	//prompt user to choose to restart display_item() function or continue to proceed
	cout <<"\nWould you like to search another item? \nEnter 'y' to check another item. Enter 'n' to proceed to exit.\n";
	while(counter2==0)
	{
			cin >> restart_func_option;

			if(restart_func_option == "y")
			{
				search_item();
				counter2++;
			}

			else if (restart_func_option == "n")
			{
				counter2++;
			}

			else
			{
				cout << "Please enter a valid choice!\n\n";
			}
	}

	//prompt user to choose toreturn to main() or exit the program
	cout << "\nDo you wish to go back to the main page or exit the program? \nEnter 'y' to go back to main page, 'n' to quit the program.\n";
	while(counter3==0)
	{
			cin >> exit_option;

			if(exit_option == "y")
			{
				main();
				counter3++;
			}

			else if (exit_option == "n")
			{
				exit_program();
				counter3++;
			}

			else
			{
				cout << "Please enter a valid choice!\n\n";
			}

	}


}

void StoreItem::exit_program()// function for user to exit the program
{
	system("cls");
  cout <<  "\nYou have exited the program. Have a nice day! \n\n";
  exit (0);
}
