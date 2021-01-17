#include <iostream>


__interface IDriverable
{
	void  drive() ;
	void  stop() ;
	void  upSpeed(const size_t& speed);
	void  downSpeed(const size_t& speed);
	void print();
};

class Horse : public IDriverable
{
public:
	Horse(const std::string breed = "NoBreed",const size_t& MAX_SPEED = 60) :MAX_SPEED(MAX_SPEED) {
		if (!breed.empty()) {
			this->breed = breed;
		}
	};
	void  drive() 
	{
		isDrive = true;
		speed = 5;
	};
	void  stop() 
	{
		isDrive = 0;
		speed = 0;
	};
	void  upSpeed(const size_t& speed)
	{
		if (speed <MAX_SPEED) {
			this->speed += speed;
		}
		else {
			this->speed =MAX_SPEED;
		}
	};
	void  downSpeed(const size_t& speed)
	{
		if (this->speed - speed >0 && speed > 0 ) {
			this->speed -= speed;
		}
	};
	void print() {
		std::cout << "Horse " << std::endl;
		std::cout << "Breed " << breed << std::endl;
		std::cout << "Speed " << speed << std::endl;;
	};
private:
	bool isDrive = false;
	size_t speed;
	const size_t MAX_SPEED = 60;
	std::string breed;
};
class Car : public IDriverable
{
public:
	Car(const std::string& prodused = "Lada",const size_t&MAX_SPEED = 304) : MAX_SPEED(MAX_SPEED) {
		if (!prodused.empty()) {
			this->prodused = prodused;
		}
	}
	void  drive()
	{
		isDrive = true;
		speed = 5;
	};
	void  stop()
	{
		isDrive = 0;
		speed = 0;
	};
	void  upSpeed(const size_t& speed)
	{
		if (speed < MAX_SPEED) {
			this->speed += speed;
		}
		else {
			this->speed =MAX_SPEED;
		}
	};
	void  downSpeed(const size_t& speed)
	{
		if ((this->speed - speed) > 0 && speed > 0) {
			this->speed -= speed;
		}
	};
	void print() {
		std::cout << "Car " << std::endl;
		std::cout << "Prodused " << prodused << std::endl;
		std::cout << "Speed " << speed << std::endl;;
	};
private:
	std::string prodused;
	bool isDrive = false;
	size_t speed;
	const size_t MAX_SPEED = 304;
};
enum class ACTION {START,STOP,UP_SPEED,DOWN_SPEED};
class Driver
{
public:
	Driver(const std::string& name, IDriverable* vehicle) 
	{
		if (!name.empty()) {
			this->name = name;
			this->vehicle = vehicle;
		}
	};
	void setVehicle(IDriverable* drivable) {
		vehicle = drivable;
	};
	void testDrive(ACTION a,const size_t speed = 0) {
		if (vehicle != nullptr) {
		if (int(a) == 0) {
			vehicle->drive();
		}
		else if (int(a)==1) {
			vehicle->stop();
		}
		else if (int(a)==2&& speed != 0) {
			vehicle->upSpeed(speed);
		}
		else if (int(a)==3 && speed != 0) {
			vehicle->downSpeed(speed);
		}
		vehicle->print();
		std::cout<<std::endl;
		}
		else {
			std::cout << "Vehicle is not choise"<<std::endl;
		}
	};
private:
	std::string name;
	IDriverable* vehicle;
};


int main()
{
	Car dg("Laborginy",34);
	Driver driver("Petro",&dg);
	driver.testDrive(ACTION::START);
	driver.testDrive(ACTION::DOWN_SPEED,1);
	driver.testDrive(ACTION::UP_SPEED,40);
	driver.testDrive(ACTION::STOP);


}

