// https://atcoder.jp/contests/abc391/tasks/abc391_c

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
    cin >> n >> q;
    vi a(n+1);
    v<set<int>> b(n+1);
    rep1(i,n){
        a[i]=i;
        b[i].insert(i);
    }
    int ans=0;
    int m,p,h;
    int pp;
    rep(i,q) {
        cin >> m;
        if (m==1) {
            cin >> p >> h;
            pp=a[p];
            if (b[pp].size() == 2) ans--;
            if (b[h].size() == 1) ans++;
            b[pp].erase(p);
            b[h].insert(p);
            a[p] = h;
        }
        if (m==2) {
            print(ans);
        }
    }

    return 0;
}
