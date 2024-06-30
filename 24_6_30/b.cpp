// https://atcoder.jp/contests/abc360/tasks/abc360_b

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
// using mint = modint1000000007;

int main() {
    string s,t;
    cin >> s >> t;
    int len = s.size();
    for (int w = 1; w < len; w++)
    {
        set<string> gets;
        int stringNum = (len+ w-1)/w;
        for (int c = 0; c < w; c++)
        {
            string get = "";
            for (int i = 0; i < stringNum; i++)
            {
                int index = i*w+c;
                if (index < len)
                {
                    get += s[index];
                }
                
            }
            gets.insert(get);
        }
        if (gets.find(t) != gets.end())
        {
            cout << "Yes" << endl;
            return 0;
        }
        
    }
    
    cout << "No" << endl;


    return 0;
}
