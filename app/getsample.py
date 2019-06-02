import os
import pickle
import re
from bs4 import BeautifulSoup

import login
import path

def taskname_atcoder(setname,probname):
    return setname.replace('-','_')+"_"+probname

def atcoder(setname,probname):
    if not os.path.exists(path.root()+".secret/session.pickle"):
        login.atcoder()
    with open(path.root()+".secret/session.pickle","rb") as fp:
        (s,csrftoken)=pickle.load(fp)
    website="https://atcoder.jp/contests/"+setname+"/tasks/"+taskname_atcoder(setname,probname)
    samples = BeautifulSoup(s.get(website).content,"html.parser").find_all("pre")
    if len(samples)%2==0:
        samples = samples[0:len(samples)//2] #delete english version
    # print(samples)
    isinput=True
    sampleNo=1
    startNo=1 if len(samples)%2==1 else 2 #input sample or IO sample
    for sample in samples[startNo:]:
        samplefilename=path.root()+"/atcoder/"+setname+"/"+probname+"/sample/"+("in" if isinput else "out")+"/"+str(sampleNo)+".txt"
        with open(samplefilename,encoding="utf-8",mode="w") as txtfile:
            txtfile.write(re.sub("[\r\n]{2,}", "\n", sample.string))
        isinput = not isinput
        if isinput:
            sampleNo += 1
    print("getsample complete.")