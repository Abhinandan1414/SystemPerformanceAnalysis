#!/usr/bin/expect

set password  root
spawn mysql -u root -p 
# You need to be in su priveleges 
# Limitation of MySQL on Ubuntu

expect "password:"
send "$password\r\n"
expect "mysql"
send "create database temp3;\r\n"
expect "OK"
send "use temp3;\r\n"
expect "changed"
send "create table emp(id int(10),name varchar(40),age int(3));\r\n"
expect "OK"
send "insert into emp (id,name,age) values (1,\"Abhi\",42);\r\n"
expect "OK"
send "insert into emp (id,name,age) values (2,\"Sangeeta\",42);\r\n"
expect "OK"
send "insert into emp (id,name,age) values (3,\"Ishan\",42);\r\n"
expect "OK"
send "insert into emp (id,name,age) values (1,\"Shivu\",42);\r\n"
expect "OK"
send "select * from emp;\r\n"
expect "Abhi"
send "exit;\r\n"
expect "Bye"
interact
