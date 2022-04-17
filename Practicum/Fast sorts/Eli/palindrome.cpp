#include <iostream>
#include <string>
int letters [26];
char result [1'000'000];

int cntUneven()
{
    int cnt = 0;
    for(int i = 0; i < 26; i++)
    {
        if(letters[i] % 2 != 0)
        {
            cnt++;
        }
    }

    return cnt;
}

void getPalindrome(int len)
{
    int idx = 0;
    if(len % 2 == 0)
    {
        for(int i = 0; i < 26; i++)
        {
            for( int j = 0; j < letters[i] / 2; j++)
            {
                result[idx] = i + 'a';
                result [len - idx  - 1] = i + 'a';
                idx++;
            }
        }
    }
    else 
    {
        int mid = len/2;
        for(int i = 0; i < 26; i++)
        {
            
            if(letters[i] % 2 != 0)
            {
                    result[mid] = i + 'a';
            }
            for( int j = 0; j < letters[i] / 2; j++)
            {
            
                    result[idx] = i + 'a';
                    result [len - idx  - 1] = i + 'a';
                    idx++;
            
               
            }
        }
    }
}

int main()
{
    std::string input;
    std::cin >> input;
    int len  = input.size();
    for(int i = 0; i < len; i++)
    {
        letters[input[i] - 'a']++;
    }

    if(cntUneven() > 1)
    {
        std::cout << "IMPOSSIBLE \n";
    }
    
    else 
    {
        getPalindrome(len);
        for(int i = 0; i < len; i++ )
        {
            std::cout << result[i];
        }
    }

    return 0;
}
