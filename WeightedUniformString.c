#include <bits/stdc++.h>

using namespace std;

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) {
    int azLength = 'z' - 'a' + 1;
    int azDic[azLength];
    for (int i = 0; i < azLength; i++) azDic[i] = 0;
    // Idea is find all max sub uniform string of each char
    char previous = ' ';
    int duplicate = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == previous) duplicate++;
        else
        {
            duplicate = 1;
            previous = s[i];
        }
        int azIdx = s[i] - 'a';
        if (azDic[azIdx] < duplicate) azDic[azIdx] = duplicate;
    }
    vector<string> ret;
    for (int query : queries)
    {
        bool isYes = false;
        for (int i = 0; i < azLength; i++)
        {
            int weight = i + 1;
            if ((query % weight == 0) && (azDic[i] >= (query/weight)))
            {
                isYes = true;
                break;
            }
        }
        if (isYes) ret.push_back("Yes");
        else ret.push_back("No");
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
