
#include"Function.h"


int main()
{
	Circle t(5);
	Circle t2(10);
	Circle t3(5);
	std::initializer_list<Circle> temp{t,t2,t3};
	Function::print(temp);
 
}
