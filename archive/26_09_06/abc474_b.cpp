// https://atcoder.jp/contests/abc474/tasks/abc474_b

#include<bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll
template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}
#define YesNo(x) print(x?"Yes":"No")


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vi p(n);
    cin >> p;
    int m=(n+9)/10;
    rep(i,m) {
        set<int> s;
        for (int j=i*10; j<min((i+1)*10,n); ++j) {
            s.insert(p[j]);
        }
        if (*s.begin()<i*10+1 || (i+1)*10<*s.rbegin()) {
            YesNo(0);
            return 0;
        }
    }
    YesNo(1);

    return 0;
}
