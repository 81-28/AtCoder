// https://atcoder.jp/contests/abc309/tasks/abc309_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;

template<typename T>
istream &operator>>(istream &is,vector<T> &v){for(T &in:v)is>>in;return is;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<string> a(n);
    cin >> a;
    v<string> b=a;
    rep(i,n-1) {
        b[0][i+1]=a[0][i];
        b[i+1][n-1]=a[i][n-1];
        b[n-1][n-2-i]=a[n-1][n-1-i];
        b[n-2-i][0]=a[n-1-i][0];
    }
    rep(i,n) print(b[i]);

    return 0;
}
