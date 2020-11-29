#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

#define FAST_IO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define endl '\n'

#define MOD 1000000007
#define INF 0x3f3f3f3f 

void solve() {
	string word;
	cin >> word;

	ll cSynonyms;
	cin >> cSynonyms;

	ll result = 0;

	for(ll i = 0; i < cSynonyms; i++) {
		string inp;
		cin >> inp;

		ll streak = 0;
		bool valid = false;
		ll found = 0;

		for(char c : word) {
			if(inp[found] == c) {
				streak = 0;
				found++;
			}

			if(inp[found-1] == c) {
				streak++;
			}

			if(streak >= 2) {
				valid = true;
				break;
			}
		}

		if(valid) {
			result++;
		}
	}

	cout << result;
}

int main() {
	FAST_IO;

	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);

	solve();
}
