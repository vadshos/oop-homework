#include "BaseFunctionForUsers.h"




void BaseFunctionForUsers::getAllProductsCategory(const std::string& nameTable)
{
	std::vector<Product*> list_product;
	int qstate;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, Login::getHost().c_str(), Login::getUser().c_str(), Login::getPass().c_str(), Login::getDB().c_str(), static_cast<unsigned int>(Login::getPort()), NULL, 0);
	if (conn) {
		std::string query = "SELECT * FROM " + nameTable;
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res))
			{
				if (nameTable == "Keyboard") {
					list_product.push_back(new KeyBoard(row[0], row[1], row[2],  row[3], row[4], row[5], row[6], row[7], row[8], row[9], row[10] ));
				}
				else if (nameTable == "Mice") {
					list_product.push_back(new Mice(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8],row[9]));

				}
				else if (nameTable == "Monitor") {

					list_product.push_back(new Monitor(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8]));
				}
				else if (nameTable == "Laptop") {
					list_product.push_back(new Laptop(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9], row[10], row[11], row[12]));


				}
				else if (nameTable == "PC") {
					list_product.push_back(new PC(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8] ,row[9]));
				}
				else if (nameTable == "Console") {

					list_product.push_back(new Console(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8] ,row[9] ));

				}
			}

			showAllProductsCategory(list_product);
		}
	}
}

void BaseFunctionForUsers::showProduct(Product* obj)
{
	obj->print();

	std::cout << "Press B to buy product ,and press any buttom to exit ->";
	int a = _getch();

	if (a == 98 or a == 66) {
		if (obj->getCountProduct() != 0) {

		buyProduct(obj);
		}
		else {
			std::cout << "Product is't in availability";
		}
	}
}

void BaseFunctionForUsers::buyProduct(Product*obj)
{
	int qstate;
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, Login::getHost().c_str(), Login::getUser().c_str(), Login::getPass().c_str(), Login::getDB().c_str(), Login::getPort(), NULL, 0);
	if (conn) {
		std::string table = typeid(*obj).name() + 6;
		table[0] = std::tolower(table[0]);
		std::string query = "UPDATE " + table + "  SET countProduct = " + std::to_string((obj->getCountProduct())-1).c_str() + " WHERE name = '" + obj->getName().c_str() + "'";
		const char* q = query.c_str();
		qstate = mysql_query(conn, q);
		if (!qstate)
		{
			obj->setCountProduct(std::to_string((obj->getCountProduct())- 1));
			res = mysql_store_result(conn);
		}
	}
}


void BaseFunctionForUsers::showAllProductsCategory(const std::vector<Product*>& list)
{
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
				std::cout << *(*(list.begin() + i)) << std::endl;
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
			else if (a == 27) {
				showCategory();
			}
		}
		if (!list.empty()) {
			Product* tempObjProduct = dynamic_cast<Product*>(*(list.begin() + achion));
			if (tempObjProduct) {

				showProduct(tempObjProduct);
			}
		}
		else {
			if (Login::getRole() == 1) {
				AdminFunction::menu();
			}
			else {
				UserFunction::menu();
			}
		}

	}
}

void BaseFunctionForUsers::showCategory()
{
	system("mode con cols=100 lines=50");
	std::vector<std::string> category{ "Keyboard","Mice","Monitor","Laptop","Console","PC" };
	int achion = 0;
	int a = 0;
		while (a != 13) {
			system("cls");
			for (int i = 0; i < category.size(); i++) {
				if (i == achion) {
					Login::SetColor(0, 14);
				}
				if (i != achion) {
					Login::SetColor(0, 15);
				}
				std::cout << *(category.begin() + i) << std::endl;
				Login::SetColor(0, 15);
			}
			a = _getch();
			if (a == 119) {
				achion--;
				if (achion < 0) {
					achion = category.size();
				}
			}
			else if (a == 115) {
				achion++;
				if (achion > category.size()) {
					achion = 0;
				}
			}
			else if (a == 27) {
				if (Login::getRole() == 1) {
					AdminFunction::menu();
				}
				else {
					UserFunction::menu();
				}
			}
		}
		getAllProductsCategory(*(category.begin() + achion));
}
