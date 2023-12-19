//to find the next permutation using recursive approach
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void recurPermuatation(vector<int>& ds, vector<int>& v, vector<vector<int>>& ans, vector<int>& freq) {
    int n = v.size();
    //base
    if(ds.size() == v.size()) {
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!freq[i]) {
            ds.push_back(v[i]);
            freq[i] = 1;
            recurPermuatation(ds, v, ans, freq);
            freq[i] = 0;
            ds.pop_back();
    }
 }
}

vector<vector<int>> permute(vector<int>& v) {
    int n = v.size();
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> freq(n, 0);

    recurPermuatation(ds, v, ans, freq);

    return ans;

}

vector<int> findNextPermutation(vector<int>& v) {
    vector<vector<int>> allPermut = permute(v);
    sort(allPermut.begin(), allPermut.end());

    auto it = find(allPermut.begin(), allPermut.end(), v);
    if(it != allPermut.end() && next(it) != allPermut.end()) {
        return *(next(it));
    }

    sort(v.begin(), v.end());
    return v;
}

int main() {
    vector<int> v{1, 2, 3};

    vector<int> ans = findNextPermutation(v);

    //find the dimentions of ans
    int n = ans.size();

    //print the ans
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

}
