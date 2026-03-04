#pragma once

#include <vector>
#include <numeric>

using namespace std;


//78. Subsets


void createSubset(vector<int>& nums, int index, vector<vector<int>>& res, vector<int>& subset) {
    if (index == nums.size()) {
        res.push_back(subset);
        return;
    }

    subset.push_back(nums[index]);
    createSubset(nums, index + 1, res, subset);

    subset.pop_back();
    createSubset(nums, index + 1, res, subset);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> subset;

    createSubset(nums, 0, res, subset);
    return res;
}



//39. Combination Sum - my solution

void makeSubset(vector<int>& nums, int index, vector<vector<int>>& res, vector<int>& subset, int target) {
    if (index == nums.size()) return;
    for (int e : subset) {
        int currentSum = std::accumulate(subset.begin(), subset.end(), 0);
        if (currentSum == target)
            res.push_back(subset);
        if (currentSum >= target)
            return;
    }

    subset.push_back(nums[index]);
    makeSubset(nums, index, res, subset, target);

    subset.pop_back();
    makeSubset(nums, index + 1, res, subset, target);

}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> subset;

    makeSubset(candidates, 0, res, subset, target);
    return res;
}

// Another soluton

class CombinatioSum {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        makeCombinationSum(candidates, target, 0, comb, 0, res);
        return res;
    }

private:
    void makeCombinationSum(std::vector<int>& candidates, int target, int idx, vector<int>& comb, int total, vector<vector<int>>& res) {
        if (total == target) {
            res.push_back(comb);
            return;
        }

        if (total > target || idx >= candidates.size()) {
            return;
        }

        comb.push_back(candidates[idx]);
        makeCombinationSum(candidates, target, idx, comb, total + candidates[idx], res);
        comb.pop_back();
        makeCombinationSum(candidates, target, idx + 1, comb, total, res);
    }
};



