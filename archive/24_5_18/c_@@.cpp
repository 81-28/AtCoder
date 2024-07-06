// https://atcoder.jp/contests/abc354/tasks/abc354_c

// Ctrl + Shift + B       => Build
// Terminal << "./a.out"  => Run

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
    int n;
    cin >> n;
    vector<pair<int,int>> cards;
    int m = 0;
    set<int> setI;
    for (int i = 0; i < n; i++)
    {
        int a,c;
        cin >> a >> c;
        bool add = true;
        if (cards.size() != 0)
        {
            int count = 0;
            for (int j = 0; j < cards.size(); j++)
            {
                if (cards[j].first > a && cards[j].second < c)
                {
                    add = false;
                    break;
                } else if (cards[j].first < a && cards[j].second > c)
                {
                    cards.erase(cards.begin() + j);
                    m--;
                    
                    auto it = setI.begin();
                    advance(it,j-count);
                    setI.erase(*it);
                    count++;
                }
            }
        }
            
        if (add)
        {
            cards.push_back(make_pair(a,c));
            m++;
            setI.insert(i+1);
        }
    }
    
    cout << m << endl;
    for (const int& value : setI)
    {
        cout << value << ' ';
    }
    cout << endl;



    return 0;
}
