#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "account.h"
#include "item.h"
#include "employee.h"
#include "customer.h"
using namespace std;
/*------------------------*/
signed main() {
    cout<<"--------------------------------\n";
    cout<<"welcome to salem online market \n";
    cout<<"--------------------------------\n";
    bool outter_check=false;
    while(!outter_check) {
        cout<<"plz define ur identity : \n";
        cout<<"(1)_employee \n";
        cout<<"(2)_customer \n";
        cout<<"(3)_exit\n";
        int identity;
        cin>>identity;
        employee admin;
        customer user;
        account *poineter=&admin,*poineter2=&user;
        item *p1=&admin,*p2=&user;
        if (identity==1) {
            bool inner_check=false;
            while (!inner_check) {
                cout<<"plz choose the way u want to enter by : \n";
                cout<<"(1)_login an account\n";
                cout<<"(2)_exit\n";
                int choise;
                cin>>choise;
                if(choise==1) {
                    poineter->set_id();
                    poineter->set_password();
                    if(poineter->login()) {
                        cout<<"ur login is done successfully \n";
                        inner_check=true;
                        outter_check=true;
                    }
                    else
                        cout<<"this id or password is wrong \n";
                }
                else
                    break;
            }
            if(inner_check) {
                while(true) {
                    cout<<"plz choose the operation u want to do : \n";
                    cout<<"(1)_add item \n";
                    cout<<"(2)_delete item \n";
                    cout<<"(3)_edit item\n";
                    cout<<"(4)_show list \n";
                    cout<<"(5)_exit\n";
                    int choise;
                    cin>>choise;
                    if(choise==1)
                        p1->add_item();
                    else if(choise==2)
                        p1->delete_item();
                    else if(choise==3)
                        p1->edit_item();
                    else if (choise==4)
                        p1->show_list();
                    else
                        break;
                }
                cout<<"**********************************************************\n";
                cout<<"great job our admin thank u for ur efforts and keep going \n";
                cout<<"**********************************************************\n";
            }
        }
        else if(identity==2){
            bool inner_check=false;
            while (!inner_check) {
                cout<<"plz choose the way u want to enter by : \n";
                cout<<"(1)_register new account \n";
                cout<<"(2)_login an account \n";
                cout<<"(3)_exit \n";
                int operation;
                cin>>operation;
                if(operation==1) {
                    user.set_id();
                    user.set_password();
                    if (user.registeration()) {
                        cout<<"ur regesteraton is done successfully \n";
                        inner_check=true;
                        outter_check=true;
                    }
                    else
                        cout<<"this id or password is already exist \n";
                }
                else if(operation==2) {
                    poineter2->set_id();
                    poineter2->set_password();
                    if(poineter2->login()) {
                        cout<<"ur login is done successfully \n";
                        inner_check=true;
                        outter_check=true;
                    }
                    else
                        cout<<"this id or password is wrong \n";
                }
                else
                    break;
            }
            if(inner_check) {
                cout<<"plz enter the money u have\n";
                int wallet;
                cin>>wallet;
                while(true) {
                    cout<<"plz choose the operation u want to do : \n";
                    cout<<"(1)_take item\n";
                    cout<<"(2)_delete item\n";
                    cout<<"(3)_reduce item\n";
                    cout<<"(4)_show shopping cart\n";
                    cout<<"(5)_check bill\n";
                    cout<<"(6)_show list\n";
                    cout<<"(7)_no thanks \n";
                    int want;
                    cin>>want;
                    if(want==1) {
                        p2->set_item_name();
                        p2->set_item_quantity();
                        admin.reset_values(user.get_item_name(),user.get_item_quantity());
                        if (p1->check_existance()) {
                            if(!p2->check_existance()) {
                                if(user.check_enough_quantity())
                                    p2->add_item();
                                else
                                    cout<<"sorry the rest of this element is not enough !\n";
                            }
                            else {
                                if(user.check_enough_quantity())
                                    p2->edit_item();
                                else
                                    cout<<"sorry the rest of this element is not enough !\n";
                            }
                        }
                        else
                            cout<<"sorry this element is not in our list !\n";
                    }
                    else if(want==2)
                        p2->delete_item();
                    else if(want==3)
                        user.reduce_item(),p2->delete_zeroes();
                    else if(want==4)
                        user.get_shopping_cart();
                    else if(want==5) {
                        if(wallet>=user.get_bill()) {
                            user.get_shopping_cart();
                            p2->delete_zeroes();
                            cout<<"ur bill = : ";
                            cout<<user.get_bill()<<" $";
                            cout<<"\n";
                            user.update_file();
                            p1->delete_zeroes();
                        }
                        else {
                            bool thanks=false;
                            while (wallet<user.get_bill()&&!thanks) {
                                cout<<"sorry u don not have enough money !\n";
                                cout<<"plz choose the next operation to do \n";
                                cout<<"(1)_reduce purchases \n";
                                cout<<"(2)_delete item\n";
                                cout<<"(3)_show shopping cart \n";
                                cout<<"(4)_no thanks \n";
                                int does;
                                cin>>does;
                                if(does==1)
                                    user.reduce_item();
                                else if(does==2)
                                    p2->delete_item();
                                else if(does==3)
                                    user.get_shopping_cart();
                                else
                                    thanks=true;
                            }
                        }
                    }
                    else if(want==6)
                        p2->show_list();
                    else
                        break;
                }
                cout<<"********************************************\n";
                cout<<"thank u for using salem online market \n";
                cout<<"********************************************\n";
            }
        }
        else
            break;
    }
}