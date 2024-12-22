// https://atcoder.jp/contests/abc385/tasks/abc385_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi h(n);
    cin >> h;
    int ans = 1;
    map<int,vi> m;
    rep(i,n) {
        m[h[i]].pb(i);
    }
    for(pair<int,vi> p:m) {
        int k = p.second.size();
        vi vec = p.second;
        v<unordered_map<int,int>> dp(k);
        for (int i = 1; i < k; i++) {
            for (int j = 0; j < i; j++) {
                int diff = vec[i] -vec[j];
                int len = dp[j].count(diff) ? dp[j][diff] + 1 : 2;
                dp[i][diff] = len;
                ans = max(ans,len);
            }
        }
    }
    print(ans);

    return 0;
}
