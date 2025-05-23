// https://atcoder.jp/contests/abc386/tasks/abc386_d

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
using ll=long long;
template<typename T>
using v=vector<T>;
using vll=v<ll>;
using vvll=v<vll>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename T>
T min(const v<T>& v){return *min_element(v.begin(),v.end());}

const ll inf=1LL<<60;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll n;
    string s;
    cin >> n >> s;
    vll c(n);
    cin >> c;
    // dp[i][j]:i文字目までに状態j,kでの最低コスト
    // j:連続文字があったかどうか,文字iがk(0:1)
    v<vvll> dp(n,vvll(2,vll(2,inf)));
    bool b=s[0]-'0';
    rep(i,2) dp[0][0][i]=c[0]*(b^i);
    for(ll i=1,b=s[i]-'0';i<n;++i,b=s[i]-'0')rep(j,2)rep(k,2) {
        dp[i][j][k] = min(j?dp[i-1][0][k]:inf,dp[i-1][j][!k])+c[i]*(b^k);
    }
    print(min(dp[n-1][1]));

    return 0;
}
