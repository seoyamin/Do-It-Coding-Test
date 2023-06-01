#include <stdio.h>
#include <iostream>

using namespace std;

int main(string args[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int s[100001];

	s[0] = 0;

	cin >> N >> M;

	int input;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		s[i] = s[i - 1] + input;
	}

	while(M--) {
		int a, b;
		cin >> a >> b;
		cout << s[b] - s[a - 1] << "\n";
	}

	return 0;
}