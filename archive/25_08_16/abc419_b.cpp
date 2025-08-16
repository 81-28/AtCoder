// https://atcoder.jp/contests/abc419/tasks/abc419_b

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
        int n;
        cin >> n;
        if (n==1) {
            int x;
            cin >> x;
            qu.push(x);
        }
        if (n==2) {
            print(qu.top());
            qu.pop();
        }
    }

    return 0;
}
