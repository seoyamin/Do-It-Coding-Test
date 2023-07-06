#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;

    int start_idx = 1, end_idx = 1;
    int sum = 1, count = 1;

    while(end_idx < N) {
        if(sum < N) {
            end_idx++;
            sum += end_idx;
        }

        else if(sum == N) {
            count++;
            end_idx++;
            sum += end_idx;
        }

        else {
            sum -= start_idx;
            start_idx++;
        }
    }

    cout << count << endl;

    return 0;
}