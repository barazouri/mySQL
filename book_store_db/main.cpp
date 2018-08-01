//
//  main.cpp
//  book_store_db
//
//  Created by bar azouri on 25/07/2018.
//  Copyright © 2018 bar azouri. All rights reserved.
//

#include <stdlib.h>
#include <iostream>
#include "Database.hpp"
#include "book.hpp"
#include "mysql_connection.h"

#include <curses.h>


#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <boost/tokenizer.hpp>
#include <string>

using namespace std;


int main(int argc, const char * argv[]) {
    
//       !!!!!!!  this is the gui  !!!!!!!
//
    int choose;
    string checkStock;
    string checkSupplier;
    while (1)
    {
        cout << "press 1-20 to choose an action.press any other number to exit" << endl << "1.print all books in stock" << endl << "2.show all reservations" << endl << "3.show all client" << endl << "4.show all suppliers" << endl << "5.show all purchase by xx/xx/xxxx-xx/xx/xxxx" << endl << "6.show all books with discount" << endl << "7.check if book is in stock by name book" << endl << "8.show all suppliers of book by book name" << endl << "9.how many coppies of x sells since xx/xx/xxxx" << endl << "10.how many books since xx/xx/xxxx" << endl << "11.client details with most books in store since xx/xx/xxxx" << endl << "12.supplier detalis that most reservation since xx/xx/xxxx" << endl << "13.how many reservation by date xx/xx/xxxx-xx/xx/xxxx" << endl << "14.how many reservetion by date xx/xx/xxxx - xx/xx/xxxx its finaly as a purchase" << endl << "15.what is the discount that client got since xx/xx/xxxx" << endl << "16.all incomes diring quarter q1 q2 q3 q4 in year xxxx" << endl << "17.how many client added since xx/xx/xxxx" << endl << "18.all purchase from supplier between xx/xx/xxxx - xx/xx/xxxx" << endl << "19.all sells of seller between xx/xx/xxxx - xx/xx/xxxx" << endl << "20.list 10 book most sells between xx/xx/xxxx - xx/xx/xxxx" << endl;
        cin >> choose;
        system("cls");
        //        clear();
        switch (choose) {
            case 1:
            {
                print_all_books();
                break;
            }
            case 2:
            {
                print_all_open_reservation();
                break;
            }
            case 3:
            {
                print_all_costumers();
                break;
            }
            case 4:
            {
                print_all_suppliers();
                break;
            }
            case 5:
            {
                string start;
                string end;
                cout << "enter start date: " << endl;
                cin >> start;
                cout << "enter end date: " << endl;
                cin >> end;
                
                print_deal_between_dates(start, end);
                break;
            }
            case 6:
            {
                print_all_books_dicounts();
                break;
            }
            case 7:
            {
                int answer;
                string author_name;
                cout << "would you like to check by book name or by book name and author name?" << endl << "press 1. for book name AND author name" << endl << "press 2. for only by book name" <<endl;
                cin >> answer;
                if (answer == 1) {
                    cout << "enter book name: " << endl;
                    cin >> checkStock;
                    cout << endl << "enter author name: " << endl;
                    cin >> author_name;
                    check_if_onstock_author(checkStock, author_name);
                    break;
                }
                if (answer == 2)
                {
                    cout << "enter book name: ";
                    cin >> checkStock;
                    check_if_onstock(checkStock);
                    break;
                }
            }
            case 8:
            {
                int answer;
                string author_name;
                cout << "would you like to check by book name or by author name or by book name AND author name?" << endl << "press 1. for book name" << endl << "press 2. for author name" << endl << "press 3. for book name AND author name " << endl;
                cin >> answer;
                if (answer == 1) {
                    cout << "enter book name: ";
                    cin >> checkSupplier;
                    check_book_supplier(checkSupplier);
                    break;
                }
                if (answer == 2) {
                    cout << "enter author name: ";
                    cin >> checkSupplier;
                    check_book_supplier_author(checkSupplier);
                    break;
                }
                if (answer == 3) {
                    cout << "enter book name: " <<endl;
                    cin >> checkSupplier;
                    cout << endl << "enter author name: " << endl;
                    cin >> author_name;
                    check_book_supplier_author_book(checkSupplier, author_name);
                    break;
                }
            }
            case 9:
            {
                int answer;
                string author_name;
                string book, date;
                cout << "would you like to check by book name or by author name or by book name AND author name?" << endl << "press 1. for book name" << endl << "press 2. for author name" << endl << "press 3. for book name AND author name " << endl;
                cin >> answer;
                if (answer == 1) {
                    cout << "enter book name: " <<endl;
                    cin >> book;
                    cout << endl << "enter the date: " <<endl;
                    cin >> date;
                    print_all_purchase_of_book_since_y(book, date);
                    break;
                }
                if (answer == 2) {
                    cout << "enter author name: " <<endl;
                    cin >> author_name;
                    cout << endl << "enter the date: " <<endl;
                    cin >> date;
                    print_all_purchase_of_author_since_y(author_name, date);
                    break;
                }
                if (answer == 3) {
                    cout << "enter book name: " <<endl;
                    cin >> book;
                    cout << "enter author name: " << endl;
                    cin >> author_name;
                    cout << endl << "enter the date: " <<endl;
                    cin >> date;
                    print_all_purchase_of_book_author_since_y(book, author_name, date);
                    break;
                }
            }
            case 10:
            {
                int answer;
                string user, date;
                cout << "would you like to check by user name or by user id or by user mobile? or by all the thirds combined" << endl << "press 1. for user name" << endl << "press 2. for user id" << endl << "press 3. for user mobile " << endl << "press 4. for thirds combined" << endl;
                cin >> answer;;
                if (answer == 1) {
                    cout << "enter user name: ";
                    cin >> user;
                    cout << "enter the date: ";
                    cin >> date;
                    print_all_book_cost_z_buy_since_y(user, date);
                    break;
                }
                if (answer == 2) {
                    cout << "enter user id: ";
                    cin >> user;
                    cout << "enter the date: ";
                    cin >> date;
                    print_all_book_cost_userNumber_buy_since_y(user, date);
                    break;
                }
                if (answer == 3) {
                    cout << "enter user mobile: ";
                    cin >> user;
                    cout << "enter the date: ";
                    cin >> date;
                    print_all_book_cost_userPhone_buy_since_y(user, date);
                    break;
                }
                if (answer == 4) {
                    string user_id, user_phone;
                    cout << "enter user name: ";
                    cin >> user;
                    cout << "enter user id: ";
                    cin >> user_id;
                    cout << "enter user phone: ";
                    cin >> user_phone;
                    cout << "enter the date: ";
                    cin >> date;
                    print_all_book_cost_combineThird_buy_since_y(user, user_id, user_phone, date);
                    break;
                }
                
            }
                
            case 11:
            {
                string date;
                cout << "enter the date: ";
                cin >> date;
                print_costumer_buy_most(date);
                
                break;
            }
            case 12:
            {
                string date;
                cout << "enter the date: ";
                cin >> date;
                print_supplier_order_most(date);
                break;
            }
            case 13:
            {
                string start_order;
                string end_order;
                cout << "enter start date: ";
                cin >> start_order;
                cout << "enter end date: ";
                cin >> end_order;
                print_invited_between(start_order,end_order);
                break;
            }
            case 14:
            {
                string start_become;
                string end_become;
                cout << "enter start date: ";
                cin >> start_become;
                cout << "enter end date: ";
                cin >> end_become;
                order_became_sell_between(start_become, end_become);
                break;
            }
                
            case 15:
            {
                string user, date;
                int answer;
                cout << "would you like to check by user name or by user id or by user mobile? or by all the thirds combined" << endl << "press 1. for user name" << endl << "press 2. for user id" << endl << "press 3. for user mobile " << endl << "press 4. for thirds combined" << endl;
                cin >> answer;;
                if (answer == 1) {
                    cout << "enter user name: ";
                    cin >> user;
                    cout << "enter the date: ";
                    cin >> date;
                    total_discount_costumer_since(user, date);
                    break;
                }
                if (answer == 2) {
                    cout << "enter user id: ";
                    cin >> user;
                    cout << "enter the date: ";
                    cin >> date;
                    total_discount_costumer_since_by_id(user, date);
                    break;
                }
                if (answer == 3) {
                    cout << "enter user mobile: ";
                    cin >> user;
                    cout << "enter the date: ";
                    cin >> date;
                    total_discount_costumer_since_by_mobile(user, date);
                    break;
                }
                if (answer == 4) {
                    string user_id, user_mobile;
                    cout << "enter user name: ";
                    cin >> user;
                    cout << "enter user id: ";
                    cin >> user_id;
                    cout << "enter user phone: ";
                    cin >> user_mobile;
                    cout << "enter the date: ";
                    cin >> date;
                    
                    total_discount_costumer_since_by_third_combine(user, user_id, user_mobile, date);
                    
                    
                    break;
                }
                
                
            }
                
            case 16:
            {
                string year;
                cout << "enter year: ";
                cin >> year;
                print_sum_quarter(year);
                break;
            }
                
            case 17:
            {
                string join_date;
                cout << "enter date: ";
                cin >> join_date;
                print_costumer_since_y(join_date);
                break;
            }
            case 18:
            {
                string suplier_id;
                string start_supplier;
                string end_supplier;
                cout << "enter start date: " << endl;
                cin >> start_supplier;
                cout << "enter end date: " << endl;
                cin >> end_supplier;
                cout << "enter supplier id " << endl;
                cin >> suplier_id;
                total_purchase_from_supplier_between(suplier_id, start_supplier,end_supplier);
                break;
            }
            case 19:
            {
                string saller_name;
                string start_saller;
                string end_saller;
                cout << "enter start date: " << endl;
                cin >> start_saller;
                cout << "enter end date: " << endl;
                cin >> end_saller;
                cout << "enter saller name " << endl;
                cin >> saller_name;
                saller_sold_most_between(start_saller, end_saller, saller_name);
                break;
            }
            case 20:
            {
                string start;
                string end;
                cout << "enter start date: " << endl;
                cin >> start;
                cout << "enter end date: " << endl;
                cin >> end;
                print_most_sells_book_between_years(start, end);
                break;
            }
                
            default:
            {
                return 0;
                break;
            }
        }
    }
    return 0;
}
