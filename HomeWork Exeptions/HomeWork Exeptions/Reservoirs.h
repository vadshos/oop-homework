#pragma once
#include<iostream>
#include<string>

using namespace std;
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
	
class WrongLengthException : public myExeption
	{
	public:
		WrongLengthException(const std::string& exMessage = "wrong length exception") : myExeption(exMessage)
		{}
	
	};
	
	class WrongDepthException : public myExeption
	{
	public:
		WrongDepthException(const std::string& exMessage = "wrong depth exception") : myExeption(exMessage)
		{}
	
};
	
class WrongWidthExceptio : public myExeption
	{
	public:
		WrongWidthExceptio(const std::string& exMessage = "wrong width exceptio") : myExeption(exMessage)
		{}
	
	};
	
	class WrongTypeException : public myExeption
	{
	public:
		WrongTypeException(const std::string& exMessage = "wrong type exception") : myExeption(exMessage)
		{}
	
};

class Reservoirs
{
public:
	enum class  TypeReservoirs { lake, sea, ocean, swamp, river, other, undefined };
	const  string getTypeStr() const;
	void Print() const;
	void setName(string Name);
	void setType(TypeReservoirs type);
	void setSizeReservoirs(float width, float height, float maxDepth); \
	static bool comparisonType(const  Reservoirs& one, const  Reservoirs& two);
	static int comparisonAmoult(const  Reservoirs& one, const  Reservoirs& two);
	static Reservoirs TheLargestAmoult(const  Reservoirs* one, TypeReservoirs type);
	string getName() const;
	TypeReservoirs getType() const;
	float* getSizeReservoirs() const;
	Reservoirs(string Name, float width, float height, float maxDepth, TypeReservoirs type = TypeReservoirs::undefined);
	Reservoirs();
private:
	string Name;
	TypeReservoirs type;
	float width = 0;
	float height = 0;
	float maxDepth = 0;
	float amount = 0;
	float square = 0;
	static size_t QuntityReservoirs ;
};
inline string Reservoirs::getName() const {
	return Name;
}

inline Reservoirs::TypeReservoirs Reservoirs::getType() const
{
	return type;
}

inline float* Reservoirs::getSizeReservoirs() const {
	float size[] = { width,height,maxDepth };
	return size;
}

inline Reservoirs::Reservoirs(string Name, float width, float height, float maxDepth, TypeReservoirs type)
{
	QuntityReservoirs++;
	setName(Name);
	setType(type);
	setSizeReservoirs(width, height, maxDepth);
}

inline Reservoirs::Reservoirs() : Reservoirs("NoName", 1, 1, 1, TypeReservoirs::undefined)
{
}
