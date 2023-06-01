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
	vector<long> v(N, 0);	// ���� �� ����
	vector<long> c(M, 0);	// (���� �� % M)�� ������ ���� ���� ����

	cin >> v[0];

	// v ä���
	int input;
	for (int i = 1; i < N; i++) {
		cin >> input;
		v[i] = v[i - 1] + input;
	}

	// v�� �� ���Ҹ� M���� ���� ������ ������ ����
	for (int i = 0; i < N; i++) {
		int remainder = v[i] % M;

		if (remainder == 0) answer++;  // 0 ~ i ���� �� s[i]�� M���� ������ ������

		c[remainder]++;		// (s[i] % M) == remainder�� ����� ���� ī��Ʈ, ����
	}

	// (s[x] - s[y]) % M == 0 �� ��� ã��
	// <=>  (s[x] % M) - (s[y] % M) == 0 �� ��� ã��
	// <=>  M���� ���� �������� ���� s[i]�� �� 2���� �̴� ����� �� nCr = (n) * (n-1) / 2
	for (int i = 0; i < M; i++) {
		if (c[i] > 1) {
			answer += (c[i] * (c[i] - 1) / 2);
		}
	}

	cout << answer << "\n";

	return 0;
}
