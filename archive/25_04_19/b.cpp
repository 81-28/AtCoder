// https://atcoder.jp/contests/abc402/tasks/abc402_b

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
    queue<int> qu;
    int n,x;
    rep(i,q) {
        cin >> n;
        if (n==1) {
            cin >> x;
            qu.push(x);
        }
        if (n==2) {
            if (!qu.empty()) {
                print(qu.front());
                qu.pop();
            }
        }
    }

    return 0;
}
