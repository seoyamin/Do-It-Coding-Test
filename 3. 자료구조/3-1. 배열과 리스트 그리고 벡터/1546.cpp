#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(string args[]) {
	int n, max, score;
	double sum = 0, m_new;
	vector<int> v;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> score;
		sum += score;
		v.push_back(score);
	}

	sort(v.begin(), v.end(), greater<>());
	max = v[0];

	m_new = sum * 100 / (n * max);
	cout << m_new;

	return 0;
}