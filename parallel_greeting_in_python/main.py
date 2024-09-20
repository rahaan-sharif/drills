#in this program, we use threads to say "hello by"
#in the same order, in two times:

from threading import Thread, Lock


class HELLO():
    def __init__(self):
        pass
        self.lh=Lock()
        self.lb=Lock()
        self.lb.acquire()

    def h(self):
        self.lh.acquire()
        print('hello', end=' ')
        self.lb.release()
            
    def b(self):
        self.lb.acquire()
        print('bye')
        self.lh.release()

object = HELLO()


th_1 = Thread(target=object.b)
th_2 = Thread(target=object.b)
th_3 = Thread(target=object.h)
th_4 = Thread(target=object.h)

th_2.start()
th_4.start()
th_1.start()
th_3.start()
