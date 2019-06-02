import os
import pickle
import json

import login
import judge
import getsample
import path

def atcoder(setname,probname):
    if judge.judgetosubmit("atcoder",setname,probname):
        if not os.path.exists(path.root()+".secret/session.pickle"):
            login.forAtCoder()
        with open(path.root()+".secret/session.pickle","rb") as fp:
            (s,csrftoken)=pickle.load(fp)
        with open(path.root()+"atcoder/"+setname+"/"+probname+"/solve.cpp",encoding="utf-8") as prog:
            source = prog.read()
        data = {
            "csrf_token": csrftoken,
            "data.LanguageId": "3003", # c++14(gcc 5.4.1)
            "data.TaskScreenName": getsample.taskname_atcoder(setname,probname),
            "sourceCode": source
        }
        #print(data)
        r=s.post("https://atcoder.jp/contests/"+setname+"/submit",data)
        print(r.status_code)
        print("submit complete.")
    else:
        print("submit interrupted.")

def to(sitename,setname,probname):
    if sitename=="atcoder":
        atcoder(setname,probname)