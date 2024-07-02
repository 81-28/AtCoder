// 

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define substring(s,l,r) s.substr(l,r-l)
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
// using mint = modint1000000007;
// using mint = modint998244353;

vector<int> input(int n) {
    vector<int> As;
    As.reserve(n);
    rep(i,n) {
        int A;
        cin >> A;
        As.push_back(A);
    }
    return As;
}
void print(vector<int> anss) {
    rep(i,anss.size()) cout << anss[i] << " ";
    cout << endl;
}
void printn(vector<int> anss) {
    rep(i,anss.size()) cout << anss[i] << endl;
}



int main() {
    int ans = 0;
    vector<int> anss;

    int n;
    cin >> n;
    vector<int> as = input(n);



    anss = as;



    cout << ans << endl;
    print(anss);
    printn(anss);


    return 0;
}
