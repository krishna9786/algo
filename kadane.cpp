#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int>& v, int start, int end) {
    for (int i = start; i <= end; i++) cout << v[i] << " ";
}

int maxSum(vector<int>& v) {
    int n = v.size();

    int maxi = INT_MIN;
    int sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;

    for(int i = 0; i < n; i++) {
        if(sum == 0) start = i;
        sum += v[i];

        if(sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if(sum < 0) sum = 0;
    }
    printArr(v, ansStart, ansEnd);
    cout << endl;

    return maxi;
}


int main() {
    vector<int> v{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int ans = maxSum(v);
    cout << "Maximum Sum: " << ans << endl;

    return 0;
}
