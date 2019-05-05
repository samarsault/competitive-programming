#
# Finds the testcase where
# you are getting WA
#
import sys
from random import randrange
import subprocess

def run(cmd, iDat):
	process=subprocess.Popen([cmd],
			stdin=subprocess.PIPE,
			stdout=subprocess.PIPE,
			stderr=subprocess.PIPE)
	inputdata=iDat
	stdoutdata,stderrdata=process.communicate(input=inputdata)
	return stdoutdata

f = open('tc.log', 'w')
def log(inp, o1, o2):
    s = str(datetime.datetime.now())
    s += '\nInput: %s\nProg1: %s\nProg2 %s\n' %(inp,o1,o2)
    f.write(s)

if len(sys.argv) < 3:
	print 'Not enough args'
else:
	while True:
		l = randrange(3, 10)
		a=[]
		for x in range(0, l):
			a.append(randrange(20))
		s = set(a)
		inp = str( len(s )) + ' ' + ' '.join([str(x) for x in s])

		o1 = run(sys.argv[1], inp)
		o2 = run(sys.argv[2], inp)

		print 'Print prog1: %sPrint prog2: %s' %(o1,o2)
		if o1 != o2:
			print 'Found error'
			print 'Data\n%s' %inp 
			break
