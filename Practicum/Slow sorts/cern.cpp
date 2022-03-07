#include <iostream>
#include <string>

void print(std::string* arr, const int size)
{
    for(int i =0; i < size; i++)
    {
        std::cout << arr[i] << " \n";
    }
}

int minFrom(std::string* arr, int from, int to)
{
    std::string min = arr[from];
    int minIdx  = from;
    for(int i = from + 1 ; i < to; i++)
    {
        if( min > arr[i])
        {
            min =  arr[i];
            minIdx = i;
        }
    }

    return minIdx;
}

void sort(std::string* arr, const int size)
{
    for(int i =0; i <size; i++)
    {
        int currentMin  = minFrom(arr, i, size);
        if(currentMin != i )
        {
            std::swap(arr[i], arr[currentMin]);
        }
    }
}

int main()
{
    int n;
    std::string array [10000]; 
    std::cin >> n;
    for( int i =0 ; i < n; i++)
    {
        std::string current;
        std::cin >> current;
        array[i] = current;
    }
    sort(array, n);
    print(array, n);
}