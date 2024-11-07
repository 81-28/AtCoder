// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_fa

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int d;
    cin >> d;
    vi x(d);
    cin >> x[0];
    int a;
    for (int i = 1; i < d; i++) {
        cin >> a;
        x[i] = x[i-1]+a;
    }
    int q,s,t,xs,xt;
    cin >> q;
    rep(_,q) {
        cin >> s >> t;
        xs = x[s-1];
        xt = x[t-1];
        if (xs == xt)print("Same");
        else print(xs>xt ? s:t);
    }

    return 0;
}
