test1 = """1
2 3
4 5 6
7 8 9 10"""

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
        S = 0
        col_num = len(data)
        sum_right = 0
        sum_left = 0
        for i in range(1, col_num):
                for j in range(i, col_num):
                        sum_left += data[j][0]
                        sum_right += data[j][j]
                if sum_left > sum_right:
                        S += data[i][0]
                else:
                        S += data[i][i]
        return S

if __name__=="__main__":
        import re
        main()
