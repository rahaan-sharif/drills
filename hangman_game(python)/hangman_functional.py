#funcitonal form of hangman game:

print("\n\nin this game, you should guess ")
print("letters of an animal name.")
print("you can guess just 6 wrong")
print("letter, then you lose.\n\n\n")

words=["cat", "lien", "fish", "ant", "rabit", "mouse"]
from random import randint
word=words[randint(0, 4)]
print("the word has %i letters" %len(word))

check=0
end=0
rg=[]
for item in word:
          rg+=[-1]
ii=0
while ii<6:
          print("\n\n",6-ii, "times ramained")
          a=input("guess a letter: ")
          for j in range(0, len(word)):
                    if rg[j]==-1 and word[j]==a:
                              rg[j]=[a]
                              check=1
                              break
                    else:
                              check=0
          if(check):
                    print("right! ")
          else:
                    print("wrong! ")
                    ii+=1
          w=[]
          for item in rg:
                    if(item!=-1):
                              w+=item
                    else:
                              w+=["-"]
         # w="".join(w)
          print("".join(w))   
          
          end=1          
          for item in rg:
                    if(item==-1):
                              end=0
          if(end):
                    print("you won! the word: ", word)
                    break
if(end==0):
          print("you lost the game!   the word: ", word)