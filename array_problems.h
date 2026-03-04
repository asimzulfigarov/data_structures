#pragma once

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


// 53. Maximum Subarray


// Here we dump negative number so that we do not deacre next subarray

int maxSubArray(vector<int>& nums) {
    int maxSoFar = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (currentSum < 0) {
            currentSum = 0;
        }
        currentSum += nums[i];
        if (currentSum > maxSoFar) {
            maxSoFar = currentSum;
        }
    }
    return maxSoFar;
}



// 121. Best Time to Buy and Sell Stock


//Here we just iterate forward by finding profit - deducting smaller index from bigger index --- we save current max profit and ay the same time saving smallest stock price entire

int maxProfitWithFunctions(vector<int>& prices) {
    int minimum = prices[0];
    int ans = 0;
    for (int i = 1; i < prices.size(); i++) {
        int currentProfit = prices[i] - minimum;
        ans = max(ans, currentProfit);
        minimum = min(minimum, prices[i]);
    }
    return ans;
}

int maxProfit(vector<int>& prices) {
    int minimum = prices[0];
    int ans = 0;
    for (int i = 1; i < prices.size(); i++) {
        int currentProfit = prices[i] - minimum;

        // replace ans = max(ans, currentProfit);
        if (currentProfit > ans) {
            ans = currentProfit;
        }

        // replace minimum = min(minimum, prices[i]);
        if (prices[i] < minimum) {
            minimum = prices[i];
        }
    }
    return ans;
}


// 167. Two Sum II - Input Array Is Sorted

// Note: becuase it is sorted we can from back and front - decreasing or increasing depending on reult

vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> answer;
    int i = 0;
    int j = numbers.size() - 1;

    while (i < j) {
        int result = numbers[i] + numbers[j];

        if (result < target) i++;
        else if (result > target) j--;
        else {
            i++;
            j++;
            answer.push_back(i);
            answer.push_back(j);
            return answer;
        }
    }
}


//  152. Maximum Product Subarray


//We from front and back, cause there can be edge cases wehre the biggest product is at the end, and bedore it come negative nmber and we wont get it

int maxProduct(vector<int>& nums) {
        int ans = 0;
        if (nums.size() == 1) { return nums[0];}
        int currentProduct = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] != 0) {
                currentProduct = currentProduct * nums[i];
                if (currentProduct > ans) {
                    ans = currentProduct;
                }
            }
            else 
                currentProduct = 1;
        }
        currentProduct = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] != 0) {
                currentProduct = currentProduct * nums[i];
                if (currentProduct > ans) {
                    ans = currentProduct;
                }
            }
            else 
                currentProduct = 1;
        }
        return ans;
}

//Two Sum



vector<int> twoSumEz(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // value -> index
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mp.find(complement) != mp.end()) {
            return { mp[complement], i };
        }
        mp[nums[i]] = i;
    }
    return {};
}


//




//189. Rotate Array


// O(n) space complexity - because we copy the array

void rotateCopy(vector<int>& nums, int k) {
    vector<int> result;
    if (k > nums.size()) k = k % nums.size();
    int i = nums.size() - k;
    while (i < nums.size()){
        result.push_back(nums[i]);
        i++;
    }

    i = nums.size() - k;
    for (size_t j = 0; j < i; j++)
    {
        result.push_back(nums[j]);
    }

    nums = result;
}

// O(1) space complexity - because we copy the array

void reverse(vector<int>&, int, int);

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    reverse(nums, 0, n);
    reverse(nums, 0, k - 1);
    reverse(nums, k, n);
}

void reverse(vector<int>& nums, int start, int end) {
    int i = start, j = end;

    while (i < j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++;
        j++;
    }
}


//485. Max Consecutive Ones

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxSoFar{ 0 };
    int current{ 0 };

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i])
            current++;
        else
            current = 0;

        if (current > maxSoFar)
            maxSoFar = current;
    }

    return maxSoFar;
}


// Product of Array Except Self

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);

    // Pass 1: prefix products
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    // Pass 2: postfix products
    int postfix = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= postfix;
        postfix *= nums[i];
    }

    return result;
}


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        // Remove indices outside the window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Maintain decreasing order in deque
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i);

        // Add maximum for the current window
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int trap(vector<int>& height) {
    int n = height.size();

    // nothing left and nothing right to most left and most right indeces 

    vector<int> left(n);
    vector<int> right(n);

    left[0] = height[0];
    right[n - 1] = height[n - 1];

    // here we are trying to find the heighest bar from left seen so far, and current index is included 

    for (int i = 1; i < n; i++) {
        left[i] = max(left[i - 1], height[i]);
    }

    // here we are trying to find the heighest bar from right seen so far, and current index is included 

    for (int j= n - 2; j >= 0; j--) {
        right[j] = max(right[j + 1], height[j]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans += min(left[i], right[i]) - height[i];
    }

    return ans;

}

// 11. Container With Most Water


int maxArea(vector<int>& height) {
    int maxAreaSoFar{ 0 };
    int n = height.size();
    int i{ 0 };
    int j{ n - 1 };
    

    while (i != j) {
        int length = min(height[i], height[j]);
        int width = j - i;
        int currenArea = length * width;
        if (currenArea > maxAreaSoFar)
            maxAreaSoFar = currenArea;
        if (height[i] < height[j])
            i++;
        else
            j--;
    }
    return maxAreaSoFar;
}