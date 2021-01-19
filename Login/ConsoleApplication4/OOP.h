#pragma once
#include <iostream>
#include"windows.h"
#include<string>

#include<fstream>
#define Clear system("cls");

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
/// //
/// </summary>
class badPassword : public myExeption
{
public:
	badPassword(const std::string& exMessage = "incorrect password") : myExeption(exMessage)
	{}
	
};
class badLogin : public myExeption
{
public:
	badLogin(const std::string& exMessage = "incorrect login") : myExeption(exMessage)
	{}
};

class ExeptionUserIsAlreadyCreate : public myExeption
{
public:
	ExeptionUserIsAlreadyCreate(const std::string& login, const std::string& exMessage = "user is already create") : myExeption(exMessage), errLogin(login)
	{};
	const std::string& getErrLogin() {
		return errLogin;
	}
private:
	std::string errLogin;
};

class Register
{
public:
	bool reg(const std::string& login, const std::string& password) {
		std::ifstream singIn;
		singIn.open("login.txt");
		while (!singIn.eof()) {
			std::string l;
			std::string p;
			getline(singIn, l);
			getline(singIn, p);
			if (l == login) {
				throw ExeptionUserIsAlreadyCreate(login);
			}
		}
		
		if (password.size() >= 8) {
			bool haveLover = false;
			bool haveHight = false;
			bool haveNumber = false;
			for (size_t i = 0; i < password.size() + 1; i++)
			{
				if (password[i] == isupper(password[i]))
				{
					haveHight = true;
				}
				else if (password[i] == islower(password[i]))
				{
					haveLover = true;
				}
				else if (int(password[i]) < 58 && int(password[i]) > 47)
				{
					haveNumber = true;
				}
			}
			if (haveHight == false && haveLover == false && haveNumber == false) {
				throw badPassword("not secure password!!!");
			}
			std::ofstream SingAdd;
			SingAdd.open("login.txt", std::ofstream::app);
			SingAdd << login << std::endl;
			SingAdd << password << std::endl;
			SingAdd.close();
		}
		else {
			throw badPassword("not secure password!!!");
		}
	}
};

class Login
{
public:
	bool login(const std::string& login, const std::string& password) {
		std::ifstream singIn;
		singIn.open("login.txt");
		Clear;
		bool isTrueLogin = false;
		bool isTruePassword = false;
		while (!singIn.eof()) {
			std::string l;
			std::string p;
			getline(singIn, l);
			getline(singIn, p);
			if (l == login) {
				if (p == password) {
					return true;
				}
				throw badPassword();
			}
		}

		throw badLogin("User is didn't find");
	}

};
class Menu : public Register, public Login
{
public:
	void menu() {
		size_t index = 0;
		std::cout << "\t  1)LOGIN,2)REGISTER -> ";
		std::cin >> index;
		std::string log;
		std::string password;
		std::cout << std::endl;
		std::cout << "\t  LOGIN" << std::endl;
		std::cout << "\t ";
		std::cin >> log;
		std::cout << "\t PASSWORD" << std::endl;
		std::cout << "\t ";
		std::cin >> password;
		if (index == 1) {
			login(log, password);
			std::cout << "success" << std::endl;
		}
		else {
			reg(log, password);
			std::cout << "success" << std::endl;
		}
	}
};




	

