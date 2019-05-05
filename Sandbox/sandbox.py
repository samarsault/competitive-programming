inp = open('notlast.in', 'r')
op = open('notlast.out', 'w')

n = int(inp.readline())
mp = { };

for x in range(0, n):
    m = inp.readline().split(' ')
    name = m[0]
    amount = int(m[1])
    if mp.has_key(name):
        mp[name] = max(amount, mp[name])
    else:
        mp[name] = amount

small = ssmall = 1e9
smkey = ans = ''

for key in mp:
    if mp[key] < small:
        small = mp[key]
        smkey = key

for key in mp:
    if key == smkey:
        continue
    if mp[key] >= small and mp[key] < ssmall:
        ssmall = mp[key]
        ans = key

op.write(ans)
