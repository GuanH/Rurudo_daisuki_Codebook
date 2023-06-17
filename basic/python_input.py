a = list(map(int,input().split()))

# 開讀檔
import sys, os.path
if(os.path.exists('input_file.txt')):
    sys.stdin = open("input_file.txt","r")
    sys.stdout = open("output_file.txt","w")