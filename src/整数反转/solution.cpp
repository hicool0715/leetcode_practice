#pragma once
/*
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。
 

示例 1：

输入：x = 123
输出：321
示例 2：

输入：x = -123
输出：-321
示例 3：

输入：x = 120
输出：21
示例 4：

输入：x = 0
输出：0
 

提示：

-231 <= x <= 231 - 1
*/
#pragma once
#include <iostream>
#include <queue>
class Solution {
public:
int reverse(int x) {
  long long long_x = x; // 存入更大的位置；
  // 判断正负；
  bool flag = x > 0 ? true : false;
  std::queue<int> target_q{};
  // 放入队列
  while (long_x >= 10 || long_x <= -10) {
    target_q.push(long_x%10);
    long_x /= 10;
  }  
  target_q.push(long_x);
  // 出队列
  long long target_val{0};
  while (!target_q.empty()) {
    target_val = target_val*10 + target_q.front();
    target_q.pop();
  } 
  long long limit_val = 1ull << 31;
  if (flag && target_val > (limit_val - 1)) return 0;
  if ((!flag) && target_val < (limit_val * -1)) return 0;
  return target_val;
}
};

int main() {
  Solution s;
  std::cout << "result: " << s.reverse(-1111111117) << std::endl;
  return 0;
}