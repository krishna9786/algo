//finding the next permutation with the help of backtrecking (swap methode)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void recurPermute(int ind, vector<int>& v, vector<vector<int>>& ans) {
    int n = v.size();

    // base
    if (ind == n) {
        ans.push_back(v);
        return;
    }

    // otherwise, call the recursive permutation function
    for (int i = ind; i < n; i++) {
        swap(v[ind], v[i]);
        recurPermute(ind + 1, v, ans);
        swap(v[ind], v[i]);
    }
}

vector<vector<int>> permute(vector<int>& v) {
    int n = v.size();
    vector<vector<int>> ans;

    recurPermute(0, v, ans);

    return ans;
}

vector<int> nextPermutation(vector<int>& v) {
    vector<vector<int>> allPermut = permute(v);
    sort(allPermut.begin(), allPermut.end());

    auto it = find(allPermut.begin(), allPermut.end(), v);
    if (it != allPermut.end() && next(it) != allPermut.end()) {
        return *next(it);
    }

    sort(v.begin(), v.end());
    return v;
}

int main() {
    vector<int> v{1, 2, 3};

    vector<vector<int>> allPermutations = permute(v);

    vector<int> nextPerm = nextPermutation(v);

    for (int num : nextPerm) {
        cout << num << " ";
    }

    return 0;
}
