#include <bits/stdc++.h>

using namespace std;

// Complete the funnyString function below.
string funnyString(string s) {
    int arrLength = s.length() - 1;
    int arr[arrLength];
    for (int i = 0; i < arrLength; i++) 
    {
        arr[i] = abs(s[i+1] - s[i]);
        cout << " " << arr[i];
    }
    cout << endl;
    int l = 0, u = arrLength - 1, half = arrLength / 2;
    for (; l < half; l++, u--) if (arr[l] != arr[u]) return "Not Funny";
    return "Funny";
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

        string result = funnyString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
