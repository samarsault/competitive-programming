import random
print '%d %d %d %d' %(1e3, 10, 0, 1e3);
a = range(0, int(1e3))
random.shuffle(a)
print ' '.join([str(x) for x in a])