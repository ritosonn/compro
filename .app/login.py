import json
import requests
from bs4 import BeautifulSoup
import pickle

import path

def atcoder():
    loginpage="https://atcoder.jp/login"
    with open(path.root()+".secret/atcoder_login.json",encoding="utf-8",mode="r") as jsonfile:
        account = json.load(jsonfile)
    s = requests.session()
    csrftoken = BeautifulSoup(s.get(loginpage).text,"html.parser").find_all("input")[0]["value"]
    logindata={
        "csrf_token":csrftoken,
        "password":account["password"],
        "username":account["username"]
    }
    r = s.post(loginpage,logindata)
    with open(path.root()+".secret/session.pickle","wb") as fp:
        pickle.dump((s,csrftoken),fp)
    print("login complete.")
    