#include <iostream>
#include <vector>

struct Fraction
{
    int nominator;
    int denominator;

    Fraction() {};
    Fraction(const int nom, const int denom) : nominator(nom), denominator(denom) {}
   
    int gcd( int a, int b)  // greatest common divider
    {
        if ( a == 0)
        {
            return b;
        }
        if( b == 0)
        {
            return a;
        }
        return gcd( b % a, a);
    }

   // checks if the fraction is simple (the nominator is less than the denominator and the fraction is already simplified)
    bool isSimple()
    {
        return (this->nominator < this->denominator) 
            && gcd(this->nominator, this->denominator) == 1;
    }

    bool operator < (const Fraction& other) // comparison of fractions
    {
        return ((double) this->nominator/ (double)this->denominator) < ((double) other.nominator / (double) other.denominator);
    }
};

int minFrom(Fraction fracs [], int from, int to )
{
    Fraction min = fracs[from];
    int minIdx = from;
    for(int  i = from + 1 ; i < to; i++)
    {
        if(fracs[i] < min)
        {
            minIdx = i;
            min = fracs[i];
        }
    }

    return minIdx;
}

void selectionSort(Fraction fracs[], int size)
{
    for(int i = 0; i < size; i++)
    {
        int min = minFrom(fracs, i, size);
        if( min != i)
        {
            std::swap(fracs[i], fracs[min]);
        }
    }
}

void printFractions(const int n)
{
    if( n == 0) {return;}

    printf("0");

    Fraction fractions [10000];
    int cnt = 0;

    for(int i = 1; i < n; i++)
    {
        for(int j = n; j > 1; j--)
        {
            Fraction current(i,j);
            if(current.isSimple())
            {
                fractions[cnt] = current;
                cnt++;
            }
        }
    }
    selectionSort(fractions, cnt);
    for(int i = 0; i < cnt; i++)
    {
        printf(" %d/%d", fractions[i].nominator, fractions[i].denominator);
    }
    printf("\n");
}


int main()
{
    int n;
    scanf("%d", &n);    // read n from input
    printFractions(n);  // print the generated fractions
    return 0;
}