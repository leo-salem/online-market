//
// Created by PC on 12/09/2024.
//

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "account.h"
using namespace std;

class account {
protected:
    int id ;
    string password;
public:
    account() ;
    void set_id();
    void set_password() ;
    int get_id();
    string get_password();
    virtual bool login()=0;
};



#endif //ACCOUNT_H
