//brute(TC = O(N^2logN^2), SC = O(N^2))

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// function to display first N maximum sum
// combinations
void KMaxCombinations(vector<int>& A, vector<int>& B, int N, int K) {
    // max heap.
    priority_queue<int> pq;

    // insert all the possible combinations
    // in max heap.
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            pq.push(A[i] + B[j]);

    // pop first N elements from max heap
    // and display them.
    int count = 0;
    while (count < K) {
        cout << pq.top() << " ";
        pq.pop();
        count++;
    }
}

// Driver Code.
int main() {
    // Convert arrays to vectors
    vector<int> A = {3, 2};
    vector<int> B = {1, 4};
    int N = A.size(); // or B.size(), since they are of the same size
    int K = 2;

    // Function call
    KMaxCombinations(A, B, N, K);
    return 0;
}

//*****************************************************************************************************************************************************************************
//optimal(TC = O(NlogN) , SC = O(N))

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

// Function prints k maximum possible combinations
void KMaxCombinations(vector<int>& A, vector<int>& B, int K) {
    // sort both arrays A and B in reverse order
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    int N = A.size();

    // Max heap which contains tuple of the format
    // (sum, (i, j)) i and j are the indices
    // of the elements from array A
    // and array B which make up the sum.
    priority_queue<pair<int, pair<int, int>>> pq;

    // my_set is used to store the indices of
    // the pair(i, j) we use my_set to make sure
    // the indices do not repeat inside max heap.
    set<pair<int, int>> my_set;

    // initialize the heap with the maximum sum
    // combination ie (A[0] + B[0])
    // and also push indices (0, 0) along
    // with the sum.
    pq.push(make_pair(A[0] + B[0], make_pair(0, 0)));
    my_set.insert(make_pair(0, 0));

    // iterate upto K
    for (int count = 0; count < K; count++) {
        // tuple format (sum, (i, j)).
        pair<int, pair<int, int>> temp = pq.top();
        pq.pop();

        cout << temp.first << endl;

        int i = temp.second.first;
        int j = temp.second.second;

        // insert (A[i + 1] + B[j], (i + 1, j))
        // into max heap.
        if (i + 1 < N) {
            int sum = A[i + 1] + B[j];
            pair<int, int> temp1 = make_pair(i + 1, j);

            // insert only if the pair (i + 1, j) is
            // not already present inside the map i.e.
            // no repeating pair should be present inside
            // the heap.
            if (my_set.find(temp1) == my_set.end()) {
                pq.push(make_pair(sum, temp1));
                my_set.insert(temp1);
            }
        }

        // insert (A[i] + B[j + 1], (i, j + 1))
        // into max heap.
        if (j + 1 < N) {
            int sum = A[i] + B[j + 1];
            pair<int, int> temp1 = make_pair(i, j + 1);

            // insert only if the pair (i, j + 1)
            // is not present inside the heap.
            if (my_set.find(temp1) == my_set.end()) {
                pq.push(make_pair(sum, temp1));
                my_set.insert(temp1);
            }
        }
    }
}

// Driver Code.
int main() {
    vector<int> A = {1, 4, 2, 3};
    vector<int> B = {2, 5, 1, 6};
    int K = 4;

    // Function call
    KMaxCombinations(A, B, K);
    return 0;
}

