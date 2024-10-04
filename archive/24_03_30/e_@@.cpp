// https://atcoder.jp/contests/abc347/tasks/abc347_e

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

int arSize(int s[],int q){
    int ans = 0;
    for (int i = 0; i < q; i++)
    {
        if (s[i] != 0)
        {
            ans++;
        }
    }
	return ans;
}

int main() {
    int n,q;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = 0;
    }
    cin >> q;
    int x[q];
    int s[q];
    for (int i = 0; i < q; i++)
    {
        cin >> x[i];
        s[i] = 0;
    }
    
    for (int i = 0; i < q; i++)
    {
        bool add = true;
        for (int j = 0; j < q; j++)
        {
            if (s[j] != 0)
            {
                if (s[j] == x[i])
                {
                    s[j] = 0;
                    add = false;
                    break;
                }
            }
            
        }
        if (add)
        {
            s[i] = x[i];
        }
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < q; k++)
            {
                if (s[k] != 0)
                {
                    if (j == s[k])
                    {
                        a[j-1] += arSize(s,q);
                        break;
                    }
                }
                
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    
    return 0;
}
