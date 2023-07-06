#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N;
    cin >> N;

    int input;
    vector<int> v;
    for(int i=0 ; i<N ; i++) {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    int idx_start, idx_end;
    int answer = 0;
    for(int i=0 ; i<N ; i++) {
        int idx_start = 0, idx_end = N-1;

        while(idx_start < idx_end) {
            if(v[idx_start] + v[idx_end] < v[i]) {
                idx_start++;
            }

            else if(v[idx_start] + v[idx_end] > v[i]) {
                idx_end--;
            }

            else {
                // 다른 두 수의 합인 경우만 인정
                if(idx_start != i && idx_end != i) {
                    answer++;
                    break;
                }

                else if(idx_start == i) {
                    idx_start++;
                }

                else if(idx_end == i) {
                    idx_end--;
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}