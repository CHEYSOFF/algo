import random
import subprocess

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
co=0
ti=0
koltes=1000
for i in range(0,koltes):

    n=10
    inn=open("test.txt", 'w')
    a=str(n)+"\n"
    inn.write(a)
    for i in range(n):
        inn.write(str(random.randint(-2000000000, 2000000000))+" ")
    inn.write("\n")
    inn.close()
    subprocess.run([sort_name + '.exe', '-o', sort_name + '.o'])
    inn=open("result.txt", 'r')
    su=inn.readline()
    ss = inn.readline()
    st = inn.readline()
    inn.close()
    unsorted=su[3:-1].split()
    b=su[3:-1].split()
    unsorted=sorted(list(map(int,unsorted)))
    sor=list(map(int,ss[4:-1].split()))
    if(sor==unsorted):
        co+=1
        ti += float(st[5:-1])
print("Correct: ",co," / ",koltes,"\nAverage time:","%.25f" %(ti/koltes) )



