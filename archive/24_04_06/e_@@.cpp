// https://atcoder.jp/contests/abc348/tasks/abc348_e

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
int f(int x,int n){
    int sum;
    for (int i = 0; i < n; i++)
    {
        // d(x,i)はxからiまで最短のしりとりの回数
    }
    
}

int main() {
    int n,ans;
    cin >> n;
    int a[n-1],b[n-1],c[n];
    for (int i = 0; i < n-1; i++)
    {
        cin >> a[i] >> b[i];  
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (int v = 0; v < n; v++)
    {
        if (v==0)
        {
            ans = f(v,n);
        }else{
            ans = (f(v,n) < ans) ? f(v,n) : ans;
        }    
    }
    cout << ans << endl;

    return 0;
}
