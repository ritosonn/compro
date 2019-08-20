import os
import time
import subprocess
import pickle
import filecmp
import re
import json
import requests
import shutil
import sys
from bs4 import BeautifulSoup

compile_option = "-std=c++14 -W -Wall -g"
workspace_directory = "/home/ritosonn/compro/"
timeout_sec = 5

def build_cpp(fullpath_noext):
    compile_command = "g++ " + compile_option + " " + fullpath_noext + ".cpp -o " + fullpath_noext + ".out"
    print("build task: " + compile_command)
    os.system(compile_command)

def execute_program(programname,infilename,outfilename):
    #print("program: "+programname)
    #print("in: "+infilename)
    #print("out: "+outfilename)
    with open(infilename,encoding="utf-8",mode="r") as infile:
        with open(outfilename,encoding="utf-8",mode="w") as outfile:
            start = time.perf_counter()
            subprocess.run(programname,stdin=infile,stdout=outfile,check=True,timeout=timeout_sec)
            return int(1000*(time.perf_counter() - start))

def judge_one_sample(setname,probname,sampleNo):
    in_fullpath = workspace_directory + ".in/" + sampleNo + ".txt"
    out_fullpath = workspace_directory + ".out/" + sampleNo + ".txt"
    tmp_fullpath = workspace_directory + ".tmp/" + sampleNo + ".txt"
    program_fullpath = workspace_directory + setname + "/" + probname + ".out"
    try:
        t=execute_program(program_fullpath, in_fullpath, tmp_fullpath)
    except:
        return "TLE",-1
    if filecmp.cmp(tmp_fullpath,out_fullpath):
        return "AC",t
    else:
        return "WA",t

def judge(setname,probname):
    build_cpp(setname + "/" + probname)
    sampleNo = 1
    (ac,wa,tle)=(0,0,0)
    while sampleNo==1 or os.path.exists(workspace_directory+".in/"+str(sampleNo)+".txt"):
        res, t = judge_one_sample(setname,probname,str(sampleNo))
        #print(res)
        #print(t)
        if res=="AC":
            print("sample "+str(sampleNo)+": [AC] "+str(t)+"msec")
            ac+=1
        elif res=="WA":
            print("sample "+str(sampleNo)+": [WA] "+str(t)+"msec")
            wa+=1
        else:
            print("sample "+str(sampleNo)+": [TLE]")
            tle+=1
        sampleNo+=1
    sampleNo-=1
    print(str(sampleNo)+"judges complete.")
    print(str(ac)+"AC,"+str(wa)+"WA,"+str(tle)+"TLE")
    return ac>0 and ac==sampleNo

def reset_tmpfile():
    for foldername in {".in",".out",".tmp"}:
        shutil.rmtree(workspace_directory + foldername)
        os.mkdir(workspace_directory + foldername)
        with open(workspace_directory + foldername + "/.gitkeep","w"):
            pass


def clear_all(setname):
    copydir=workspace_directory+setname+"/"
    shutil.rmtree(copydir,ignore_errors=True)
    shutil.copytree(workspace_directory+".template/",copydir)

# --- for atcoder ---

def login_atcoder():
    loginpage="https://atcoder.jp/login"
    with open(workspace_directory+".secret/atcoder_login.json",encoding="utf-8",mode="r") as jsonfile:
        account = json.load(jsonfile)
    s = requests.session()
    csrftoken = BeautifulSoup(s.get(loginpage).text,"html.parser").find_all("input")[0]["value"]
    logindata={
        "csrf_token":csrftoken,
        "password":account["password"],
        "username":account["username"]
    }
    s.post(loginpage,logindata)
    with open(workspace_directory+".secret/session.pickle","wb") as fp:
        pickle.dump((s,csrftoken),fp)
    print("login complete.")

def taskname_atcoder(setname,probname):
    return setname.replace('-','_')+"_"+probname
def website_atcoder(setname,probname):
    return "https://atcoder.jp/contests/"+setname+"/tasks/"+taskname_atcoder(setname,probname)

def getsample_atcoder(setname,probname):
    reset_tmpfile()
    if not os.path.exists(workspace_directory+".secret/session.pickle"):
        login_atcoder()
    with open(workspace_directory+".secret/session.pickle","rb") as fp:
        (s,_)=pickle.load(fp)
    samples = BeautifulSoup(s.get(website_atcoder(setname,probname)).content,"html.parser").find_all("pre")
    if len(samples)%2==0:
        samples = samples[0:len(samples)//2] #delete english version
    isinput=True
    sampleNo=1
    startNo=1 if len(samples)%2==1 else 2 #input sample or IO sample
    for sample in samples[startNo:]:
        samplefilename=workspace_directory+(".in" if isinput else ".out")+"/"+str(sampleNo)+".txt"
        with open(samplefilename,encoding="utf-8",mode="w") as txtfile:
            txtfile.write(re.sub("[\r\n]{2,}", "\n", sample.string))
        isinput = not isinput
        if isinput:
            sampleNo += 1
    print("getsample complete.")

def submit_atcoder(setname,probname):
    if judge(setname,probname):
        with open(workspace_directory+".secret/session.pickle","rb") as fp:
            (s,csrftoken)=pickle.load(fp)
        with open(workspace_directory+setname+"/"+probname+".cpp",encoding="utf-8") as prog:
            source = prog.read()
        data = {
            "csrf_token": csrftoken,
            "data.LanguageId": "3003", # c++14(gcc 5.4.1)
            "data.TaskScreenName": taskname_atcoder(setname,probname),
            "sourceCode": source
        }
        #print(data)
        r=s.post("https://atcoder.jp/contests/"+setname+"/submit",data)
        print(r.status_code)
        print("submit complete.")
    else:
        print("submit interrupted.")

def usage():
    print("usage: python3 main.py [init|judge|submit] [dirname] [a-z]")
    print("       python3 main.py clear_all < [foldername]")

if __name__=="__main__":
    if len(sys.argv)==4:
        if sys.argv[1]=="init":
            getsample_atcoder(sys.argv[2],sys.argv[3])
        elif sys.argv[1]=="judge":
            judge(sys.argv[2],sys.argv[3])
        elif sys.argv[1]=="submit":
            submit_atcoder(sys.argv[2],sys.argv[3])
        else:
            usage()
    elif len(sys.argv)==2 and sys.argv[1]=="clearall":
        clear_all(input())
    else:
        usage()
