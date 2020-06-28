#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the highestValuePalindrome function below.
string highestValuePalindrome(string s, int n, int k) {
    bool isOdd = (s.length() % 2) == 1;
    int half = (s.length() / 2);
    int lowerStart = half - 1; // length = 4; u = 1; ; length = 5; u = 1;
    // length = 4; l = 2; ; length = 5; l = 3;
    int upperStart = isOdd? half + 1: half;
    // First loop to check string status
    bool isLeadingZero = isOdd? s[half] == 0 : true; // Check center number
    int countLeadingZero = isOdd? (isLeadingZero? 1 : 0) : 0;
    std::cout << "countLeadingZero:" << countLeadingZero << "\n";
    int count9 = 0, count = 0;
    for (int i = lowerStart, j = upperStart; j < s.length(); j++, i--)
    {
        if (s[i] != s[j])
        {
            isLeadingZero = false;
            if (s[i] == '9' || s[j] == '9') count9++;
            else count++;
        }
        else if (isLeadingZero && (s[i] == '0')) countLeadingZero++;
    }
    if ((count9 + count) > k) return "-1";
    if (countLeadingZero > 1)
    {
        if (isOdd)
        {
            s[half] = '9';
            k--;
        }
        else
        {
            if (k - (count9 + count) <  2) return "-1";
            s[lowerStart] = s[upperStart] = '9';
            k -= 2;
        }
    }
    // Second loop to make string Palindrome
    int countReplace9 = k - count - count9;
    for (int i = lowerStart, j = upperStart; j < s.length(); j++, i--)
    {
        if (s[i] != s[j])
        {
            if (k == 0) break;
            isLeadingZero = false;
            if (s[i] == '9' || s[j] == '9')
            {
                s[i] = s[j] = '9';
                k--;
            }
            else
            {
                if (countReplace9 > 0)
                {
                    s[i] = s[j] = '9';
                    countReplace9--;
                    k-=2;
                }
                else
                {
                    if (s[i] < s[j]) s[i] = s[j];
                    else s[j] = s[i];
                    k--;
                }
            }
        }
    }
    std::cout << k << "\n";
    if ((k > 1) && (s[half] != '9'))
    {
        s[half] = '9';
        k--;
    }
    // At this point s is already Palindrome
    for (int i = lowerStart, j = upperStart; j < s.length(); j++, i--)
    {   
        if (k <= 1) break;
        else if (s[i] != '9')
        {
            
            s[i] = s[j] = '9';
            k -= 2;
        }
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
