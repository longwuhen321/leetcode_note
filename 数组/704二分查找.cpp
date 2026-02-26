#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/binary-search/description/

// 版本一
class Solution {
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
        while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
            int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // target 在左区间，所以[left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，所以[middle + 1, right]
            } else { // nums[middle] == target
                return middle; // 数组中找到目标值，直接返回下标
            }
        }
        // 未找到目标值
        return -1;
    }
};

int main()
{
    system("chcp 65001");   // 设置控制台编码为UTF-8
    Solution solution;

    vector<int> nums = { 1, 3, 5, 7, 9, 11, 15 };
    int target;

    cout << "请输入要查找的数字: " << endl;
    cin >> target;

    int result = solution.search(nums, target);

    if (result != -1) {
        cout << "找到目标，下标为: " << result << endl;
    } else {
        cout << "未找到目标" << endl;
    }

    return 0;
}
