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
    while (1)
    {
        cout << "press 1-20 to choose an action.press any other number to exit" << endl << "1.print all books in stock" << endl << "2.show all reservations" << endl << "3.show all client" << endl << "4.show all suppliers" << endl << "5.show all purchase by xxxx-xx-xx - xxxx-xx-xx" << endl << "6.show all books with discount" << endl << "7.check if book is in stock by name book" << endl << "8.show all suppliers of book by book name" << endl << "9.how many coppies of x sells since xxxx-xx-xx" << endl << "10.how many books since xxxx-xx-xx" << endl << "11.client details with most books in store since xxxx-xx-xx" << endl << "12.supplier detalis that most reservation since xxxx-xx-xx" << endl << "13.how many reservation by date xxxx-xx-xx - xxxx-xx-xx" << endl << "14.how many reservetion by date xxxx-xx-xx - xxxx-xx-xx its finaly as a purchase" << endl << "15.what is the discount that client got since xxxx-xx-xx" << endl << "16.all incomes diring quarter q1 q2 q3 q4 in year xxxx" << endl << "17.how many client added since xxxx-xx-xx" << endl << "18.all purchase from supplier between xxxx-xx-xx - xxxx-xx-xx" << endl << "19.all sells of seller between xxxx-xx-xx - xxxx-xx-xx" << endl << "20.list 10 book most sells between xxxx-xx-xx - xxxx-xx-xx" << endl;
        cin >> choose;
        system("clear");
        //        clear();
        switch (choose) {
            case 1:
            {
                print_all_books();
                break;
            }
            case 2:
            {
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
                break;
            }
            case 6:
            {
                print_all_books_dicounts();
                break;
            }
            case 7:
            {
                string checkStock;
                cout << "enter book name: ";
                cin >> checkStock;
                check_if_onstock(checkStock);
                break;
            }
            case 8:
            {
                break;
            }
            case 9:
            {
                break;
            }
            case 10:
            {
                break;
            }
                
            case 11:
            {
                break;
            }
            case 12:
            {
                break;
            }
            case 13:
            {
                break;
            }
            case 14:
            {
                break;
            }
                
            case 15:
            {
                break;
            }
            case 16:
            {
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
                break;
            }
            case 19:
            {
                break;
            }
            case 20:
            {
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
