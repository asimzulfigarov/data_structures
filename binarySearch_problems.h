#pragma once

#include <vector> 

using namespace std;


// 35. Search Insert Position


int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return left;
}


// 34. Find First and Last Position of Element in Sorted Array

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int>result;
    int left = 0;
    int right = nums.size() - 1;
    int mid{ 0 };
    while (left <= right) {
        mid = left + (right - left) / 2;

        if (nums[mid] >= target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    result.push_back(mid);

    left = 0;
    right = nums.size() - 1;
    mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;

        if (nums[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    result.push_back(mid);

    return result;
}