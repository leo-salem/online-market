//
// Created by PC on 12/09/2024.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "account.h"
#include "item.h"
#include "customer.h"
class customer : public account ,public item{
private:
    vector<pair<string, pair<int, int>>> cart;
public:
    bool registeration();
    int get_price_for_user(string name);
    void reduce_item() ;
    int get_bill() ;
    void get_shopping_cart() ;
    void update_file() ;
    bool check_enough_quantity();
    bool login() override ;
    bool check_existance() override ;
    void show_list() override;
    void add_item() override ;
    void edit_item() override ;
    void delete_item() override ;
    void delete_zeroes() override ;
};



#endif //CUSTOMER_H
