// https://atcoder.jp/contests/abc311/tasks/abc311_a

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
template<typename T>
using v=vector<T>;
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    v<bool> b(3,0);
    rep(i,n) {
        b[s[i]-'A']=1;
        if (b[0]&&b[1]&&b[2]) {
            print(i+1);
            return 0;
        }
    }
    return 0;
}
