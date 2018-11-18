<!-- GFM-TOC -->
* [算法思想](#算法思想)
    * [双指针](#双指针)
    * [排序](#排序)
        * [快速选择](#快速选择)
    * [贪心思想](#贪心思想)
    * [二分查找](#二分查找)
    * [分治](#分治)
    * [搜索](#搜索)
        * [BFS](#bfs)
        * [DFS](#dfs)
        * [Backtracking](#backtracking)
    * [动态规划](#动态规划)
        * [斐波那契数列](#斐波那契数列)
    * [数学](#数学)
        * [素数](#素数)
* [数据结构相关](#数据结构相关)
    * [链表](#链表)
    * [树](#树)
        * [递归](#递归)
    * [栈和队列](#栈和队列)
    * [哈希表](#哈希表)
    * [字符串](#字符串)
    * [数组与矩阵](#数组与矩阵)
    * [图](#图)
        * [二分图](#二分图)
    * [位运算](#位运算)
* [参考资料](#参考资料)
<!-- GFM-TOC -->


# 算法思想

## 双指针

双指针主要用于遍历数组，两个指针指向不同的元素，从而协同完成任务。

**有序数组的 Two Sum** 

[Leetcode ：167. Two Sum II - Input array is sorted (Easy)](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/)

```html
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
```

题目描述：在有序数组中找出两个数，使它们的和为 target。

使用双指针，一个指针指向值较小的元素，一个指针指向值较大的元素。指向较小元素的指针从头向尾遍历，指向较大元素的指针从尾向头遍历。

- 如果两个指针指向元素的和 sum == target，那么得到要求的结果；
- 如果 sum > target，移动较大的元素，使 sum 变小一些；
- 如果 sum < target，移动较小的元素，使 sum 变大一些。

```java
public int[] twoSum(int[] numbers, int target) {
    int i = 0, j = numbers.length - 1;
    while (i < j) {
        int sum = numbers[i] + numbers[j];
        if (sum == target) {
            return new int[]{i + 1, j + 1};
        } else if (sum < target) {
            i++;
        } else {
            j--;
        }
    }
    return null;
}
```
