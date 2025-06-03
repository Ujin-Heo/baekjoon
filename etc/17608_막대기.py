import sys

news = []
while True:
    try:
        news.append(int(sys.stdin.readline()))
    except:
        break
print(news)

sticks = []
for new in news:
    if len(sticks) == 0:
        sticks.append(new)
    else:
        for stick in sticks:
            if new >= stick:
                sticks.pop(0)
                if len(sticks) == 0:
                    sticks.append(new)
                    break
            else:
                sticks.insert(0, new)
                break
    print(sticks, "\n")

print(len(sticks))
print(sticks)