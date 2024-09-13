//
// Created by PC on 12/09/2024.
//

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "account.h"
#include "item.h"
#include "employee.h"
using namespace std;
class employee : public account,public item {
public:
    void reset_values(string name,int quantity) ;
    bool login() override;
    bool check_existance() override ;
    void show_list() override;
    void add_item() override;
    void edit_item() override;
    void delete_item() override;
    void  delete_zeroes() override;
};



#endif //EMPLOYEE_H
