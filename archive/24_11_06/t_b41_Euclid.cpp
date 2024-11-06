// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_dn

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;

template<typename F,typename S>
ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<" "<<p.second;return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int x,y;
    cin >> x >> y;
    v<pii> anss;
    for(int i=1; x*y!=1; i++) {
        anss.pb({x,y});
        if(x>y) x-=y;
        else y-=x;
    }
    reverse(all(anss));
    int n = anss.size();
    print(n);
    rep(i,n) print(anss[i]);

    return 0;
}
