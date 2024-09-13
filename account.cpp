//
// Created by PC on 12/09/2024.
//

#include "account.h"
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
    account::account() {
        id=0;
        password="00000000";
    }
    void account:: set_id() {
        cout<<"enter ur id plz : ";
        int x;
        cin>>x;
        id=x;
    }
    void account:: set_password() {
        cout<<"enter ur password plz : ";
        string x;
        cin>>x;
        password=x;
    }
    int account:: get_id(){
        return id;
    }
    string account:: get_password() {
        return password;
    }