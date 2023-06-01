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

	long answer = 0;
	vector<long> v(N, 0);	// 구간 합 저장
	vector<long> c(M, 0);	// (구간 합 % M)이 동일한 원소 개수 저장

	cin >> v[0];

	// v 채우기
	int input;
	for (int i = 1; i < N; i++) {
		cin >> input;
		v[i] = v[i - 1] + input;
	}

	// v의 각 원소를 M으로 나눈 나머지 값으로 변경
	for (int i = 0; i < N; i++) {
		int remainder = v[i] % M;

		if (remainder == 0) answer++;  // 0 ~ i 구간 합 s[i]가 M으로 나누어 떨어짐

		c[remainder]++;		// (s[i] % M) == remainder인 경우의 개수 카운트, 저장
	}

	// (s[x] - s[y]) % M == 0 인 경우 찾기
	// <=>  (s[x] % M) - (s[y] % M) == 0 인 경우 찾기
	// <=>  M으로 나눈 나머지가 같은 s[i]들 중 2개를 뽑는 경우의 수 nCr = (n) * (n-1) / 2
	for (int i = 0; i < M; i++) {
		if (c[i] > 1) {
			answer += (c[i] * (c[i] - 1) / 2);
		}
	}

	cout << answer << "\n";

	return 0;
}
