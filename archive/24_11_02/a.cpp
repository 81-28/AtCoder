// https://atcoder.jp/contests/abc378/tasks/abc378_a

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

    vi b(4,0);
    int ans = 0;
    int a;
    rep(i,4) {
        cin >> a;
        if (b[a-1]) ans++;
        b[a-1]^=1;
    }
    print(ans);

    return 0;
}
