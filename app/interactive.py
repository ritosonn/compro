import sys

import init
import judge
import submit

if len(sys.argv)==3:
    l=sys.argv[2].split("\\")
    sitename=l[-3]
    setname=l[-2]
    probname=l[-1]
    print(sitename+" - "+setname+" - "+probname)
    if sys.argv[1]=="init":
        init.initProblem(sitename,setname,probname)
    elif sys.argv[1]=="judge":
        judge.prejudge(sitename,setname,probname)
    elif sys.argv[1]=="submit":
        submit.to(sitename,setname,probname)