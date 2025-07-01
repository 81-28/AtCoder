// https://atcoder.jp/contests/abc396/tasks/abc396_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int q;
    cin >> q;
    stack<int> s;
    rep(i,100) s.push(0);
    int m,x;
    rep(i,q) {
        cin >> m;
        if (m==1) {
            cin >> x;
            s.push(x);
        }
        if (m==2) {
            print(s.top());
            s.pop();
        }
    }

    return 0;
}
