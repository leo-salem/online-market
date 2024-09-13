//
// Created by PC on 12/09/2024.
//

#include "item.h"
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

item::item() {
    item_name="empty";
    item_price=0;
    item_quantity=0;
}
void item:: set_item_name() {
    cout<<"enter item name plz : ";
    string x;
    cin>>x;
    item_name=x;
}
void item::set_item_price() {
    cout<<"enter item price plz : ";
    int x;
    cin>>x;
    item_price=x;
}
void item:: set_item_quantity() {
    cout<<"enter item quantity plz : ";
    int x;
    cin>>x;
    item_quantity=x;
}
string item::get_item_name(){
    return item_name;
}
int item::get_item_price() {
    return item_price;
}
int item::get_item_quantity() {
    return item_quantity;
}