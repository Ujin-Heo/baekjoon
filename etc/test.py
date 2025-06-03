a_s = [1,2,3,4,5,6]
    
for a in a_s:
    if a %2 == 1:
        a_s.pop(0)
    else:
        print(a)

print(a_s)