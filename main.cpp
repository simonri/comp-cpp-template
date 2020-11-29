#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)(x).size()

#define endl '\n'
#define MOD 1000000007
#define INF 0x3f3f3f3f 

string output;

int height, width, cInstructions;
int startX = 0, startY = 0;

vector<vector<int>> directions {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

pair<ll, vector<int>> recursion(vector<vector<int>> grid, vector<int> dir) {
	ll bestPoints = 0;
	vector<int> bestDir {0, 0};

	int currX = startX, currY = startY;
	int currentCell = 0;
	int len = 0;

	while(currentCell != 1) {
		currX += dir[0];
		currY += dir[1];

		currentCell = grid[currY][currX];

		if(currentCell != 2)
			len++;
	}

	if(len > bestPoints) {
		bestPoints = len;
		bestDir = dir;
	} else if(len == bestPoints) {
		if(bestDir != dir) {
			int a = recursion(grid, bestDir).first;
			int b = recursion(grid, dir).first;

			if(b > a) {
				bestDir = dir;
				bestPoints = len;
			}
		} else {
			bestDir = dir;
			bestPoints = len;
		}
	}

	return make_pair(bestPoints, bestDir);
}

void run(vector<vector<int>> grid) {
	vector<vector<int>> outDirections;

	for(int i = 0; i < cInstructions; i++) {
		vector<int> bestDir;
		ll bestPoints = 0;

		for(vector<int> dir : directions) {
			pair<ll, vector<int>> eeeee = recursion(grid, dir);

			if(eeeee.first > bestPoints) {
				bestPoints = eeeee.first;
				bestDir = eeeee.second;
			}
		}

		outDirections.pb(bestDir);
		int currX = startX, currY = startY;
		int currentCell = 0;
		while(currentCell != 1) {
			currX += bestDir[0];
			currY += bestDir[1];

			int currentCell = grid[currY][currX];
			if(currentCell == 1) break;
			grid[currY][currX] = 2;
		}

		startX = currX - bestDir[0];
		startY = currY - bestDir[1];


		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				int cell = grid[i][j];

				if(i == startY && j == startX) {
					cout << "O";
					continue;
				}

				if(cell == 1) {
					cout << "#";
				} else if(cell == 2) {
					cout << "-";
				} else {
					cout << " ";
				}
			}
			cout << endl;
		}
		
		cout << endl << endl;
	}
	
	for(vector<int> d: outDirections) {
		if(d[0] == 1 && d[1] == 0) 
			cout << ">";
		else if(d[0] == -1 && d[1] == 0)
			cout << "<";
		else if(d[0] == 0 && d[1] == -1)
			cout << "^";
		else if(d[0] == 0 && d[1] == 1)
			cout << "v";
	}
}

void solve() {
    cin >> height >> width >> cInstructions;

    vector<vector<int>> grid;

    for (int i = 0; i < height; i++) {
        vector<int> ve;
        for (int j = 0; j < width; j++) {
            char cell;
            cin >> cell;
            if (cell == '#')
                ve.pb(1);
            else
                ve.pb(0);

            if (cell == 'O') {
                startX = j;
                startY = i;
						}
        }
        grid.pb(ve);
    }

		run(grid);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);

    int _; cin >> _;

    solve();
}
