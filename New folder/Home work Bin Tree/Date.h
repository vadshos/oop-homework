#include <iostream>

#include <stdio.h>

int LongMonth[] = { 1,3,5,7,8,10,12 };
const char* sMonth[] =
{
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

class date
{
public:
    friend class Violation;
    int day, month, year;
    bool bChangeDay, bChangeMonth, bChangeYear;
    char sDate[256];//Дата в строковом формате

    date();                               
    date(int iDay, int iMonth, int iYear);
    date(const date& val);               
    ~date();                              

    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }

    void setDay(int iDay);
    void setMonth(int iMonth);
    void setYear(int iYear);
    bool IsChangeDay() { return bChangeDay; }
    bool IsChangeMonth() { return bChangeMonth; }
    bool IsChangeYear() { return bChangeYear; }

    char* ShowDate();
};

date::date()
{
    day = 1;
    month = 1;
    year = 1900;

    bChangeDay = false;
    bChangeMonth = false;
    bChangeYear = false;

    sDate[0] = '\0';
}

date::date(int iDay, int iMonth, int iYear)
{
    bChangeDay = false;
    bChangeMonth = false;
    bChangeYear = false;

    setDay(iDay);
    setMonth(iMonth);
    setYear(iYear);

    sDate[0] = '\0';
}

date::date(const date& val)
{
    day = val.day;
    month = val.month;
    year = val.year;

    sDate[0] = '\0';
}

date::~date()
{
    day = 1;
    month = 1;
    year = 1900;

    sDate[0] = '\0';
}

void date::setDay(int iDay)
{
    if (iDay < 1 || 31 < iDay)
        bChangeDay = true;
    if (bChangeDay)
        day = 1;
    day = iDay;
}

void date::setMonth(int iMonth)
{
    int i, nMonth = sizeof(LongMonth) / sizeof(int);
    if (iMonth < 1 || 12 < iMonth)
        bChangeMonth = true;
    if (bChangeMonth)
        month = 1;
    if (day == 31)
    {
        for (i = 0; i < nMonth; i++)
        {
            if (iMonth == LongMonth[i])
                break;
        }
        if (nMonth <= i)
            bChangeDay = true;
    }
    if (bChangeDay)
        day = 1;
    month = iMonth;
}

void date::setYear(int iYear)
{
    if (iYear < 1)
        bChangeYear = true;
    if (bChangeYear)
        iYear = 1;
    if (28 < day && month == 2)
        if (iYear % 4 != 0)
            bChangeDay = true;
    if (bChangeDay)
        day = 1;
    year = iYear;
}

char* date::ShowDate()
{
        sprintf_s(sDate, "%02d %s %04d\r\n", day, sMonth[month - 1], year);
    return &sDate[0];
}
