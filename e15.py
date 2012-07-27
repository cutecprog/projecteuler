def solution(x):
        if x == 0:
                return 1
        return solution(x-1) * (4 * (x-1) + 2)/x
        
for i in range(0,21):
        print "%i: %i" % (i, solution(i))
