//
// Created by PC on 12/09/2024.
//

#include "customer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "account.h"
#include "item.h"
#include "customer.h"
bool customer::registeration(){
        bool exist=false;
        ifstream input("user.txt");
        int temp_id;
        string temp_password;
        while(input>>temp_id>>temp_password&&!exist) {
            if(temp_id==id||temp_password==password)
                exist=true;
        }
        input.close();
        ifstream in("admin.txt");
        int check_id;
        string check_password;
        while(in>>check_id>>check_password&&!exist) {
            if(check_id==id||check_password==password)
                exist=true;
        }
        if(exist)
            return false;
        ofstream output("user.txt",ios::app);
        output<<id<<" "<<password<<"\n";
        output.close();
        in.close();
        return true;
    }
    int customer::get_price_for_user(string name) {
        ifstream in("item.txt");
        string temp_name;
        int temp_price;
        int temp_quantity;
        int check;
        while(in>>temp_name>>temp_price>>temp_quantity) {
            if(name==temp_name) {
                check=temp_price;
                break;
            }
        }
        in.close();
        return check;
    }
    void customer::reduce_item() {
        cout<<"plz enter the item name u want to reduce \n";
        string name;
        cin>>name;
        cout<<"plz enter appropriate quantity u want to reduce \n";
        int quant ;
        cin>>quant ;
        for(auto &x : cart) {
            if(name==x.first) {
                x.second.second-=quant;
                break;
            }
        }
        cout<<"item quantity reduced sucessfully\n";
    }
    int customer::get_bill() {
        int cost=0;
        for(auto &x : cart) {
            ifstream in("item.txt");
            string temp_name;
            int temp_price;
            int temp_quantity;
            while(in>>temp_name>>temp_price>>temp_quantity) {
                if(temp_name==x.first) {
                    cost+=(temp_price*x.second.second);
                    break;
                }
            }
            in.close();
        }
        return cost;
    }
    void customer::get_shopping_cart() {
        cout<<"sir what did u buy till now is : \n";
        for(auto &x : cart)
            cout<<x.first<<" **  price= "<<x.second.first<<" ** quantity = "<<x.second.second<<"\n";
        cout<<"total cost = "<<get_bill()<<" $\n";
    }
    void customer::update_file() {
        for(auto &x : cart) {
            ifstream in("item.txt");
            ofstream out("temp_item.txt",ios::app);
            string temp_name;
            int temp_price;
            int temp_quantity;
            while(in>>temp_name>>temp_price>>temp_quantity) {
                if(x.first!=temp_name) {
                    out<<temp_name<<" "<<temp_price<<" "<<temp_quantity<<"\n";
                }
                else {
                    temp_quantity-=x.second.second;
                    out<<temp_name<<" "<<temp_price<<" "<<temp_quantity<<"\n";
                }
            }
            in.close();
            out.close();
            remove("item.txt");
            rename("temp_item.txt","item.txt");
        }
    }
    bool customer::check_enough_quantity() {
        ifstream in("item.txt");
        string temp_name;
        int temp_price;
        int temp_quantity;
        bool check=false;
        while(in>>temp_name>>temp_price>>temp_quantity) {
            if(item_name==temp_name&&temp_quantity>=item_quantity)
                check=true;
        }
        in .close();
        if(!check)
            return false;
        return true;
    }
    bool customer::login()  {
        bool exist=false;
        ifstream input("user.txt");
        int temp_id;
        string temp_password;
        while(input>>temp_id>>temp_password&&!exist) {
            if(temp_id==id&&temp_password==password)
                exist=true;
        }
        input.close();
        if(exist)
            return true;
        return false;
    }
    bool customer::check_existance()  {
        for(auto &x : cart)
            if(x.first==item_name)
                return true;;
        return false;
    }
    void customer::show_list()  {
        ifstream in("item.txt");
        string temp_name;
        int temp_price;
        int temp_quantity;
        while(in>>temp_name>>temp_price>>temp_quantity){
            cout<<temp_name<<" **  price= "<<temp_price<<"\n";
        }
        in.close();
    }
    void customer::add_item()  {;
        int prce=get_price_for_user(item_name);
        cart.push_back({item_name,{prce,item_quantity}});
        cout<<"item added to shopping cart successfully \n";
    }
    void customer::edit_item()  {
        for(auto &x:cart) {
            if(item_name==x.first) {
                x.second.second+=item_quantity;
                break;
            }
        }
        cout<<"item edited in shopping cart successfully \n";
    }
    void customer::delete_item()  {
        cout<<"plz enter the name item u want to delete\n";
        string name;
        cin>>name;
        vector<pair<string,pair<int,int>>>temp;
        for(auto &x : cart) {
            if(x.first!=name) {
                temp.push_back(x);
            }
        }
        cart=temp;
        cout<<"item deleted from shopping cart successfully \n";
    }
    void customer::delete_zeroes()  {
        vector<pair<string,pair<int,int>>>temp;
        for(auto &x : cart) {
            if(x.second.second) {
                temp.push_back(x);
            }
        }
        cart=temp;
    }