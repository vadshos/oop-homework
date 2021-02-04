#include "Login.h"
#include"Lib.h"


/// <summary>
/// variabel for counting entered bad password
/// </summary>
size_t Login::counterIncorectPassword = 0;

/// <summary>
/// variabel for assignment role
/// </summary>
Login::ROLE_LIST Login::role = Login::ROLE_LIST::UNDEFINED;

/// <summary>
/// variabel fo connect to DB
/// </summary>
std::string Login::DB = "shop";
std::string Login::host = "localhost";
std::string Login::pass = "zaq19842";
std::string Login::user = "root";
std::string Login::table = "accounts";
int Login::port = 3306;

/// <summary>
/// base class exeption
/// </summary>
class myExeption
{
public:
	myExeption(const std::string& exMessage = "Uknown error") : exMessage(exMessage)
	{}
	virtual const std::string& what() const
	{
		return exMessage;
	}

private:
	std::string exMessage;
};

/// <summary>
/// exeption if user enter incorrect password
/// </summary>
class badPassword : public myExeption
{
public:
	badPassword(const std::string& exMessage = "incorrect password") : myExeption(exMessage)
	{}

};

/// <summary>
/// exeption if user banned
/// </summary>
class banUser : public myExeption
{
public:
	banUser(const std::string& exMessage = "user is banned") : myExeption(exMessage)
	{}

};

/// <summary>
/// exeption if user enter incorrect login
/// </summary>
class badLogin : public myExeption
{
public:
	badLogin(const std::string& exMessage = "incorrect login") : myExeption(exMessage)
	{}
};

void Login::SetColor(int text, int bg)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

/// <summary>
/// head function login
/// </summary>
void Login::menu()
{
	std::string login;
	std::string password;
	try {
		SetColor(0, 15);
		system("mode con cols=26 lines=10");
		std::cout << std::endl;
		std::cout << "\t  LOGIN" << std::endl;
		std::cout << "\t ";
		std::cin >> login;
		std::cout << "\t PASSWORD" << std::endl;
		std::cout << "\t ";
		std::cin >> password;
		isTrueSingIn(login, password);
	}catch (const  banUser& ex) {
		system("cls");
		SetColor(4, 15);
		ex.what();
		Sleep(2000);
	}
	catch (const myExeption& ex ) {
		if (counterIncorectPassword == 3) {
			AdminFunction::banAccount(login);
		}else{
			system("cls");
			SetColor(4, 15);
			std::cout <<"\n\n\n\n"<< ex.what()<< std::endl;
			Sleep(2000);
			SetColor(0, 15);
			ex.what();
			menu();
		}	
	}
	
}

/// <summary>
/// function for gived number role
/// </summary>
/// <returns>return number role</returns>
size_t Login::getRole()
{
	return static_cast<int>(role);
}

/// <summary>
/// function for gived name DB
/// </summary>
/// <returns>return name DB</returns>
std::string Login::getDB()
{
	return DB;
}

/// <summary>
/// function for gived host
/// </summary>
/// <returns>return host</returns>
std::string Login::getHost()
{
	return host;
}

/// <summary>
/// function for gived name user for DB
/// </summary>
/// <returns>return user name </returns>
std::string Login::getUser()
{
	return user;
}

/// <summary>
/// function for gived pass fo DB
/// </summary>
/// <returns>pass fo DB</returns>
std::string Login::getPass()
{
	return pass;
}

/// <summary>
/// function for gived name Table
/// </summary>
/// <returns></returns>
std::string Login::getTable()
{
	return table;
}

/// <summary>
/// function for gived number port
/// </summary>
/// <returns>port</returns>
unsigned int Login::getPort()
{
	return port;
}

/// <summary>
/// function check login data
/// </summary>
/// <param name="login">variabel login</param>
/// <param name="password">ariabel password</param>
/// <returns>return true if user enter correct login and password else thow exeption</returns>
bool Login::isTrueSingIn(const std::string& login, const std::string& password) 
{
	int qstate;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, host.c_str(), user.c_str(), pass.c_str(), DB.c_str(), static_cast<unsigned int>(port), NULL, 0);
	if (conn) {
		std::string query = "SELECT * FROM "+table;
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res))
			{

				std::string isActive = row[4];
				if (isActive == "0") {
					throw banUser();
				}
				if (login == row[1]) {
					if (password == row[2]) {
						std::string roleInDB = row[3];
						if (roleInDB == "user") {
							role = ROLE_LIST::USER;
							UserFunction::menu();
						}
						else if (roleInDB == "admin") {
							role = ROLE_LIST::ADMIN;
							AdminFunction::menu();
						}
						else {
							role = ROLE_LIST::UNDEFINED;
						}
						return 1;
					}
					else {
						counterIncorectPassword++;
						throw badPassword();
					}
				}
			}
			throw badLogin("Such a user does not exist ");
		}
		else
		{
			std::cout << "Query failed: " << mysql_error(conn) << std::endl;
		}
	}
	else {
		puts("Connection to database has failed!");
	}
}
