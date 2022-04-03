#include <string>
#include <iostream>
#include <algorithm>

int main()
{
    char nums [10000000];
    char lowerCase [10000000];
    char upperCase [10000000];
    int numsCnt = 0;
    int lowerCnt = 0;
    int upperCnt = 0;
    int n;
    scanf("%d", &n);
    for(int i =0; i <= n; i++)
    {
        char current;
        scanf("%c", &current);

        if(current >= '0' && current <= '9')
        {
            nums.push_back(current);
            numsCnt++;
        }
        else if(current >= 'a' && current <='z')
        {
            lowerCase.push_back(current);
            lowerCnt++;
        }
        else if(current >= 'A' && current <= 'Z')
        {
            upperCase.push_back(current);
            upperCnt++;
        }
    }

    std::sort(nums, nums + numsCnt);
    std::sort(lowerCase, lowerCase + lowerCnt);
    std::sort(upperCase, upperCase + upperCnt);
    std::cout << nums;
    std::cout << lowerCase;
    std::cout << upperCase;
    return 0;
}
