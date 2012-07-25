#!/usr/bin/python3

def main():
        print("Euler Problem 15\n", end="")
        print(factorial(4))

def factorial(x):
        product = 1
        while x != 0:
                product = product * x
                x = x - 1
        return product

if __name__=="__main__":
        main()
        
