#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, unordered_set<string> &dict) {
    if(dict.size()==0) return false;

    vector<bool> dp(s.size()+1,false);
    dp[0]=true;

    for(int i=1;i<=s.size();i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(dp[j])
            {
                string word = s.substr(j,i-j);
                if(dict.find(word)!= dict.end())
                {
                    dp[i]=true;
                    break; //next i
                }
            }
        }
    }
    return dp[s.size()];
}

int main()
{
    string s;
    // cin >> s;

    unordered_set<string> dict;
    // string tmp;
    // while (cin >> tmp)
    // {
    //     dict.insert(tmp);
    // }

    s = "leetcode";
    dict.insert("leet");
    dict.insert("code");
    cout << wordBreak(s,dict) << endl;
}