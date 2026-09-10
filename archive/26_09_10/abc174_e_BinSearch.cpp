// https://atcoder.jp/contests/abc174/tasks/abc174_e

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}

template<typename T>
T max(const v<T>& v){return *max_element(v.begin(),v.end());}


vi a;
// 長さx以下にするのに必要な切る回数
int c(int x) {
    int res=0;
    for (int val:a) res+=(val-1)/x;
    return res;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    a=vi(n);
    cin >> a;
    // k回以下の切断で達成できる長さ(l,r]
    int l=0,r=max(a);
    while (l+1<r) {
        int m=(l+r)/2;
        if (c(m)>k) l=m;
        else r=m;
    }
    print(r);

    return 0;
}
