#include <bits/stdc++.h>

using namespace std;

// Complete the minimumNumber function below.
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";

    bool conds[4];
    for (int i = 0; i < 4; i++) conds[i] = false;
    for (int i = 0; i < password.length(); i++)
    {
        if (!conds[0] && numbers.find(password[i], 0) != string::npos)
            conds[0] = true;
        if (!conds[1] && lower_case.find(password[i], 0) != string::npos)
            conds[1] = true;
        if (!conds[2] && upper_case.find(password[i], 0) != string::npos)
            conds[2] = true;
        if (!conds[3] && special_characters.find(password[i], 0) != string::npos)
            conds[3] = true;
    }
    int count = 0;
    for (int i = 0; i < 4; i++) if (!conds[i]) count++;
    int addLength = 6 - password.length();
    return (addLength > count)? addLength : count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}
