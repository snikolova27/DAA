#include <iostream>

int bubbleSort(int array[], int size)
{
    int result = 0;
    bool changed = false;
    int sorted = 0;

    do 
    {
        changed = false;
        for(int i = size  -1; i > sorted; i--)
        {
            if(array[i] < array[i-1])
            {
                std::swap(array[i], array[i-1]);
                changed = true;
                result++;
                
            }
        }
        ++sorted;
    
    }while (changed);

    return result;
}

int main()
{
    int people [1000];
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int current;
        scanf("%d", &current);
        people[i] = current;
    }
    printf("%d", bubbleSort(people,n));
    printf("\n");
    return 0;
}