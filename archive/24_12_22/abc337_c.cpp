// https://atcoder.jp/contests/abc337/tasks/abc337_c

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){for(int i=0;i<(int)v.size();i++)os<<(i?" ":"")<<v[i];return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,a;
    cin >> n;
    vi ans(n);
    vi m(n+1);
    rep1(i,n) {
        cin >> a;
        if (a == -1) ans[0] = i;
        else m[a] = i;
    }
    rep1(i,n-1) ans[i] = m[ans[i-1]];
    print(ans);

    return 0;
}
