#pragma once

#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

// 283. Move Zeroes

void moveZeroes(vector<int>& nums) {
    int i{ 0 };
    int j{ 1 };

    while (j < nums.size()) {
        if (nums[i] == 0) {
            if (nums[j] == 0) {
                j++;
                continue;
            }
            else {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        i++;
        j++;
    }
}


// Textbook implementation

void moveZeroesTB(vector<int>& nums) {
    int i = 0; // slow pointer: position to place next non-zero

    for (int j = 0; j < nums.size(); ++j) { // fast pointer: scans the array
        if (nums[j] != 0) {
            swap(nums[i], nums[j]);
            i++;
        }
    }
}

// Implementation from course 

void moveZeroesNew(vector<int>& nums) {
    int start = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            int temp = nums[start];
            nums[start] = nums[i];
            nums[i] = temp;
            start++;
        }
    }
}



// 75. Sort Colors


void sortColors(vector<int>& nums) {
    int i{ 0 };
    int j{ 1 };
    while (j < nums.size()) {
        if (nums[i] > 0) {
            if (nums[j] == 0) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            else {
                j++;
                continue;
            }
        }
        i++;
        j++;
    }
    j = i + 1;

    while (j < nums.size()) {
        if (nums[i] > 1) {
            if (nums[j] == 1) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            else {
                j++;
                continue;
            }
        }
        i++;
        j++;
    }

}


    // Course methods

void sortColorsCV(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    int i = 0;

    while (i <= right) {
        if (arr[i] == 0) {
            int temp = arr[i];
            arr[i] = arr[left];
            arr[left] = temp;
            i++;
            left++;
        }
        else if (arr[i] == 2) {
            int temp = arr[i];
            arr[i] = arr[right];
            arr[right] = temp;
            right--;
        }
        else {
            i++;
        }
    }
}



// 169. Majority Element

int majorityElement(vector<int>& nums) {
    int times = (nums.size()) / 2;
    unordered_map<int, int> map;

    for (size_t i = 0; i < nums.size(); i++)
    {
        map[nums[i]] += 1;
        if (map[nums[i]] > times)
            return nums[i];
    }

}


// Space complexity O(1)

int majorityElementLessSpace(vector<int>& nums) {
    int majElement = nums[0];
    int count{ 1 };

    for (size_t i = 1; i < nums.size(); i++)
    {
        if (majElement != nums[i])
            count--;
        else
            count++;

        if (!count) {
            majElement = nums[i];
            count = 1;
        }
            
    }
    return majElement;
}


// Sort function solution 


int majorityElementSort(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    return nums[n / 2];
}