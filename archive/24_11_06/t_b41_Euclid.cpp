// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_dn

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define all(v) v.begin(),v.end()
template<typename T>
using v=vector<T>;
using pii=pair<int,int>;

// template<typename T>
// ostream &operator<<(ostream &os,const vector<T> &v){for(int i=0;i<(int)v.size();i++)os<<(i?"\n":"")<<v[i];return os;}
// template<typename F,typename S>
// ostream &operator<<(ostream &os,const pair<F,S> &p){os<<p.first<<" "<<p.second;return os;}
template<typename F,typename S>
ostream &operator<<(ostream &os,const vector<pair<F,S>> &v){for(int i=0;i<(int)v.size();i++)os<<(i?"\n":"")<<v[i].first<<" "<<v[i].second;return os;}
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int x,y;
    cin >> x >> y;
    v<pii> anss;
    while(x!=y) {
        anss.pb({x,y});
        if(x>y) x-=y;
        else y-=x;
    }
    int n = anss.size();
    // cout<<n<<'\n';
    // for(int i=n-1; i>=0; i--) cout<<anss[i].first<<' '<<anss[i].second<<'\n';
    reverse(all(anss));
    print(n);
    print(anss);

    return 0;
}
