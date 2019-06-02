import time
import subprocess
rootdir=""
timeoutsec=2
# return execute time[msec] (accuracy ≈ 10msec)
# if timeout, throw TimeoutExpired
def exe(programname,infilename,outfilename):
    with open(rootdir+infilename,encoding="utf-8",mode="r") as infile:
        with open(rootdir+outfilename,encoding="utf-8",mode="w") as outfile:
            start = time.perf_counter()
            subprocess.run(rootdir+programname,stdin=infile,stdout=outfile,check=True,timeout=timeoutsec)
            return int(1000*(time.perf_counter() - start))