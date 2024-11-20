// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_dx

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    stack<int> f;
    rep(i,n) {
        if(s[i]=='(') {
            f.push(i+1);
        } else {
            print(f.top(),i+1);
            f.pop();
        }
    }

    return 0;
}
