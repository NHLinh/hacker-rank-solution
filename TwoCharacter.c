#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int getAltSubStringLength(string s, char a, char b)
{
    int count = 0;
    char previous = ' ';
    for (int i = 0; i < s.length(); i++)
    {
        if ((a == s[i]) || (b ==s[i]))
        {
            if (s[i] == previous) return 0;
            previous = s[i];
            count++;
        }
    }
    return count;

}
// Complete the alternate function below.
int alternate(string s) {
    int azLength = 'z' - 'a' + 1;
    int azDic[azLength];
    for (int i = 0; i < azLength; i++) azDic[i] = 0;
    for (int i = 0; i < s.length(); i++) azDic[s[i] - 'a']++;
    int max = 0;
    for (int i = 0; i < (azLength - 1); i++)
    {
        if (azDic[i] > 0)
        {
            for (int j = i + 1; j < azLength; j++)
            {
                if (azDic[j] > 0)
                {
                    int len = getAltSubStringLength(s, 'a' + i, 'a' + j);
                    if (max < len) max = len;
                }
            }
        }
    }
    return max;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string l_temp;
    getline(cin, l_temp);

    int l = stoi(ltrim(rtrim(l_temp)));

    string s;
    getline(cin, s);

    int result = alternate(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
