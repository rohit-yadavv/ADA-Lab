def longestCommonSubsequence(s1, s2, m, n, memo):
    if m == 0 or n == 0:
        return 0

    if memo[m][n] != -1:
        return memo[m][n]

    if s1[m - 1] == s2[n - 1]:
        memo[m][n] = 1 + longestCommonSubsequence(s1, s2, m - 1, n - 1, memo)
    else:
        memo[m][n] = max(
            longestCommonSubsequence(s1, s2, m - 1, n, memo),
            longestCommonSubsequence(s1, s2, m, n - 1, memo),
        )

    return memo[m][n]


if __name__ == "__main__":
    s1 = "ABCBDAB"
    s2 = "BDCABB"
    m = len(s1)
    n = len(s2)
    memo = [[-1 for _ in range(n + 1)] for _ in range(m + 1)]

    result = longestCommonSubsequence(s1, s2, m, n, memo)
    print("Length of LCS:", result)
