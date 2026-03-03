import heapq as hq

T = int(input())
results = []

for _ in range(0, T):
    N, M = map(int, input().split())

    cases = list(
        map(
            lambda idx_data: (int(idx_data[1]) * -1, idx_data[0]),
            enumerate(input().split()),
        )
    )
    hq.heapify(cases)

    count = 0
    while True:
        x, i = hq.heappop(cases)
        count += 1
        if i == M:
            break
    results.append(count)

print(results)
