import time
import os
import subprocess
import filecmp

import getsample
import execute
import build
import path

def prejudge(sitename,setname,probname):
    probdir=path.root()+sitename+"/"+setname+"/"+probname+"/"
    if not os.path.exists(probdir+"sample/"):
        if sitename=="atcoder":
            getsample.atcoder()
    build.cpp(probdir+"solve.cpp",probdir+"build/solve.exe")
    sampleNo = 1
    (ac,wa,tle)=(0,0,0)
    while sampleNo==1 or os.path.exists(probdir+"sample/in/"+str(sampleNo)+".txt"):
        try:
            t=execute.exe(probdir+"/build/solve.exe",probdir+"sample/in/"+str(sampleNo)+".txt",probdir+"build/"+str(sampleNo)+".txt")
        except:
            print("sample "+str(sampleNo)+": [TLE]")
            tle+=1
        if filecmp.cmp(probdir+"sample/out/"+str(sampleNo)+".txt",probdir+"build/"+str(sampleNo)+".txt"):
            print("sample "+str(sampleNo)+": [AC] "+str(t)+"msec")
            ac+=1
        else:
            print("sample "+str(sampleNo)+": [WA] "+str(t)+"msec")
            wa+=1
        sampleNo+=1
    sampleNo-=1
    print(str(sampleNo)+"judges complete.")
    print(str(ac)+"AC,"+str(wa)+"WA,"+str(tle)+"TLE")
    return ac>0 and ac==sampleNo

def usemylib(programname):
    with open(path.root()+programname,encoding="utf-8") as fp:
        l=fp.readline()
        while l:
            if l.find('"lib/')>=0:
                return True
            l=fp.readline()
        return False

def judgetosubmit(sitename,setname,probname):
    return prejudge(sitename,setname,probname) and not usemylib(sitename+"/"+setname+"/"+probname+"/solve.cpp")