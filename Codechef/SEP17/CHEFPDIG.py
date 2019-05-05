
# m = { }
# for x in range(0, 10):
    # m[x] = [ ]

# for x in range(ord('A'), ord('Z') + 1):
    # nums = [int(j) for j in str(x)]
    # for n in nums:
        # m[n].append(chr(x))

# print m

def solve(s):
    exists = {}
    for x in range(0, 10):
        exists[x] = 0

    for n in s:
        exists[int(n)] += 1

    ans = ''
    for x in range(ord('A'), ord('Z') + 1):
        nums = [int(j) for j in str(x)]
        if (nums[0] == nums[1]) :
            if exists[nums[0]] >= 2:
                ans += chr(x)
        else:
            if exists[nums[0]] and exists[nums[1]]:
                ans += chr(x)
    print ans

if __name__ == "__main__":
    t = int(raw_input())
    for x in range(0, t):
        solve(raw_input())
