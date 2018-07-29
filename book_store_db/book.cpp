//
//  book.cpp
//  book_store_db
//
//  Created by bar azouri on 25/07/2018.
//  Copyright © 2018 bar azouri. All rights reserved.
//

#include "book.hpp"

void print_all_books() {
    int n = 0;
    int i = 1;
    int j = 0;
    
    while (1)
    {
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM book LIMIT 5 OFFSET ?");
        pstmt->setInt(1, n);
        ResultSet *res = pstmt->executeQuery();
        /* Fetch in reverse = descending order! */
        if (!res->next() && n>0)                            //if there is no next
        {
            cout << endl << "there is no next data!" << endl;
            n -= 5;
            i -= j;
            j = 0;
            delete res;
            delete pstmt;
            pstmt = con->prepareStatement("SELECT * FROM book LIMIT 5 OFFSET ?");
            pstmt->setInt(1, n);
            res = pstmt->executeQuery();
        }
        else {
            j = 0;
        }
        res->beforeFirst();
        while (res->next())
        {
            cout << "book: " << i << endl << "id: " << res->getString("id") << endl << "book name: " << res->getString("book_name") << endl << "book author: " << res->getString("book_author") << endl << "book type: " << res->getString("book_type") << "book price: " << res->getString("book_price") << endl << "book stock: " << res->getString("book_stock") << endl << endl;            i++;
            j++;
        }
        
        cout << endl << endl << "1.next" << endl << "2.prev" << endl << "other number to main menu" << endl;
        int choose;
        cin >> choose;
        switch (choose) {
            case 1:
            {
                system("clear");
                n += 5;
                break;
            }
            case 2:
            {
                if (n >= 5)
                {
                    system("clear");
                    n -= 5;
                    i -= j + 5;
                }
                else
                {
                    system("clear");
                    i -= j;
                    j = 0;
                    cout << endl << "there is no prev data!" << endl;
                }
                break;
            }
            default:
            {
                return;
            }
        }
        delete res;
        delete con;
        delete pstmt;
    }
}


void print_all_books_dicounts() {
    int n = 0;
    int i = 1;
    int j = 0;
    
    while (1)
    {
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM book_discount LIMIT 5 OFFSET ?");
        pstmt->setInt(1, n);
        ResultSet *res = pstmt->executeQuery();
        /* Fetch in reverse = descending order! */
        if (!res->next() && n>0)                            //if there is no next
        {
            cout << endl << "there is no next data!" << endl;
            n -= 5;
            i -= j;
            j = 0;
            delete res;
            delete pstmt;
            pstmt = con->prepareStatement("SELECT * FROM book_discount LIMIT 5 OFFSET ?");
            pstmt->setInt(1, n);
            res = pstmt->executeQuery();
        }
        else {
            j = 0;
        }
        res->beforeFirst();
        while (res->next())
        {
            cout << "book: " << i << endl << "id: " << res->getString("id") << endl << "book name: " << res->getString("book_name") << endl << "book discount: " << res->getString("book_dicount") << endl << endl;
            i++;
            j++;
        }
        
        cout << endl << endl << "1.next" << endl << "2.prev" << endl << "other number to main menu" << endl;
        int choose;
        cin >> choose;
        switch (choose) {
            case 1:
            {
                system("clear");
                n += 5;
                break;
            }
            case 2:
            {
                if (n >= 5)
                {
                    system("clear");
                    n -= 5;
                    i -= j + 5;
                }
                else
                {
                    system("clear");
                    i -= j;
                    j = 0;
                    cout << endl << "there is no prev data!" << endl;
                }
                break;
            }
            default:
            {
                return;
            }
        }
        delete res;
        delete con;
        delete pstmt;
    }
}



void print_all_costumers() {
    int n = 0;
    int i = 1;
    int j = 0;
    
    while (1)
    {
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM costumer LIMIT 5 OFFSET ?");
        pstmt->setInt(1, n);
        ResultSet *res = pstmt->executeQuery();
        
        if (!res->next() && n>0)                            //if there is no next
        {
            cout << endl << "there is no next data!" << endl;
            n -= 5;
            i -= j;
            j = 0;
            delete res;
            delete pstmt;
            pstmt = con->prepareStatement("SELECT * FROM costumer LIMIT 5 OFFSET ?");
            pstmt->setInt(1, n);
            res = pstmt->executeQuery();
        }
        else {
            j = 0;
        }
        res->beforeFirst();
        while (res->next())
        {
            cout << "costumer: " << i << endl << "id: " << res->getString("user_id") << endl << "user name: " << res->getString("user_name") << endl << "user mobile: " << res->getString("user_mobile") << endl << "user email: " << res->getString("user_email") << "user address: " << res->getString("user_address") <<endl<<"join date: "<<res->getString("join_date")<< endl << endl;
            i++;
            j++;
        }
        
        cout << endl << endl << "1.next" << endl << "2.prev" << endl << "other number to main menu" << endl;
        int choose;
        cin >> choose;
        switch (choose) {
            case 1:
            {
                system("clear");
                n += 5;
                break;
            }
            case 2:
            {
                if (n >= 5)
                {
                    system("clear");
                    n -= 5;
                    i -= j + 5;
                }
                else
                {
                    system("clear");
                    i -= j;
                    j = 0;
                    cout << endl << "there is no prev data!" << endl;
                }
                break;
            }
            default:
            {
                return;
            }
        }
        delete res;
        delete con;
        delete pstmt;
    }
}


void print_all_suppliers() {
    int n = 0;
    int i = 1;
    int j = 0;
    
    while (1)
    {
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM supplier LIMIT 5 OFFSET ?");
        pstmt->setInt(1, n);
        ResultSet *res = pstmt->executeQuery();
        /* Fetch in reverse = descending order! */
        if (!res->next() && n>0)                            //if there is no next
        {
            cout << endl << "there is no next data!" << endl;
            n -= 5;
            i -= j;
            j = 0;
            delete res;
            delete pstmt;
            pstmt = con->prepareStatement("SELECT * FROM supplier LIMIT 5 OFFSET ?");
            pstmt->setInt(1, n);
            res = pstmt->executeQuery();
        }
        else {
            j = 0;
        }
        res->beforeFirst();
        while (res->next())
        {
            cout << "supplier: " << i << endl << "supplier id: " << res->getString("supplier_id") << endl << "supplier name: " << res->getString("supplier_name") << endl << "supplier phone: " << res->getString("supplier_phone") << endl << "supplier email: " << res->getString("supplier_email") << endl << endl;
            i++;
            j++;
        }
        
        cout << endl << endl << "1.next" << endl << "2.prev" << endl << "other number to main menu" << endl;
        int choose;
        cin >> choose;
        switch (choose) {
            case 1:
            {
                system("clear");
                n += 5;
                break;
            }
            case 2:
            {
                if (n >= 5)
                {
                    system("clear");
                    n -= 5;
                    i -= j + 5;
                }
                else
                {
                    system("clear");
                    i -= j;
                    j = 0;
                    cout << endl << "there is no prev data!" << endl;
                }
                break;
            }
            default:
            {
                return;
            }
        }
        delete res;
        delete con;
        delete pstmt;
    }
}


void check_if_onstock(string checkStock) {
    Database &db = Database::getInstance();
    Connection *con = db.getConnection();
    PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM book WHERE book_name = ? AND book_stock = ? ");
    pstmt->setString(1, checkStock);
    pstmt->setString(2, "1");
    ResultSet *res = pstmt->executeQuery();
    if (!res->next()) {
        cout << "book is not exist" <<endl;
    }
    else {
        cout << "book exist" << endl;
    }
}

void print_costumer_since_y(const string &date){
    int n = 0;
    int i = 1;
    int j = 0;
    
    while (1)
    {
        Database &db = Database::getInstance();
        Connection *con = db.getConnection();
        PreparedStatement *pstmt = con->prepareStatement("SELECT * FROM costumer WHERE join_date >= ? LIMIT 5  OFFSET ? ");
        pstmt->setString(1, date);
        pstmt->setInt(2, n);
        ResultSet *res = pstmt->executeQuery();
        
        if (!res->next() && n>0)                            //if there is no next
        {
            cout << endl << "there is no next data!" << endl;
            n -= 5;
            i -= j;
            j = 0;
            delete res;
            delete pstmt;
            pstmt = con->prepareStatement("SELECT * FROM costumer LIMIT 5 OFFSET ?");
            pstmt->setInt(1, n);
            res = pstmt->executeQuery();
        }
        else {
            j = 0;
        }
        res->beforeFirst();
        while (res->next())
        {
            cout << "costumer: " << i << endl << "id: " << res->getString("user_id") << endl << "user name: " << res->getString("user_name") << endl << "user mobile: " << res->getString("user_mobile") << endl << "user email: " << res->getString("user_email") << "user address: " << res->getString("user_address") <<endl<<"join date: "<<res->getString("join_date")<< endl << endl;
            i++;
            j++;
        }
        
        cout << endl << endl << "1.next" << endl << "2.prev" << endl << "other number to main menu" << endl;
        int choose;
        cin >> choose;
        switch (choose) {
            case 1:
            {
                system("clear");
                n += 5;
                break;
            }
            case 2:
            {
                if (n >= 5)
                {
                    system("clear");
                    n -= 5;
                    i -= j + 5;
                }
                else
                {
                    system("clear");
                    i -= j;
                    j = 0;
                    cout << endl << "there is no prev data!" << endl;
                }
                break;
            }
            default:
            {
                return;
            }
        }
        delete res;
        delete con;
        delete pstmt;
    }
    
}

