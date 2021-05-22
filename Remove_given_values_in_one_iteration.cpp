#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "asdcsdbbbb";
    int n = s.length() - 1;

    for (int i = n; i >= 0; i--)
    {
        if (s[i] == 'b')
        {
            s.erase(s.begin() + i);
        }
        else if (s[i] == 'c' && s[i - 1] == 'a')
        {

            s.erase(s.begin() + i);
            s.erase(s.begin() + i - 1);
        }
    }
    cout << s;
    return 0;
}
