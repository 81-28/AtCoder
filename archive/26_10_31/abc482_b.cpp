// https://atcoder.jp/contests/abc482/tasks/abc482_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    v<string> s(5);
    cin >> s;
    vi r(5,0),c(5,0),x(2,0);
    rep(i,5)rep(j,5) {
        if (s[i][j]!='o') continue;
        ++r[i],++c[j];
    }
    rep(i,5) {
        if (s[i][i]=='o') ++x[0];
        if (s[i][4-i]=='o') ++x[1];
    }
    print(5-max({max(r),max(c),max(x)}));

    return 0;
}
