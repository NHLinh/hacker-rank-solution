#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
    int azLength = 'z' - 'a' + 1;
    int azDic[azLength];
    for (int i = 0; i < azLength; i++) azDic[i] = 0;
    for (int i = 0; i < s.size(); i++)
        if ((s[i] >= 'a') && (s[i] <= 'z')) azDic[s[i] - 'a']++;
        else if ((s[i] >= 'A') && (s[i] <= 'Z')) azDic[s[i] - 'A']++;
    for (int i = 0; i < azLength; i++)
        if (azDic[i] == 0) return "not pangram";
    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
