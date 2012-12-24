test1 = """3
7 4
2 4 6
8 5 9 3"""

test2 = """75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23"""

test3 = """1
0 1
1 1 0
1 1 0 0"""

def main():
        data2 = atot(test2)
        print gsum(data2)
        print gsum(atot(test3))
        print gsum(atot(test1))
        '''for n in data2:
                print " " * (15-len(n)),
                for o in n:
                        print o / 50,
                print " " * (15-len(n)),
                print "  " * (15-len(n)),
                for o in n:
                        if o < 10:
                                print "",
                        print o, "",
                print ""'''

def atot(a):
        """Converts a space delimited string to a 2d array (triangle).

        """
        output = []
        i = 0
        j = 0
        for n in re.split("\n| ", a):
                if j == i:
                        j = 0
                        i += 1
                        output.append([])
                output[i-1].append(int(n))
                j += 1
        return output

def gsum(data):
        """Computes the greatest possible sum of one traversal of a triangle.

        """
        col_num = len(data)
        largest = 0
        for i in range(0, col_num):
                current = 0
                l = 0
                for j in range(col_num, 0, -1):
                        print "i:", i, "j:", j, "l:", l, "D:",
                        if (j != i-l) and (i-l == 0 or data[j-1][i-l] > data[j-1][i-l-1]):
                                current += data[j-1][i-l]
                                print data[j-1][i-l]
                        else:
                                current += data[j-1][i-l-1]
                                print data[j-1][i-l-1]
                                l += 1
                print "Current:", current
                if current > largest:
                        largest = current
        return largest

if __name__=="__main__":
        import re
        from math import *
        main()
