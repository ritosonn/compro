import os
option="-std=c++14 -W -Wall -g"
rootdir=""
def cpp(cppname,outname):
    os.system("g++ "+option+" "+rootdir+cppname+" -o "+rootdir+outname)