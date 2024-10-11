#in this progrem, we save title of products
#in https://divar.ir/s/tehran
# with tag="نو" in data.txt    .
#I can't check the process, because every time 
#I open the web page, new resaults are shown.

import requests
from bs4 import BeautifulSoup

file=open("/tmp/data.txt","w")

response=requests.get("https://divar.ir/s/tehran")
resault1=BeautifulSoup(response.text, "html.parser")
T1={"class":"kt-post-card__action"}
T2={"class":"kt-post-card__description"}
resault2=resault1.find_all("a", attrs=T1)
for item in resault2:
          item2 = item.find('div', class_='kt-post-card__description', string="نو")
          if(item2):
                    file.write(item.find('h2', class_='kt-post-card__title').text)
                    file.write("\n\n")
file.close()
