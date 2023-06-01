#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(string args[]) {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	vector<vector<int>> v(N+1, vector<int>(N+1, 0));
	vector<vector<int>> vSum(N+1, vector<int>(N+1, 0));


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> v[i][j];
			vSum[i][j] = vSum[i][j - 1] + vSum[i - 1][j] - vSum[i - 1][j - 1] + v[i][j];
		}
	}

	int r1, c1, r2, c2;
	int result;
	while (M--) {
		cin >> r1 >> c1 >> r2 >> c2;
		result = vSum[r2][c2] - vSum[r1-1][c2] - vSum[r2][c1-1] + vSum[r1-1][c1-1];
		cout << result << "\n";
	}


	return 0;
}