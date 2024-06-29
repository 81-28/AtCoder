// https://atcoder.jp/contests/arc180/tasks/arc180_a

// Ctrl + Shift + B                => Build
// Terminal : "./a.out"            => Run
// Terminal : "./a.out < ./in.txt" => Run

#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n+1); i++)
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
// using mint = modint1000000007;


set<string> ans;
string a = "A";
string b = "B";
string aba = "ABA";
string bab = "BAB";
void replace(set<string> nowAns) {
    set<string> nextAns;

    for (auto it = nowAns.begin(); it != nowAns.end(); it++)
    {
        const string str = *it;

        ll posA = str.find(aba);
        while (posA != string::npos) {
            string newStr = str;
            newStr.replace(posA,3,a);
            nextAns.insert(newStr);
            ans.insert(newStr);
            posA = str.find(aba, posA + 1);
        }
        ll posB = str.find(bab);
        while (posB != string::npos) {
            string newStr = str;
            newStr.replace(posB,3,b);
            nextAns.insert(newStr);
            ans.insert(newStr);
            posB = str.find(bab, posB + 1);
        }
    }
    if (nextAns.size() > 0)
    {
        replace(nextAns);
    }
}

int main() {
    ll n;
    string s;
    cin >> n >> s;

    ans.insert(s);
    set<string> newAns;
    newAns.insert(s);
    replace(newAns);

    ll ansInt = ans.size()%1000000007;
    cout << ansInt << endl;

    return 0;
}
