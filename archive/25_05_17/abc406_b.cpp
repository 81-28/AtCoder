// https://atcoder.jp/contests/abc406/tasks/abc406_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);++i)
using ull=unsigned long long;
template<typename T>
using v=vector<T>;

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    v<ull> a(n);
    cin >> a;
    ull ans=1;
    ull mx=pow(10,k);
    int l1,l2;
    rep(i,n) {
        l1=log10(ans);
        l2=log10(a[i]);
        if (l1+l2>k) {
            ans=1;
        } else {
            ans*=a[i];
            if (ans>=mx) {
                ans=1;
            }
        }
    }
    print(ans);

    return 0;
}
