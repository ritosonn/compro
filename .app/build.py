import os
option="-std=c++14 -W -Wall -g"
rootdir=""
def cpp(cppname,outname):
    com="g++ "+option+" "+rootdir+cppname+" -o "+rootdir+outname
    print("build task: "+com)
    os.system(com)
    