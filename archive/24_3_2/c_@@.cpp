// https://atcoder.jp/contests/abc343/tasks/abc343_c

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

ll len(ll n){
	ll digit = 0;
	while(n != 0){
		n /= 10;
		digit++;
	}
	return digit;
}
ll dec(ll n){
    ll ans = 1;
    for (ll i = 0; i < n; i++)
    {
        ans *= 10;
    }
    return ans;
}

int main() {
    ll n;
    cin >> n;

    // for (ll i = n; i > 0; i--)
    // {
    //     if (fmod(cbrt(i),1.0) == 0.0)
    //     {
    //         bool ok = true;
    //         for (ll j = 0; j < (ll)(len(i)/2)+1; j++)
    //         {
    //             if ((i/dec(j))%10 == (i/dec(len(i)-1-j))%10)
    //             {
    //             }else{
    //                 ok = false;
    //             }
    //         }
    //         if(ok){
    //             cout << i << endl;
    //             break;
    //         }
            
    //     }
    // }
    ll cube = (ll)cbrt(n);
    ll cb = 1;
    if (cube >= 110011.0)
    {
        cb = 110011;
    }else if (cube >= 101101)
    {
        cb = 101101;
    }else if (cube >= 100001)
    {
        cb = 100001;
    }else if (cube >= 11011)
    {
        cb = 11011;
    }else if (cube >= 10101)
    {
        cb = 10101;
    }else if (cube >= 10001)
    {
        cb = 10001;
    }else if (cube >= 2201)
    {
        cb = 2201;
    }else if (cube >= 1001)
    {
        cb = 1001;
    }else if (cube >= 111)
    {
        cb = 111;
    }else if (cube >= 101)
    {
        cb = 101;
    }else if (cube >= 11)
    {
        cb = 11;
    }else if (cube >= 7)
    {
        cb = 7;
    }else if (cube >= 2)
    {
        cb = 2;
    }
    cout << cb*cb*cb << endl;
    
    return 0;
}
