N = int(input())
candidates = list(map(int, input().split()))
candidates.sort()

M = int(input())
targets = map(int, input().split())

for target in targets:
    found = False

    h = 0
    t = N - 1
    m = (h + t)//2

    while True:
        if h > t:
            break
        else:
            to_compare = candidates[m]
            if target < to_compare:
                t = m - 1
                m = (h + t) // 2
            elif target > to_compare:
                h = m + 1
                m = (h + t) // 2
            else:
                found = True
                break
    
    if found:
        print(1)
    else:
        print(0)