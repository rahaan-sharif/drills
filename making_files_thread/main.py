# in this program, we make 5 text file
# with name from 1 to 5 and inserti 
# numbers from 1 to (1000000*file name)

import threading

def str_making(counter):
          list=[]
          for item in range(counter*1000000+1):   
                    list+=[str(item)]
                    list+=["\n"]
          string="".join(list)
          return string

def file_making(counter):
          string=str_making(counter)
          s=str(counter)
          file=open(s, "w")
          file.write(string)
          file.close()


th_1=threading.Thread(target=file_making, args=(1, ))
th_2=threading.Thread(target=file_making, args=(2, ))
th_3=threading.Thread(target=file_making, args=(3, ))
th_4=threading.Thread(target=file_making, args=(4, ))
th_5=threading.Thread(target=file_making, args=(5, ))

th_1.start()
th_2.start()
th_3.start()
th_4.start()
th_5.start()
print("\n\n  ***  please wait  ***")
