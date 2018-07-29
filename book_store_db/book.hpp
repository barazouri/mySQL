//
//  book.hpp
//  book_store_db
//
//  Created by bar azouri on 25/07/2018.
//  Copyright © 2018 bar azouri. All rights reserved.
//

#ifndef book_hpp
#define book_hpp

#include <stdio.h>
#include <iostream>
#include "Database.hpp"
#include <boost/date_time/posix_time/posix_time.hpp>

#include "mysql_connection.h"

using namespace std;
using namespace boost::posix_time;
using namespace boost::gregorian;

void print_all_books();
void print_all_books_dicounts();
void print_all_costumers();
void print_all_suppliers();
void check_if_onstock(string checkStock);
void print_costumer_since_y(const string &date);
#endif /* book_hpp */

