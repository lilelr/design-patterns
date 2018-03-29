//
// Created by YuXiao on 3/29/18.
//
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Connection{
public:
    virtual void connect() = 0;

};

class OracleConnection :public Connection{
public:
    void connect(){
        cout<<"Oracle Connects"<<endl;
    }
};

class MYSQLConnection :public Connection{
public:
    void connect(){
        cout<<"Mysql Connects"<<endl;
    }
};

class Statement{
public:
    virtual void execute_statement()= 0;
};

class OracleStatement : public Statement{
public:
    void execute_statement(){
        cout<<"Oracle statement"<<endl;
    }
};
class MysqlStatement : public Statement{
public:
    void execute_statement(){
        cout<<"Mysql statement"<<endl;
    }
};

class DBFactory{
public:
    virtual  Connection* create_connection() = 0;
    virtual  Statement*  create_statement() = 0;

};


class OracleFactory : public DBFactory{
public:
    Connection* create_connection(){
        return   new OracleConnection();
    }
    Statement* create_statement(){
        return new OracleStatement();
    }
};

int main(){
    DBFactory* oracle_factory = new OracleFactory();
    Connection* connection = oracle_factory->create_connection();
    connection->connect();
    Statement* statement = oracle_factory->create_statement();
    statement->execute_statement();
}
