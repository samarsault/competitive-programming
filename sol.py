n=int(raw_input())
s=raw_input()
a = [int(x) for x in s.split(' ')]
a=sorted(a)
print ' '.join(str(x) for x in a)
