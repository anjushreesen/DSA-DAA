def knapSack(W, wt, val, n):
    if n == 0 or W == 0:
        return 0
    if (wt[n-1] > W):
        return knapSack(W, wt, val, n-1)
    else:
        return max(
            val[n-1] + knapSack(
                W-wt[n-1], wt, val, n-1),
            knapSack(W, wt, val, n-1))

n = int(input())
W = int(input())
wt = list(map(int, input().split()))
val = list(map(int, input().split()))

print (knapSack(W, wt, val, n))