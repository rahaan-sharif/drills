class questioner():
          def __init__(self):
                    self.__animal=input("**p1:    wich animal? ")
          def letters(self):
                    return len(self.__animal)
          def word(self):
                    return self.__animal
          def check(self,list, letter):
                    c=0
                    for i in range(len(self.__animal)):
                              if (self.__animal[i]==letter and list[i]==-1):
                                        list[i]=letter
                                        c=1
                                        break
                    return [list, c]
                              
                    
                    

class responser():
          def __init__(self, ob):
                    self.ob=ob
                    print("the animal has %i letters\n\n" %ob.letters())
          def game(self):
                    g_list=[]
                    for item in range(0, self.ob.letters()):
                              g_list+=[-1]
                    i=0
                    while i<6:
                              print("**p2:    times remains =", 6-i)
                              a=input("guess: ")
                              checked_list=self.ob.check(g_list, a)
                              g_list=checked_list[0]
                              tmp=[]
                              for item in g_list:
                                        if item==-1:
                                                  tmp+=['-']
                                        else:
                                                  tmp+=[str(item)]
                              print("".join(tmp), "\n\n")
                              if not(-1 in g_list):
                                        print("p2 won!  the word: ")
                                        print("\tword: ", "".join(g_list))
                                        return
                              if(not checked_list[1]):
                                        i+=1
                    print("p1 won!")
                    print("\t", self.ob.word())
          
          
          
          
          
          
          
########################
print("\n\n\nplayer1 will give the animal name")
print("and player2 will guess the animal.")
print("player2 can guess only 6 wrong letter.\n\n\n")
ob1=questioner()
ob2=responser(ob1)
ob2.game()