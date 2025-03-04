// https://atcoder.jp/contests/abc318/tasks/abc318_b

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    vvi s(101,vi(101,0));
    int a,b,c,d;
    rep(i,n) {
        cin >> a >> b >> c >> d;
        s[a][c]++;
        s[b][c]--;
        s[a][d]--;
        s[b][d]++;
    }
    int ans=0;
    rep(i,100)rep(j,100) {
        if(i) {
            if(j) s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            else s[i][j]+=s[i-1][j];
        } else {
            if(j) s[i][j]+=s[i][j-1];
        }
        ans+=(s[i][j]>0);
    }
    print(ans);

    return 0;
}