// https://atcoder.jp/contests/abc261/tasks/abc261_b

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename T>
istream &operator>>(istream &is,v<T> &v){for(T &in:v)is>>in;return is;}
#define endl '\n' // flushしたい場合は無効化
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<string> a(n);
    cin >> a;
    rep(i,n-1)for(int j=i+1; j<n; ++j) {
        bool ok=1;
        if (a[i][j]=='W' && a[j][i]!='L') ok=0;
        if (a[i][j]=='D' && a[j][i]!='D') ok=0;
        if (a[i][j]=='L' && a[j][i]!='W') ok=0;
        if (!ok) {
            print("incorrect");
            return 0;
        }
    }
    print("correct");

    return 0;
}
