#!/bin/env python3

import sys
import requests
import json
import math

print("Currency converter with Exchangerate.Host API\n")

if len(sys.argv) == 1:
	amount = input("Amount: ")
	curfrom = input("Currency from: ")
	curto = input("Currency to: ")
	crypto = input("Crytocurrency? (yes/no)" )
	#sys.exit(1)
	#'''Supply amount in first argument, 
	#currency from in second argument, and 
	#currency to in third argument.
	#Usage: currency.py 10 EUR USD''')
elif len(sys.argv) > 1 and sys.argv[1] == "crypto" or sys.argv[1] == "CRYPTO":
	print("Convert crypto currencies")
	amount = input("Amount: ")
	curfrom = input("Currency from: ")
	curto = input("Currency to: ")
	crypto = True
else:
	amount = sys.argv[1]
	curfrom = sys.argv[2]
	curto = sys.argv[3]
	if len(sys.argv) > 4:
		crypto = sys.argv[4]

url = f"https://api.exchangerate.host/convert?amount={amount}&from={curfrom}&to={curto}"

if 'crypto' in globals():
	if crypto == "yes" or crypto == True or crypto == "CRYPTO" or crypto == "crypto":
		url += "&source=crypto"

try:
	request = requests.get(url)
	response = json.loads(request.text)
	result = f"{amount} {curfrom} equals {response['result']} {curto}"
except:
	print("Either currency supplied is not supported or other error")
	print("Api call: ", url)

print(result)
