#include <bits/stdc++.h>

using namespace std;

// make sure length is valid
long getFirstNumber(string s, int length)
{
    long ret = 0;
    for (int i = 0; i < length; i++)
    {
        ret = ret * 10 + s[i] - '0';
    }
    return ret;
}

// make sure length is valid
string toString(long value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}

int isNextValid(string s, long lastNumber, int next)
{
    std::string strCurrentNumber = toString(lastNumber + 1);
    if ((next + strCurrentNumber.length()) > s.length()) return -1;
    for (int i = 0; i < strCurrentNumber.length(); i++)
        if (strCurrentNumber[i] != s[next + i]) return -1;
    return next + strCurrentNumber.length(); 
}

// Complete the separateNumbers function below.
void separateNumbers(string s) {
    for (int i = 1; i <= (s.length() / 2); i++)
    {
        long first = getFirstNumber(s, i);
        // cout << first << endl;
        if (first == 0 && i > 1) continue;
        int pos = i;
        long current = first;
        while (pos > 0)
        {
            pos = isNextValid(s, current, pos);
            if (pos == s.length())
            {
                cout << "YES " << first << endl;;
                return;
            }
            current++;
        }
    }
    cout << "NO" << endl;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}
