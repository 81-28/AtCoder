// https://atcoder.jp/contests/abc404/tasks/abc404_a

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

    string s;
    cin >> s;
    vi a(26,0);
    for(char c:s)a[c-'a']++;
    rep(i,26) {
        if (a[i]==0) {
            print(char(i+'a'));
            return 0;
        }
    }

    return 0;
}
