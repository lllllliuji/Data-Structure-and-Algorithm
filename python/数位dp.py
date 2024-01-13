from functools import cache


def numberOfBeautifulIntegers(self, low: int, high: int, k: int) -> int:
        # MOD = 10 ** 9 + 7
        def calc(s: str) -> int:
            m = len(s)
            @cache  # 记忆化搜索
            def f(i: int, v: int, total: int, is_limit: bool, is_num: bool) -> int:
                if i == len(s):
                    return int(is_num) and total == 0 and v % k == 0  # is_num 为 True 表示得到了一个合法数字
                res = 0
                if not is_num:  # 可以跳过当前数位
                    res = f(i + 1, v, total, False, False)
                low = 0 if is_num else 1  # 如果前面没有填数字，必须从 1 开始（因为不能有前导零）
                high = int(s[i]) if is_limit else 9  # 如果前面填的数字都和 s 的一样，那么这一位至多填 s[i]（否则就超过 s 啦）
                for d in range(low, high + 1):  # 枚举要填入的数字 d
                    res += f(i + 1, (10 * v + d) % k, total + (1 if d % 2 == 0 else -1), is_limit and d == high, True)
                return res
            f.cache_clear()
            return f(0, 0, 0, True, False)
        return calc(str(high)) - calc(str(low - 1))