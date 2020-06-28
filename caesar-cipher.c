#include <bits/stdc++.h>

using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {
    int azLength = 'z' - 'a' + 1;
    k = k % azLength;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a') && (s[i] <= 'z'))
            s[i] = ((s[i] + k) <= 'z')? s[i] + k : s[i] + k - azLength;
        if ((s[i] >= 'A') && (s[i] <= 'Z'))
            s[i] = ((s[i] + k) <= 'Z')? s[i] + k : s[i] + k - azLength;
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
