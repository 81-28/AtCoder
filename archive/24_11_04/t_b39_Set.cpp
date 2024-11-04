// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_dl

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
#define pb push_back
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,d;
    cin >> n >> d;
    vvi g(d+1);
    int x,y;
    rep1(i,n) {
        cin >> x >> y;
        g[x].pb(y);
    }
    int ans = 0;
    multiset<int> s;
    vi gi;
    int m;
    rep1(i,d) {
        gi = g[i];
        for (int val : gi) s.insert(val);
        if (s.rbegin() != s.rend()) {
            m = *s.rbegin();
            s.erase(s.find(m));
            ans+=m;
        }
    }
    print(ans);

    return 0;
}
