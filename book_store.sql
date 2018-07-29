create database if not exists book_store;
use book_store;

create table if not exists costumer(
	user_id char(50) primary key, 
	user_name char(50), 
	user_mobile char(50), 
	user_email char(50),
	user_address char(50)
);

create table if not exists book (
	id varchar(50) primary key,
    book_name varchar(50),
    book_author varchar(50),
    book_type varchar(50),
    book_price float(7,2),
    book_stock bool
);

create table if not exists supplier(
	supplier_name varchar(50),
    supplier_id varchar(50) primary key,
	supplier_phone int(50),
    supplier_email varchar(50)
);

create table if not exists books_suppliers(
	book_id varchar(50),
    supplier_id varchar(50),
    primary key(book_id, supplier_id),
    foreign key(book_id) references book(id), 
	foreign key(supplier_id) references supplier(supplier_id) 
);

create table if not exists purchase(
	purchase_id char(50) primary key,
	amount_to_paid float(7,2),
	price float(7,2),
	book_ISBN char(50),
	seller_name char(50)
);

create table if not exists sales_and_discount(
	sales_id char(50) primary key,
	amount_to_pay float(7,2),
	amount_paid float(7,2),
	balance  float(7,2)
);

create table if not exists purchase_record(
	purchase_id varchar(50),
    amount_to_pay float(7,2),
    primary key(purchase_id),
	price float(7,2),
    book_ISBN varchar(50),
    saller_name varchar(50)
);

/*DESCRIBE costumer; 
DESCRIBE book;
DESCRIBE supplier;
DESCRIBE books_suppliers;
DESCRIBE purchase; 
DESCRIBE sales_and_discount;
DESCRIBE purchase_record;
*/
/*
select * from books b inner join books_suppliers bs on b.id = bs.book_id
	inner join supplier s on bs.supplier_id = s.supplier_id;*/