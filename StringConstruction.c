#include <bits/stdc++.h>

using namespace std;

// Complete the stringConstruction function below.
int stringConstruction(string s) {
    int azLength = 'z' - 'a' + 1;
    int azDic[azLength];
    for (int i = 0; i < azLength; i++) azDic[i] = 0;
    int cost = 0;
    for (int i = 0; i < s.size(); i++) 
    {
        if (azDic[s[i] - 'a'] == 0) cost++;
        azDic[s[i] - 'a']++;
    }
    return cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = stringConstruction(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
