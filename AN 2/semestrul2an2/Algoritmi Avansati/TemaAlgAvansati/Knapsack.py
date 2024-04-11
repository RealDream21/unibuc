import random
import matplotlib as mp

def opt(testcase):
    dp = [[0 for _ in range(1001)] for i in range(1001)]
    mx = 0   
    n, k = testcase[0:2]
    s = [0] + testcase[2:]
    for i in range(1, n + 1):
        for j in range(1, k + 1):
            if s[i] <= j:
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - s[i]] + s[i])
            else:
                dp[i][j] = dp[i - 1] [j]
            mx = max(mx, dp[i][j])
    return mx

def alg(testcase):
    n, k = testcase[0:2]
    s = [0] + testcase[2:]
    mx = max(s)
    s.remove(mx)
    for elem in s:
        if elem + mx <= k:
            mx += elem
    return mx

def algPdf(testcase):
    n, k = testcase[0:2]
    total = 0
    s = [0] + testcase[2:]
    for x in s:
        if x + total <= k:
            total += x
        elif (total < x):
            total = x
    return total 

def generateTestcase(param1 = 10, param2 = 10):
    k = int(random.uniform(param1, 2 * param1))
    n = int(random.uniform(0, param2))
    testcase = [n] + [k] + [int(random.uniform(1, k)) for _ in range(n)]
    return testcase

cnt = 0
for _ in range(1):
    #teste = generateTestcase(10, 100)
    teste = [5, 3, 1, 1, 9, 1, 1]
    val1 = opt(teste)
    val2 = alg(teste)
    val3 = algPdf(teste)
    print(val1)
    print(val2)
    print(val3)
    if val1 != 0:
        raport = val3/val1
        if raport < 0.5:
            cnt += 1
            print(teste)
            break


print(cnt)

