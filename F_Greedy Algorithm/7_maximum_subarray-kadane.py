
# 8
# -2 -2 4 -1 -2 1 5 -3

# output -> 7

def MaxSum(a):
    MaxSum = int('-inf')
    currSum = 0

    for val in a:
        currSum += val
        MaxSum = max(MaxSum, currSum)
        if currSum < 0:
            currSum = 0

    return MaxSum

# Input
n = int(input())
a = list(map(int, input().split()))

# Calculate the maximum sum
result = MaxSum(a)
print(result)
