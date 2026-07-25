// https://atcoder.jp/contests/abc468/tasks/abc468_a

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


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout<<fixed<<setprecision(16);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    int ans=0;
    for (int i=1; i+1<n; ++i) {
        if (a[i-1]<a[i] && a[i]>a[i+1]) ++ans;
    }
    print(ans);

    return 0;
}
