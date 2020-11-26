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

#define MOD 1000000007
#define INF 0x3f3f3f3f 

void recursion(vector<vector<bool>> grid, vector<vector<bool>> visited, int currX, int currY, int dirX, int dirY, int iter, vector<pair<int, int>> instructions) {
	if (iter == 4) {
		string out;
		for(pair<int, int> ins : instructions) {
			if(ins.first == -1 && ins.second == 0) out += "<";
			else if(ins.first == 1 && ins.second == 0) out += ">";
			else if(ins.first == 0 && ins.second == 1) out += "v";
			else if(ins.first == 0 && ins.second == -1) out += "^";
		}

		int visitedCount = 0;

		for(vector<bool> ve : visited) {
			for(bool vo : ve) {
				cout << vo;
				if(vo) visitedCount++;
			}
			cout << endl;
		}

		cout << to_string(visitedCount) << " : " << out << endl;
		return;
	}

	visited[currY][currX] = true;
	bool first = true;

	while(!grid[currY + dirY][currX + dirX]) {
		currX += dirX;
		currY += dirY;
		bool curr = grid[currY][currX];

		visited[currY][currX] = true;

		if(first && curr) return;
		first = false;

		if(currX < 0) currX = 0;
		if(currY < 0) currY = 0;
		if(currY > grid.size()) currY = grid.size();
		if(currX > grid[0].size()) currX = grid[0].size();
	}

	pair<int, int> nextPair(dirX, dirY);
	instructions.pb(nextPair);

	recursion(grid, visited, currX, currY, 1, 0, iter+1, instructions);
	recursion(grid, visited, currX, currY, -1, 0, iter+1, instructions);
	recursion(grid, visited, currX, currY, 0, 1, iter+1, instructions);
	recursion(grid, visited, currX, currY, 0, -1, iter+1, instructions);

	return;
}

void solve() {
	int height, width, directions;
	cin >> height >> width >> directions;

	vector<vector<bool>> grid;
	vector<vector<bool>> visited;
	int startX = 0, startY = 0;

	for (int i = 0; i < height; i++) {
		vector<bool> ve;
		vector<bool> vo;
		for (int j = 0; j < width; j++) {
			char cell;
			cin >> cell;
			if (cell == '#')
				ve.pb(true);
			else
				ve.pb(false);

			vo.pb(false);

			if (cell == 'O') {
				startX = j;
				startY = i;
			}

			cout << cell;
		}
		grid.pb(ve);
		visited.pb(vo);
		cout << endl;
	}

	cout << "Start:" << startX << " " << startY << endl; 

	recursion(grid, visited, startX, startY, 1, 0, 0, {});
	recursion(grid, visited, startX, startY, -1, 0, 0, {}); 
	recursion(grid, visited, startX, startY, 0, 1, 0, {});
	recursion(grid, visited, startX, startY, 0, -1, 0, {});
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);

	int _; cin >> _;

	solve();
}
