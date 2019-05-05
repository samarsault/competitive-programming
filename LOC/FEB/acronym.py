# Verdict: AC
print len([ word for word in raw_input().split(' ') if len(word) > 1 and word == word.upper()])