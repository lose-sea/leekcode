/*
 * @lc app=leetcode.cn id=977 lang=c
 *
 * [977] 有序数组的平方
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(const void* e1, const void* e2) {
    return *(int*)e1 - *(int*)e2; 
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        nums[i] = nums[i] * nums[i]; 
    } 
    qsort(nums, numsSize, sizeof(int), cmp);  
    *returnSize = numsSize; 
    return nums; 
}
// @lc code=end

