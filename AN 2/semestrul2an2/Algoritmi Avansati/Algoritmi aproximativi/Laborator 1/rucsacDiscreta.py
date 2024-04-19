n, c = [int(x) for x in input().split()]

valori = [0] + [int(x) for x in input().split()]
greutati = [0] + [int(x) for x in input().split()]


dp = [[int(0) for j in range(c + 1)] for _ in range (n + 1)]
mx = 0

for i in range(1, n + 1):
    for j in range(1, c + 1):
        if greutati[i] <= j:
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - greutati[i]] + valori[i])
        else:
            dp[i][j] = dp[i - 1][j]
        mx = max(mx, dp[i][j])

print(mx)