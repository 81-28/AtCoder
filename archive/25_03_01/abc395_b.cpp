// https://atcoder.jp/contests/abc395/tasks/abc395_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    v<string> s(n,string(n,'.'));
    for (int i=0; i<=(n-1)/2; i+=2) {
        for (int j=i; j<n-i; j++) {
            s[i][j] = '#';
            s[j][n-1-i] = '#';
            s[n-1-i][n-1-j] = '#';
            s[n-1-j][i] = '#';
        }
    }
    rep(i,n) print(s[i]);

    return 0;
}
