/*
 * @lc app=leetcode.cn id=32 lang=c
 *
 * [32] 最长有效括号
 */

// @lc code=start
int longestValidParentheses(char* s) {
    int top = 0;  
    int max = 0; 
    int len = strlen(s);  
    int stack[len + 1]; 
    stack[0] = -1; 
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') { 
            stack[++top] = i; 
        } else { 
            --top; 
            if (top == -1) {
                stack[++top] = i; 
            } else {
                max = fmax(max, i - stack[top]); 
            } 
        } 
    }  
    return max;  
}
// @lc code=end

