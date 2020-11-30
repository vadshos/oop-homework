#include "train.h"


size_t Train::NumberTrain = 0;
Train::Train(string NameTrain, size_t QuentityCars)
{
	NumberTrain++;
	setName(NameTrain);
	setQuentity(QuentityCars);
	
	
}

Train::Train(string NameTrain, size_t QuentityCars, size_t pass[], car::typeCar TypeCar)
{
	NumberTrain++;
	setName(NameTrain);
	setQuentity(QuentityCars);
}

Train::Train() : Train(NameTrain = "Львів_Ковель",QuentityCars = 45) 
{
}

void Train::setName(string NameTrain)
{
	if (NameTrain != "") {
		this->NameTrain = NameTrain;
		Cars = new car();
	}
}

string Train::getName() const
{
	return NameTrain;
}

size_t Train::maxCarPassIndex() const
{
	size_t index = 0;
	size_t maxPass = Cars[0].getPass();
	for (int i = 0; i < QuentityCars; i++) {
		if (Cars[i].getPass() > maxPass) {
			index = i;
			maxPass = Cars[i].getPass();
		}
	}
	index++;
	return index++;
}
size_t Train::minCarPassIndex() const
{
	size_t index = 0;
	size_t minPass = Cars[0].getPass();
	for (int i = 0; i < QuentityCars; i++) {
		if (Cars[i].getPass() < minPass) {
			index = i;
			minPass = Cars[i].getPass();
		}
	}
	index++;
	return index;
}

size_t Train::getNumber() const
{
	return NumberTrain;
}

size_t Train::getQuentity() const
{
	return QuentityCars;
}

void Train::setQuentity(size_t QuentityCars)
{
	if (QuentityCars != 0 && QuentityCars < 50) {
		this->QuentityCars = QuentityCars;
		Cars = new car[QuentityCars];
		for (int i = 0; i < QuentityCars; i++) {
			new (&Cars[i]) car();
		}
	}
}
void Train::Print() const
{
	cout << "Name train : " << getName() << endl;
	cout << "Number train : " << getNumber() << endl;
	cout << "Quntity cars : " << getQuentity() << endl;
	for (size_t i = 0; i < QuentityCars; i++)
	{
		Cars[i].print();
	}
}

void Train::FuctionalPrint() const
{
	cout << QuntityPass << endl;
	cout << QuentityCars << endl;
	cout << minCarPassIndex() << endl;
	cout << maxCarPassIndex() << endl;

}

Train::~Train()
{
	if (Cars != nullptr) {
		delete[] Cars;
		Cars = nullptr;
	}
}
