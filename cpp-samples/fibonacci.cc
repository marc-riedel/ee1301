p = 1
q = 1
print(p, end=", ")
for i in range(1, 11):
    print(p, end="")
    s = p
    t = q
    q = p
    p = s + t
    if i < 10:
        print(", ", end="")
print()
