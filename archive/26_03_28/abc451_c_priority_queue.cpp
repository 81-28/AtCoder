// https://atcoder.jp/contests/abc451/tasks/abc451_c

#include<bits/stdc++.h>
using namespace std;

template<typename T>
using v=vector<T>;
using vi=v<int>;

template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<endl;}


signed main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int q;
    cin >> q;
    priority_queue<int,vi,greater<>> qu;
    while (q--) {
        int m,h;
        cin >> m >> h;
        if (m==1) {
            qu.push(h);
        }
        if (m==2) {
            while (!qu.empty()) {
                if (qu.top()>h) break;
                qu.pop();
            }
        }
        print(qu.size());
    }

    return 0;
}
