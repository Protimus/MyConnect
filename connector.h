/* Classes para uso do MySQL Connector C++ 
** @author: Rafael P. da Costa Gorges
** @date: 12/02/2015
**/

#ifndef CONNECTOR_H_
#define CONNECTOR_H_

// Bibliotecas do MySQL C++ Connector
#include <mysql/mysql.h>
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <iostream>
#include <string>

// Informações para a conexão com o MySQL
#define MyAddress "localhost"
#define MyUser "root"
#define MyPass "root"
#define MyDB "teste"

using namespace std;

/* Classe para uso do MySQL Connector C++ */
class MySQLConnector {
private: // Privadas: Estados executados pelo MySQL Connector C++
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;
public: // Públicas: Funções de uso geral no código
	MySQLConnector();
	virtual ~MySQLConnector();
	bool conecta();
	bool desconecta();
	char getSysdate();
};

#endif