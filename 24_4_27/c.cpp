// https://atcoder.jp/contests/abc351/tasks/abc351_c

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

vector<int> c;
void method(int a){
    c.push_back(a);
    if (c.size() != 1 && c[c.size()-1] == c[c.size()-2])
    {
        int num = c[c.size()-1] + 1;
        c.pop_back();
        c.pop_back();
        method(num);
    }
    

}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        method(a);
    }
    
    cout << c.size() << endl;




    return 0;
}
