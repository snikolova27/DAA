#include <iostream>
#include <vector>
#include <string>

// struct to keep the date entered
struct Date
{
    int day = 0;
    int month = 0;
    int year = 0;
    int idx = -1;

    Date(){}
    Date(const int day, const int month, const int year, const int idx) : day(day), month(month), year(year) , idx(idx){}

    bool operator <= (const Date& other)
    {
        return  (this->year == other.year && this->day == other.day && this->month == other.month && this->idx < other.idx) // same date, different idx
                || (this->year < other.year) 
                || (this->month < other.month && this->year < other.year) 
                || (this->day < other.day && this->month == other.month && this->year == other.year) 
                || (this->day == other.day && this->month < other.month && this->year == other.year) 
                || (this->day == other.day && this->month == other.month && this->year < other.year);
    }
};

// helper func that converts a char into an int
int charToInt(char ch)
{
    return ch - '0';
}

// read a date from a string, assuming the input is correct always
Date getDate(const std::string& str)
{
    Date res;
    int day, month, year;
    day = charToInt(str[0]) * 10 + charToInt(str[1]);
    month = charToInt(str[3]) * 10 + charToInt(str[4]);
    year = charToInt(str[6]) * 1000 + charToInt(str[7]) * 100 + charToInt(str[8]) * 10 + charToInt(str[9]);
    res.day = day;
    res.month = month;
    res.year = year;

    return res;
}

// helper func for the selection sort
int minFrom(std::vector<Date>& dates, int from, int to)
{
    Date minD = dates[from];
    int min = from;
    for(int  i = from + 1; i < to; i++)
    {
        if(dates[i] <= minD)
        {
            min = i;
            minD = dates[i];
        }
    }

    return min;
}

// actual selection sort func
void selectionSort(std::vector<Date>& dates)
{
    for(int i = 0; i < dates.size(); i ++)
    {
        int currentMin = minFrom(dates, i, dates.size());
        if(currentMin != i )
        {
            std::swap(dates[i], dates[currentMin]);
        }
    }
}

// wrapper for the sorting
void sortDates(std::vector<Date>& dates)
{
      selectionSort(dates);
}

// print the indices of the dates when they are sorted
void printDates(std::vector<Date>& dates)
{
    const int size = dates.size();
    for(int i = 0; i < size; i++)
    {
        std::cout << dates[i].idx << "\n";
    }
}

int main()
{
    int n;                      // count of dates to be entered
    std::vector<Date> dates;    // vector to keep the dates
    std::string current;        // input
    std::cin >> n;
    for(int i  = 0 ; i < n; i++)
    {
        std::cin >> current;
        Date currentD = getDate(current);
        currentD.idx = i+1;
        dates.push_back(currentD);
    }

    sortDates(dates);
    printDates(dates);

    return 0;
}