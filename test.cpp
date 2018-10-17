#include <iostream>
#include <cstdlib>
#include <assert.h>
#include "bit.h"
using namespace std;

int main() {
    // change N and vector template parameter for other tests
    // already past test under ubuntu g++ 7.3
    int N = 100;
    vector<int> nums(N, 0);
    vector<int> sum(N, 0);
    for (int i = 0; i < N; i++) {
        nums[i] = rand() % 1000;
        if (i == 0)
            sum[i] = nums[i];
        else
            sum[i] = sum[i-1] + nums[i];
    }
    BIT<int> bit_test(nums);
    for (int i = 0; i < nums.size(); i++) {
        assert(sum[i] == bit_test.prefix(i));
    }
}
