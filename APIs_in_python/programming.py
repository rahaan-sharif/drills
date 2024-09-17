from abc import ABC, abstractmethod
import json
import requests


class parent(ABC):
          @abstractmethod
          def api_call():
                    pass

class province(parent):
          def __init__(self):
                    self.__URL1=["http://iran-locations-api.ir/api/v1/fa/cities?state="]
                    self.__URL1+=input("tell me iranian province(persian name): ")
          def api_call(self):
                    response1=requests.get("".join(self.__URL1))
                    file=open("province.txt", "w")
                    
                    v=response1.json()[0]["cities"]
                    final=[]
                    out=[]
                    for item in v:
                              out+=["شهر: "]
                              out+=[item["name"]]
                              out+=["\tطول جغرافیایی: "]
                              out+=[item["latitude"]]
                              out+=["\tعرض جغرافیایی: "]
                              out+=[item["longitude"]]
                              out+=["\tid: "]
                              out+=[str(item["id"])]
                              final+=out
                              final+=["\n"]
                              out=[]
                    
                    file.write("".join(final))          
                    
                    file.close()

class is_holiday(parent):
          def __init__(self):
                    self.__URL2=["https://holidayapi.ir/jalali/"]
                    self.__date=[input("tell me the time: ")]
                    self.__URL2+=self.__date
          def api_call(self):
                    response=requests.get("".join(self.__URL2))
                    file=open("holiday.txt", "w")
                    
                    v1=response.json()
                    final=[]
                    final+=["تاریخ: "]
                    final+=self.__date
                    final+=["\nتعطیل: "]
                    final+=[str(v1['is_holiday'])]
                    final+=["\n"]
                    final+=["\nرویداد ها:\n"]
                    for item in v1['events']:
                              final+=item["description"]
                              final+=" ("
                              final+=item['additional_description']
                              final+=")\n"
                    final="".join(final)
                    file.write(final)
                    
                    file.close()

class random_verse(parent):
          def api_call(self):
                    url="http://c.ganjoor.net/beyt-json.php"
                    response=requests.get(url)

                    file=open("random_verse.txt", "w")
                    middle_stage=[response.json()['m1'], response.json()['m2'], response.json()['poet']]
                    out=["«", middle_stage[0], "     ", middle_stage[1], "»", "\n", middle_stage[2]]
                    file.write("".join(out))
                    file.close()
          
def pr():
          ob1=province()
          ob1.api_call()

def ho():
          ob2=is_holiday()
          ob2.api_call()

def ve():
          ob3=random_verse()
          ob3.api_call()

while(1):                    
          print("\n\nchoose your operation:")
          print("(all outputs will store in a file)")
          print("    1- getting cities of a specified province")
          print("    2- getting events of a specified day")
          print("    3- getting a random persian verse")
          print("    0- exit")

          in_value=int(input("\noperation: "))
          if in_value==1:
                    pr()
          elif in_value==2:
                    ho()
          elif in_value==3:
                    ve()
          elif in_value==0:
                    break
