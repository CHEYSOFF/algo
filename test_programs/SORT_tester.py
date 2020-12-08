import random
import subprocess

n=1000
inn=open("test.txt", 'w')
inn.write("str(n)+\n")
for i in range(n):
    inn.write(str(random.randint(-2000000000, 2000000000))+" ")
inn.write("\n")
inn.close()
print("Enter 1 if you want to test shellsort\nEnter 2 if you want to test quicksort\nEnter 3 if you want to test heapsort\nEnter 4 if you want to test introsort\n")
w1 = int(input())
sort_name=""
if (w1==1):
    sort_name="shell_sort"
elif(w1==2):
    sort_name="quick_sort"
elif(w1==3):
    sort_name="heap_sort"
elif(w1==4):
    sort_name="intro_sort"

subprocess.run([sort_name + '.exe', '-o', sort_name + '.o'])
inn=open("result.txt", 'r')
su=inn.readline()
unsorted=su[3:-1].split()
b=su[3:-1].split()
co=0
unsorted=sorted(list(map(int,unsorted)))
ss=inn.readline()
sor=list(map(int,ss[4:-1].split()))
if(sor==unsorted):
    print("Correct\n")
else:
    print("Incorrect\n")
st=inn.readline()
print(st+"\n")
