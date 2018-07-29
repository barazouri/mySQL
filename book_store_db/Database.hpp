//
//  Database.hpp
//  book_store_db
//
//  Created by bar azouri on 25/07/2018.
//  Copyright © 2018 bar azouri. All rights reserved.
//

#ifndef Database_hpp
#define Database_hpp

#include <stdio.h>

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <boost/tokenizer.hpp>

using namespace sql;
using namespace std;
#define DB_NAME "book_store"
#define DB_HOST "tcp://127.0.0.1/"
#define DB_PORT 3306
#define DB_USER "root"
#define DB_PASS ""

class Database {
private:
    // singleton instance
    static Database *instance;
    
    Driver *driver;
    ConnectOptionsMap connection_properties;
    
    // private CTOR (singleton)
    Database();
public:
    static Database& getInstance();
    
    Connection *getConnection();
    
    virtual ~Database() {}
};

#endif /* Database_hpp */
