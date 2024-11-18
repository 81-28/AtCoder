// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_dp

#include<bits/stdc++.h>
using namespace std;

#define rep1(i,n) for(int i=1;i<(int)(n+1);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vi ans(n+1,m);
    int a;
    rep1(i,m) {
        cin >> a;
        ans[a]--;
    }
    rep1(i,n) print(ans[i]);

    return 0;
}