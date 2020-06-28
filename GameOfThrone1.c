#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {
    int azLength = 'z' - 'a' + 1;
    int azDic[azLength];
    for (int i = 0; i < azLength; i++) azDic[i] = 0;
    for (int i = 0; i < s.size(); i++) azDic[s[i] - 'a']++;
    int oddCount = 0;
    for (int i = 0; i < azLength; i++)
       if (azDic[i] % 2 == 1) oddCount++;
    return oddCount > 1?"NO":"YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
