#include <iostream>

double getMedian(double array[], int size)
{
    if(size == 1)
    {
        return array[0];
    }
    if(size % 2 !=0) // if it is not even, we get the number in the middle
    {
        return array[ (size - 1) / 2];
    }
    else 
    {   //0 1 2 3
        // 0 1 2 3 4 5
        return ((array[size/2] + array[(size/2) -1]) / 2.0);
    }
}

void printMedians(double array[], int size)
{
    for(int i = 0; i < size; i++)
    {
      printf("%.1f ",array[i]);
    }
    printf("\n");
}

void insertInSorted(double array[], int size, int value)
{
    int pos = size;
    while(array[pos - 1] > value && pos > 0 )
    {
        array[pos] = array[pos - 1];
        --pos;
    }
    array[pos] = value;
}

int main()
{
    double nums [10000];
    double res  [10000];
    int n;
    scanf("%d", &n);
    for(int i =0; i < n; i++)
    {
        double current;
        scanf("%lf", &current);
        insertInSorted(nums,i, current);
        res[i] = getMedian(nums, i+1);
    }
    printMedians(res, n);
    return 0;
}