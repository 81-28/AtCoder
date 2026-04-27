// https://atcoder.jp/contests/abc250/tasks/abc250_d

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define pb push_back

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


bool isPrime(const int& n) {
    if (n <= 1) return false;
    else if (n <= 3) return true;
    else if (!(n%2&&n%3)) return false;
    for (int i=5;i*i<=n;i+=6) if (!(n%i&&n%(i+2))) return false;
    return true;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi p;
    for (int i=2; i*i*i*2<=n; ++i) {
        if (isPrime(i)) p.pb(i);
    }
    int ans=0;
    int l=p.size();
    rep1(i,l-1) {
        int q=p[i];
        int d=n/(q*q*q);
        auto it=upper_bound(p.begin(),p.begin()+i,d);
        int add=it-p.begin();
        if (!add) break;
        ans+=add;
    }
    print(ans);

    return 0;
}
