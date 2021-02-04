#include "AdminFunction.h"
#include <mysql.h>



void AdminFunction::menu()
{

	std::vector<std::string> list{ "Show category","Add accounts","Ban account","Erase account","Changer password user","Add product","Erase product","Exit" };
	while (true) {
		size_t achion = 0;
		int a = 0;
		while (a != 13) {
			system("cls");
			for (int i = 0; i < list.size(); i++) {
				if (i == achion) {
					Login::SetColor(0, 14);
				}
				if (i != achion) {
					Login::SetColor(0, 15);
				}
				std::cout << (*(list.begin() + i)) << std::endl;
				Login::SetColor(0, 15);
			}
			a = _getch();
			if (a == 119) {
				achion--;
				if (achion < 0) {
					achion = list.size();
				}
			}

			else if (a == 115) {
				achion++;
				if (achion > list.size()) {
					achion = 0;
				}
			}
		}
		std::cin.ignore();
		if (achion == 0) {
			BaseFunctionForUsers::showCategory();
		}
		else if (achion == 1) {
			std::string login;
			std::string password;
			std::string role;
			std::cout << "Login ->";
			std::getline(std::cin, login);
			std::cout << "Password ->";
			std::getline(std::cin, password);
			std::cout << "Role ->";
			std::getline(std::cin, role);
			addAccount(login, password, role);
		}
		else if (achion == 2 or achion == 3) {
			std::string login;
			std::cout << "Login ->";
			std::getline(std::cin, login);
			if (achion == 2)
				banAccount(login);
			else
				eraseAccount(login);
		}
		else if (achion == 4) {
			std::string login;
			std::string password;
			std::cout << "Login ->";
			std::getline(std::cin, login);
			std::cout << "Password ->";
			std::getline(std::cin, password);
			changeAccountPassword(login, password);
		}
		else if (achion == 5) {
		}
		else if (achion == 6) {
		}
		else if (achion == 7) {
			break;
		}
	}
}

void AdminFunction::addAccount(const std::string& login, const std::string& password,const std::string role)
{
	int qstate;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, Login::getHost().c_str(), Login::getUser().c_str(), Login::getPass().c_str(), Login::getDB().c_str(), Login::getPort(), NULL, 0);
	if (conn) {
		std::string query = "INSERT INTO accounts(Id,login,password,role,activity) VALUES (1,\"login\",\""+password+"\",\""+role+"\",1);";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
		}
	}
}

void AdminFunction::banAccount(const std::string& login)
{
	int qstate;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, Login::getHost().c_str(), Login::getUser().c_str(), Login::getPass().c_str(), Login::getDB().c_str(), Login::getPort(), NULL, 0);
	if (conn) {
		std::string query = "UPDATE "+Login::getTable()+"  SET activity = 0 WHERE login = '" + login + "'";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
		}
	}
}

void AdminFunction::eraseAccount(const std::string& login)
{
	int qstate;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, Login::getHost().c_str(), Login::getUser().c_str(), Login::getPass().c_str(), Login::getDB().c_str(), Login::getPort(), NULL, 0);
	if (conn) {
		std::string query = "DELETE FROM " + Login::getTable() + "  WHERE login = '" + login +"'";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
		}
	}
}

void AdminFunction::changeAccountPassword(const std::string& login, const std::string& password)
{
	int qstate;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, Login::getHost().c_str(), Login::getUser().c_str(), Login::getPass().c_str(), Login::getDB().c_str(), Login::getPort(), NULL, 0);
	if (conn) {
		std::string query = "UPDATE " + Login::getTable() + "  SET password = '"+password+"' WHERE login = '" + login + "'";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
		}
	}
}
