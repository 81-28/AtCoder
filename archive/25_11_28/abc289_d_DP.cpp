// https://atcoder.jp/contests/abc289/tasks/abc289_d

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m,x;
    cin >> n;
    vi a(n);
    cin >> a >> m;
    unordered_map<int,bool> mp;
    rep1(i,m) {
        int b;
        cin >> b;
        mp[b]=1;
    }
    cin >> x;
    v<bool> dp(x+1,0);
    dp[0]=1;
    rep1(i,x) {
        if (mp[i]) continue;
        for (int val:a) {
            int j=i-val;
            if (j<0) break;
            if (dp[j]) {
                dp[i]=1;
                break;
            }
        }
    }
    YesNo(dp[x]);

    return 0;
}
