import os
import shutil

import getsample
import path

def initProblem(sitename,setname,probname):
    copydir=path.root()+sitename+"/"+setname+"/"+probname+"/"
    shutil.rmtree(copydir,ignore_errors=True)
    shutil.copytree(path.root()+"template/",copydir)
    if sitename=="atcoder":
        getsample.atcoder(setname,probname)