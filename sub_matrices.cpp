#include <iostream>
using namespace std;

int array[5][5];

int subSum(int top, int left, int height, int width) {
    int sum = 0;
    for(int i = top; i < top + height; i++) {
        for(int j = left; j < left + width; j++) {
            sum += array[i][j];
        }
    }
    return sum;
}

int main() {
    int N = 0, S = 0, count = 0;
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> array[i][j];
        }
    }

    cin >> S;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int size = 1;
            while(i + size <= N && j + size <= N) {
                int sum = subSum(i, j, size, size);
                if(sum == S) {
                    count++;
                }
                else if(sum > S) {
                    break;
                }
                size++;
            }
        }
    } 

    cout << count;
    return 0;
}