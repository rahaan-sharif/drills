numbers=dict()
numbers['۰']='0'
numbers['۱']='1'
numbers['۲']='2'
numbers['۳']='3'
numbers['۴']='4'
numbers['۵']='5'
numbers['۶']='6'
numbers['۷']='7'
numbers['۸']='8'
numbers['۹']='9'
numbers['.']='.'
numbers['.']='.'
for i in range(0,10):
    numbers[str(i)]=str(i)

check=dict()
check["."]=0

def function(a):
    sum=0
    num=[]
    count=1
    for i in range(0, len(a)):
        if (a[i] in numbers):
            num+=[numbers[a[i]]]
        else:
            new_str="".join(num)
            if(len(new_str)>0):
                if(new_str[0]=='.'):
                    num=[]
                else:
                    print("number", count, ":", new_str)
                    count+=1
                    sum+=float(new_str)
            num=[]
    print("------")
    print("sum:", sum)


file=open("/home/rahaan/Desktop/spam/python_programing/final_project.txt")
f=file.read()
f=str(f)
function(f)




file.close()
