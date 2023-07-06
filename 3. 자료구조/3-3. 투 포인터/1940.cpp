#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N, M;
    int answer = 0;
    vector<int> v;

    cin >> N >> M;

    int input;
    for(int i=0 ; i<N ; i++) {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    int idx_start = 0, idx_end = N-1;
    while(idx_start < idx_end) {
        if(v[idx_start] + v[idx_end] < M) {
            idx_start++;
        }

        else if(v[idx_start] + v[idx_end] > M) {
            idx_end--;
        }

        else {
            answer++;
            idx_start++;
            idx_end--;
        }

    }

    cout << answer << endl;

    return 0;
}
