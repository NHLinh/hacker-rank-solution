#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int max = 0;
    int previous = 0;
    while ( n > 0)
    {
        if (n % 2 == 1)
        {
            previous++;
        }
        else
        {
            if (previous > max) max = previous;
            previous = 0;
        }
        n = n / 2;
    }
    if (previous > max) max = previous;
    std::cout << max; 
    return 0;
}