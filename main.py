import sys

sys.stdin = open("input.txt", "r")
sys.stdout = open("output.txt", "w")
input = sys.stdin.readline

line = input()
a, b = line.split(" ")
print(a)
print(b)
for i in range(3):
    print(i)