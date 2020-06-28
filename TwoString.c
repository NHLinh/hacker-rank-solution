#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    int azLength = 'z' - 'a' + 1;
    int azDic1[azLength], azDic2[azLength];
    for (int i = 0; i < azLength; i++) azDic1[i] = azDic2[i] = 0;
    for (int i = 0; i < s1.size(); i++) azDic1[s1[i] - 'a']++;
    for (int i = 0; i < s2.size(); i++) azDic2[s2[i] - 'a']++;
    for (int i = 0; i < azLength; i++)
        if ( (azDic1[i] > 0) && (azDic2[i] > 0)) return "YES"  ;
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
