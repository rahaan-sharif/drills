#getting random verses of iranian poems from ganjoor.net:
import requests
import json

url="http://c.ganjoor.net/beyt-json.php"
response=requests.get(url)

file=open("poem_output.txt", "w")
middle_stage=[response.json()['m1'], response.json()['m2'], response.json()['poet']]
out=["«", middle_stage[0], "     ", middle_stage[1], "»", "\n", middle_stage[2]]
file.write("".join(out))
file.close()
