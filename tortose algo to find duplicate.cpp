//tortose algo to find duplicate

#include <iostream>
#include <vector>

using namespace std;

int findDuplicate(vector<int>& arr) {
    int slow = arr[0];
    int fast = arr[0];

    //step1: detect cycle 
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while(slow != fast);
    fast = arr[0];

    //step2: find the start of the cycle (duplicate)
    while(slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    } 

    return slow;
}

int main() {
    vector <int> arr;
    arr = {1,3,4,2,3};
    cout << "The duplicate element is " << findDuplicate(arr) << endl;
}
