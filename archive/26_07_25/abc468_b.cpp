// https://atcoder.jp/contests/abc468/tasks/abc468_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
auto sum(const v<T>& v){return accumulate(v.begin(),v.end(),T{});}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int m,d;
    string s;
    cin >> m >> d >> s;
    vi b(m,1);
    rep(i,m) {
        if (s[i]!='G') continue;
        for (int j=max(0,i-d); j<=min(m-1,i+d); ++j) b[j]=0;
    }
    print(sum(b));

    return 0;
}
