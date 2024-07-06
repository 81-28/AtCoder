// https://atcoder.jp/contests/abc347/tasks/abc347_c

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
    ll n,a,b;
    cin >> n;
    ll d[n];
    cin >> a;
    cin >> b;
    for (ll i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    ll w = a+b;
    for (ll i = 0; i < n; i++)
    {
        d[i] = d[i]%w;
    }

    ll mini = d[0];
	for(ll i=1; i < n; i++){
		mini = (mini > d[i]) ? d[i] : mini;
	}

    for (ll i = 0; i < n; i++)
    {
        d[i] = d[i]-mini;
    }

    ll maxi = d[0];
	for(ll i=1; i < n; i++){
        maxi = (d[i] > maxi) ? d[i] : maxi;
	}

    if (maxi < a)
    {
        cout << "Yes" << endl;
    }else{
        for (ll i = 0; i < n; i++)
        {
            d[i] = (d[i]+a)%w;
        }

        mini = d[0];
        for(ll i=1; i < n; i++){
            mini = (mini > d[i]) ? d[i] : mini;
        }

        for (ll i = 0; i < n; i++)
        {
            d[i] = d[i]-mini;
        }

        maxi = d[0];
        for(ll i=1; i < n; i++){
            maxi = (d[i] > maxi) ? d[i] : maxi;
        }

        if (maxi < a)
        {
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    
    return 0;
}
