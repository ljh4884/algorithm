
temp = input().split(" ")

n = int(temp[0])
m = float(temp[1]) / 100


total = []

sum_water = 0
sum_matter = 0
sum_total = 0

for _ in range(n):
    temp = input().split(" ")

    d = float(temp[0])
    t = float(temp[1])

    temp = t * d / 100

    total.append((d, t, temp, t-temp))

    sum_water += t-temp
    sum_matter += temp
    sum_total += t

total = sorted(total)

cur_value = sum_matter / sum_total
check = False
if cur_value == m:
    print(sum_total)
elif cur_value < m:
    i = 0
    for i in range(n):
        matter = sum_matter - total[i][2]
        plus = sum_total - total[i][1]
        if plus == 0:
            check = True
            break
        if matter / plus >= m:
            break
        sum_matter -= total[i][2]
        sum_total -= total[i][1]
    if check:
        print(0.0)
    else:
        x = (m * sum_total - sum_matter) / (m * total[i][1] - total[i][2])
        ans = ans = sum_total - x * total[i][1]
        print(ans)
else:
    i = n-1
    for i in range(n-1, -1, -1):
        matter = sum_matter - total[i][2]
        plus = sum_total - total[i][1]
        if plus == 0:
            check = True
            break
        if matter / plus <= m:
            break
        sum_matter -= total[i][2]
        sum_total -= total[i][1]
    if check:
        print(0.0)
    else:
        x = (m * sum_total - sum_matter) / (m * total[i][1] - total[i][2])
        ans = sum_total - x * total[i][1]
        print(ans)



