// https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_dk

#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
template<typename T>
using v=vector<T>;
using vi=v<int>;
using vvi=v<vi>;

void print(){cout<<'\n';}
template<typename Head,typename... Tail>
void print(const Head &head,const Tail &... tail){cout<<head;((cout<<' '<<tail),...);cout<<'\n';}

template<typename T>
auto sum(const vector<T>& v){return accumulate(v.begin(),v.end(),T{});}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    vi h(n,0);
    vvi g(n);
    queue<int> q;
    rep(i,n-1) {
        if (i==0 && s[i]=='A') {
            h[i] = 1;
            q.push(i);
        }
        if ((i==n-2 && s[i]=='B') || (i!=n-2 && s.substr(i,2) == "BA")) {
            h[i+1] = 1;
            q.push(i+1);
        }
        if (s[i] == 'A') g[i].pb(i+1);
        else g[i+1].pb(i);
    }
    int pos;
    vi nowG;
    while (!q.empty()) {
        pos = q.front();
        q.pop();
        nowG = g[pos];
        for (int val : nowG) {
            h[val] = max(h[val],h[pos]+1);
            q.push(val);
        }
    }
    print(sum(h));

    return 0;
}
