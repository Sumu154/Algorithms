def isFound(a, k):
    n = len(a)
    l,r = 0,n-1

    while l<=r:
        mid = (l+r) // 2
        if a[mid]==k:
            return mid+1
        elif a[mid]>k:
            r = mid-1
        else:
            l = mid+1

    return -1

if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    k = int(input())
    pos = isFound(a, k)
    if pos == -1:
        print("NO")
    else:
        print("YES", pos)
