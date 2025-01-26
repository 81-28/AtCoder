// https://atcoder.jp/contests/abc328/tasks/abc328_c

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,q;
    string s;
    cin >> n >> q >> s;
    vi t(n,0);
    rep1(i,n-1) t[i] = s[i-1]==s[i];
    rep1(i,n-1) t[i] += t[i-1];

    int l,r;
    rep(i,q) {
        cin >> l >> r;
        print(t[r-1]-t[l-1]);
    }

    return 0;
}
