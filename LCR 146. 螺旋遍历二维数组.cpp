#include<iostream> 
#include<vector>
using namespace std; 

class Solution {
public:
    vector<int> spiralArray(vector<vector<int>>& array) {  
        if (array.empty()) {
            return {}; 
        }
        // 行数
        int m = array.size();  
        // 列数
        int n = array[0].size(); 
        // 元素总数
        int size = m * n; 
        vector<int> result; 
        result.resize(size); 
        int num = 0;  
        int top = 0; 
        int bottom = m - 1; 
        int left = 0; 
        int right = n - 1; 
        while (num < size) { 

            for (int i = left; i <= right && top <= bottom; i++) {
                result[num++] = array[top][i]; 
            } 
            top++; 
            for (int i = top; i <= bottom && left <= right; i++) {
                result[num++] = array[i][right];  
            } 
            right--; 
            for (int i = right; i >= left && top <= bottom; i--) {
                result[num++] = array[bottom][i]; 
            } 
            bottom--; 
            for (int i = bottom; i >= top && left <= right; i--) {
                result[num++] = array[i][left]; 
            } 
            left++; 
        } 
        return result; 
    }
}; 