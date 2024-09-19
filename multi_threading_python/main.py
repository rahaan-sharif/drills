#in this program, after finshing th_1 and th_2 th_3 starts:
from threading import Thread
import time

def func1():
          time.sleep(3)
          print("func1")
def func2():
          time.sleep(2)
          print("func2")
def func3():
          time.sleep(1)
          print("func3")
          
th_1=Thread(target=func1)
th_2=Thread(target=func2)
th_3=Thread(target=func3)

th_1.start()
th_2.start()

th_1.join()
th_2.join()

th_3.start()
th_3.join()
