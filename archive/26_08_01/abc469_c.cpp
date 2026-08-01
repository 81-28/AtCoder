// https://atcoder.jp/contests/abc469/tasks/abc469_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
template<typename T>inline bool chmin(T& a,const T& b){if(a>b){a=b;return 1;}return 0;}

#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    vi sm(n+1,0);
    rep1(i,n) sm[i]=sm[i-1]+(s[i-1]=='o');
    rep1(k,n) {
        int l=0,r=k;
        int add=sm[r]-sm[l];
        while (add>0) {
            l=r,r+=add;
            chmin(r,n);
            add=sm[r]-sm[l];
        }
        print(r);
    }

    return 0;
}
