//
// Created by PC on 12/09/2024.
//

#include "employee.h"
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "account.h"
#include "item.h"
using namespace std;
    void employee:: reset_values(string name,int quantity) {
        item_name=name;
        item_quantity=quantity;
    }
    bool employee::login()  {
        bool exist=false;
            ifstream input("admin.txt");
            int temp_id;
            string temp_password;
        while( input>>temp_id>>temp_password&&!exist) {
            if(temp_id==id&&temp_password==password)
                exist=true;
        }
        input.close();
        if(exist)
            return true;
        return false;
    }
    bool employee::check_existance()  {
        ifstream in("item.txt");
        string temp_name;
        int temp_price;
        int temp_quantity;
        bool check=false;
        while(in>>temp_name>>temp_price>>temp_quantity)
            if(item_name==temp_name)
                check=true;
        in.close();
        if(!check)
            return false;
       return true;
    }
    void employee::show_list() {
        ifstream in("item.txt");
        string temp_name;
        int temp_price;
        int temp_quantity;
        while(in>>temp_name>>temp_price>>temp_quantity){
            cout<<temp_name<<" **  price= "<<temp_price<<" ** quantity= "<<temp_quantity<<"\n";
        }
        in.close();
    }
    void employee::add_item()  {
        set_item_name();
        set_item_price();
        set_item_quantity();
        ofstream out("item.txt",ios::app);
        out<<item_name<<" "<<item_price<<" "<<item_quantity<<"\n";
        out.close();
        cout<<"item added successfully \n";
    }
    void employee::edit_item()  {
        set_item_name();
        ifstream in("item.txt");
        ofstream out("temp_item.txt",ios::app);
        string temp_name;
        int temp_price;
        int temp_quantity;
        while(in>>temp_name>>temp_price>>temp_quantity) {
            if(item_name!=temp_name)
                out<<temp_name<<" "<<temp_price<<" "<<temp_quantity<<"\n";
            else {
                cout<<"plz enter the item quantity that u want to add : \n";
                int quant;
                cin>>quant;
                int total_quantity=quant+temp_quantity;
                out<<temp_name<<" "<<temp_price<<" "<<total_quantity<<"\n";
            }
        }
        in.close();
        out.close();
        remove("item.txt");
        rename("temp_item.txt","item.txt");
        cout<<"item edited successfully \n";
    }
    void employee::delete_item() {
        set_item_name();
        ifstream in("item.txt");
        ofstream out("temp_item.txt",ios::app);
        string temp_name;
        int temp_price;
        int temp_quantity;
        while(in>>temp_name>>temp_price>>temp_quantity) {
            if(item_name!=temp_name)
                out<<temp_name<<" "<<temp_price<<" "<<temp_quantity<<"\n";
        }
        in.close();
        out.close();
        remove("item.txt");
        rename("temp_item.txt","item.txt");
        cout<<"item deleted successfully \n";
    }
    void  employee::delete_zeroes()  {
        ifstream in("item.txt");
        ofstream out("temp_item.txt",ios::app);
        string temp_name;
        int temp_price;
        int temp_quantity;
        while(in>>temp_name>>temp_price>>temp_quantity)
            if(temp_quantity)
                out<<temp_name<<" "<<temp_price<<" "<<temp_quantity<<"\n";
        in.close();
        out.close();
        remove("item.txt");
        rename("temp_item.txt","item.txt");
    }