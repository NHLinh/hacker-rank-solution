#include <bits/stdc++.h>

using namespace std;

// Complete the anagram function below.
int anagram(string s) {
    if (s.size() % 2 == 1) return -1;
    int azLength = 'z' - 'a' + 1;
    int azDic1[azLength], azDic2[azLength];
    for (int i = 0; i < azLength; i++) azDic1[i] = azDic2[i] = 0;
    int half = (s.size() / 2);
    for (int i = 0; i < half; i++)
    {
        azDic1[s[i] - 'a']++;
        azDic2[s[half + i] - 'a']++;
    }
    int count = 0;
    for (int i = 0; i < azLength; i++)
        count += abs(azDic1[i] - azDic2[i]);  
    return count/2;
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

        int result = anagram(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
