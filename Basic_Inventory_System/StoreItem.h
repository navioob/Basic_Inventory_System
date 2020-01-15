/**********|**********|**********|
Program: StoreItem.h
Course: Programming Fundamentals
Year: 2018/19 Trimester 1
Name: Boo Ee Kein Ivan
ID: 1161104032
Lecture Section: TC02
Tutorial Section: TT04
Email: 1161104032@student.mmu.edu.my
Phone: 017-3070870
**********|**********|**********/
#ifndef STOREITEM_H_
#define STOREITEM_H_

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

// Global functions
int main();

class StoreItem //constructing class StoreItem
{
  public:
    string Lowercase(string text);
    int Find(string A, string B);
    void insert_item();
    void display_item();
    void delete_item();
    void update_item();
    void search_item();
    void exit_program();
};


#endif
