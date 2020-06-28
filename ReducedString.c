#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
    std::stringstream ss;
    bool isDeleted = false;
    int i = 0;
    while ( i < s.size())
    {
        if (s[i] == s[i + 1])
        {
            isDeleted = true;
            i += 2;
        }
        else
        {
            ss << s[i];
            i++;
        }
    }
    std::string str = ss.str();
    if (str.size() == 0) return "Empty String";
    if (isDeleted) return superReducedString(str);
    else return str;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
