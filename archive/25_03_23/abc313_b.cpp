// https://atcoder.jp/contests/abc313/tasks/abc313_b

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

    int n,m;
    cin >> n >> m;
    vi s(n,0);
    int a,b;
    rep(i,m) {
        cin >> a >> b;
        if (s[a-1]!=-1) s[a-1]=1;
        s[b-1]=-1;
    }
    int c=0,ans;
    rep(i,n) {
        if (s[i]==1) {
            c++;
            ans=i+1;
        }
    }
    print(c==1?ans:-1);

    return 0;
}
