// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_eh

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
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
    vi f(n);
    int a,b;
    rep(i,m) {
        cin >> a >> b;
        f[a-1]++;
        f[b-1]++;
    }
    print(max_element(all(f))-f.begin()+1);

    return 0;
}
