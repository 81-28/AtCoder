// https://atcoder.jp/contests/abc389/tasks/abc389_b

#include<bits/stdc++.h>
using namespace std;

using ll=long long;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    ll x;
    cin >> x;
    int i = 1;
    while(true) {
        x /= i;
        if (x == 1) {
            print(i);
            return 0;
        }
        i++;
    }

    return 0;
}
