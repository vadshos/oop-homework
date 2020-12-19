#include <iostream>
#include "Base_DAI.h"




int main()
{
    date d(3, 5, 2012);
    Violation v("NULL",300,d);
    Base_DAI base;
    base.add(4342, { "NULL",300,{1,5,2015}});
    base.add(4342, { "NULL2",300,{2,6,2016}});
    base.add(0043, { "NULL3",300,{2,6,2016} });
    base.add(0043, { "NULL3",300,{2,6,2016} });
    base.add(0043, { "NULL3",300,{2,6,2016} });
    base.add(4343, { "NULL3",300,{2,6,2016} });
    base.editViolation(4342,0,"1341342", 700, { 2,6,2016 });
    base.print();
}
