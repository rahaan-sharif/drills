#in this program, we get some prices for oil
#then use regex to print price
import re

prices=[]
for i in range(4):
    print("\n*****")
    barrel=int(input("\tbarrel: "))
    price=int(input("\tprice: "))
    prices+=["price of oil is %i$ for %i barrels" %(price, barrel)]
print("\n\n")

price_barrel=[]
for item in prices:
    tmp=re.findall(r"price of oil is (\d+)\$ for (\d+) barrels" ,item )
    price_barrel+=tmp

print("price(dollar per barrel)")
for (item1, item2) in price_barrel:
    print("%f" %(float(item1)/float(item2)))
