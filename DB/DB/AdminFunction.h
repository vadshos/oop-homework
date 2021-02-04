#pragma once
#include "Login.h"
#include"BaseFunctionForUsers.h"
#include <string>

class AdminFunction 
{
public:
	static void menu();
	static void addAccount(const std::string& login, const std::string& password, const std::string role);
	static void banAccount(const std::string& login);
	static void eraseAccount(const std::string& login);
	static void changeAccountPassword(const std::string& login, const std::string& password);
	static void addProduct();
	static void eraseProduct();
};

