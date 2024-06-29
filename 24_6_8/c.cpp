// https://atcoder.jp/contests/abc357/tasks/abc357_c

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

vector<vector<char>> carpet(int num) {
    int p3 = pow(3,num);
    int p31 = pow(3,num-1);
    vector<vector<char>> result;
    // result.reserve(p3);
    if (num == 0)
    {
        result = {{'#'}};
    } else {
        vector<vector<char>> lowLev = carpet(num-1);

        vector<vector<char>> spaces;
        for (int i = 0; i < p31; i++)
        {
            vector<char> space;
            for (int j = 0; j < p31; j++)
            {
                space.insert(space.end(),'.');
            }
            spaces.insert(spaces.end(),space);
        }

        vector<vector<char>> row0(p31);
        for (int i = 0; i < p31; i++)
        {
            row0[i].reserve(p3);
            for (int j = 0; j < 3; j++)
            {
                row0[i].insert(row0[i].end(),lowLev[i].begin(),lowLev[i].end());
            }
        }
        
        vector<vector<char>> row1(p31);
        for (int i = 0; i < p31; i++)
        {
            row1[i].reserve(p3);
            row1[i].insert(row1[i].end(),lowLev[i].begin(),lowLev[i].end());
            row1[i].insert(row1[i].end(),spaces[i].begin(),spaces[i].end());
            row1[i].insert(row1[i].end(),lowLev[i].begin(),lowLev[i].end());
        }
        
        result.insert(result.end(),row0.begin(),row0.end());
        result.insert(result.end(),row1.begin(),row1.end());
        result.insert(result.end(),row0.begin(),row0.end());
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> ans = carpet(n);
    int p3 = pow(3,n);
    for (int i = 0; i < p3; i++)
    {
        for (int j = 0; j < p3; j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
