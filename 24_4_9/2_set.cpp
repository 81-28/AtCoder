// https://atcoder.jp/contests/abc296/tasks/abc296_c

// Ctrl + Shift + B       => Build
// Terminal << "./a.out"  => Run

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

int main() {
    int n,x;
    cin >> n >> x;

    // me
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i]-a[j] == x)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }


    // ans
    // https://chat.openai.com/c/cd3b67ea-2237-446b-a971-0404d810aa07
	set<int>s;
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		s.insert(t);
	}
	
	for(auto a:s){
		if(s.find(a+x)!=s.end()){
			cout << "Yes" << endl;
			return 0;
		}
	}


    cout << "No" << endl;
    
    return 0;
}
