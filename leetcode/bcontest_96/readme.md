# p1 最小公共值
* 暴力

# p2 使数组中所有元素相等的最小操作数 II
* 求出diff数组，检查diff[i]是否是 k 的整数倍，如果不是，直接返回 false
* 根据diff数组，检查所有正数diff的和是否等于所有负数diff的和，如果不相等，返回false
* 返回 sum(diff_正数) / k

# p3 最大子序列的分数
```
itoa(idxs.begin(), idxs.end(), 0);
sort(idxs.begin(), idxs.end(), [&](const int& a, const int &b) {
    return nums2[a] > nums[b];
});
```
* 遍历 idxs 数组， 假设当前 nums2[idx]为所选序列的最小值
* nums1[idx] 进堆， 小根堆保存最大的 k 个数
*  if (heap.size() == k) ans = max(ans, nums2 * sum(heap))

# p4 判断一个点是否可以到达
* 数学
