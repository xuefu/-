#include <iostream>
#include <vector>

using namespace std;

/*

*/

string simply(string &str)
{
    vector<string> dirs;

    int len = str.size();
    int i = 0;
    while (i < len-1)
    {
        int begin = i+1;
        while (str[++i] != '/')
            ;
        dirs.push_back(string(str, begin, i-begin));
    }
    int last_num = 0;
    string result = "";
    for (auto it = dirs.rbegin(); it != dirs.rend(); ++it)
    {
        // cout << *it << endl;
        if (*it == "" || *it == ".") continue;
        if (*it == "..")
        {
            ++last_num;
            continue;
        }
        if (last_num == 0) 
            result.insert(0, "/"+*it);
        else
            --last_num;
        
    }
    return result;
}

int main()
{
    string input;
    cin >> input;

    cout << simply(input) << endl;
}