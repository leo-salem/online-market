//
// Created by PC on 12/09/2024.
//

#ifndef ITEM_H
#define ITEM_H
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "item.h"
using namespace std;
class item {
protected:
    string item_name;
    int item_price,item_quantity;
public:
    item();
    void set_item_name() ;
    void set_item_price() ;
    void set_item_quantity();
    string get_item_name();
    int get_item_price() ;
    int get_item_quantity() ;
    virtual bool check_existance()=0;
    virtual void show_list()=0;
    virtual void add_item()=0;
    virtual void edit_item()=0;
    virtual void delete_item()=0;
    virtual void delete_zeroes()=0;
};



#endif //ITEM_H
