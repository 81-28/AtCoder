// https://atcoder.jp/contests/abc347/tasks/abc347_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a,b;
    cin >> n;
    int d[n];
    cin >> a;
    cin >> b;
    int w = a+b;
    for (int i = 0; i < n; i++){
        cin >> d[i];
        d[i] = d[i]%w;
    }

    int min = d[0];
	for (int i = 1; i < n; i++){
		min = (min > d[i]) ? d[i] : min;
	}
    int max = d[0];
	for (int i = 1; i < n; i++){
        max = (d[i] > max) ? d[i] : max;
	}

    if (max - min < a){
        cout << "Yes" << endl;
    }else{
        for (int i = 0; i < n; i++){
            d[i] = (d[i]+a)%w;
        }

        min = d[0];
        for (int i = 1; i < n; i++){
            min = (min > d[i]) ? d[i] : min;
        }
        max = d[0];
        for (int i = 1; i < n; i++){
            max = (d[i] > max) ? d[i] : max;
        }

        if (max - min < a){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    
    return 0;
}
