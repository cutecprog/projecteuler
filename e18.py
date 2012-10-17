test1 = """3
7 4
2 4 6
8 5 9 3"""

def main():
        print gsum(atot(test1))

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
        S = data[0][0]
        col_num = len(data)
        l = 0 # Number of left turns        
        r = 0 # Number of right turns
        for i in range(1, col_num):
                sum_right = 0
                sum_left = 0
                for j in range(i, col_num):
                        print data[j][r], data[j][j-l]
                        sum_left += data[j][r]
                        sum_right += data[j][j-l]
                if sum_left > sum_right:
                        l += 1
                        print "L", data[i][r]
                        S += data[i][r]
                else:
                        r += 1
                        print "R", data[i][i-l]
                        S += data[i][i-l]
        return S

if __name__=="__main__":
        import re
        main()
