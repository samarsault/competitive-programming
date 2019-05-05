def solve(bl, bw, l2, w2):
	if (l2 > bl and w2 < bw):
		return (bl * bw) + ((l2 - bl) * w2);
	elif (l2 < bl and w2 > bw):
		return (bl * bw) + ((w2 - bw) * l2);
	else:
		return bl * bw;
 
i = 0
t = int(raw_input())
while i < t:
	s = raw_input().split(' ')
	l1 = int(s[0])
	w1 = int(s[1])
	l2 = int(s[2])
	w2 = int(s[3])
	ar1 = l1 * w1
	ar2 = l2 * w2
	mx = ar1 + ar2
	mn = ar1
	if ar1 > ar2:
		mn =solve(l1, w1, l2, w2)
	else:
		mn =solve(l2, w2, l1, w1)

	print '%s %s' %(mn, mx)
	i+=1