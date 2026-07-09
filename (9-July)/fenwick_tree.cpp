#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
public:
    vector<int> bit;
    vector<int> nums;
    int n;

    FenwickTree(int size) {
        n = size;
        bit.resize(n + 1, 0);
        nums.resize(n);
    }

    // Internal update
    void updateBIT(int index, int delta) {

        index++;   // Convert to 1-based indexing

        while (index <= n) {
            bit[index] += delta;
            index += (index & -index);
        }
    }

    // Build Fenwick Tree
    void build(vector<int> &arr) {

        nums = arr;

        for (int i = 0; i < n; i++) {
            updateBIT(i, nums[i]);
        }
    }

    // Prefix Sum [0...index]
    int prefixSum(int index) {

        index++;

        int sum = 0;

        while (index > 0) {
            sum += bit[index];
            index -= (index & -index);
        }

        return sum;
    }

    // Range Sum Query
    int query(int left, int right) {

        return prefixSum(right) -
               (left == 0 ? 0 : prefixSum(left - 1));
    }

    // Point Update
    void update(int index, int newValue) {

        int delta = newValue - nums[index];

        nums[index] = newValue;

        updateBIT(index, delta);
    }
};

int main() {

    vector<int> nums = {4, -3, 6, 1, 2, 5};

    int n = nums.size();

    FenwickTree *ft = new FenwickTree(n);

    ft->build(nums);

    cout << "Sum of values from 2 to 4 is : "
         << ft->query(2, 4) << "\n";

    ft->update(2, 12);

    cout << "Sum of values from 2 to 4 is : "
         << ft->query(2, 4) << "\n";

    return 0;
}