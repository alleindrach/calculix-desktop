#!/usr/bin/env python
"""
This is a monitor for .sta and .cvg files of calculix
"""
import sys
import matplotlib.pyplot as plt
import numpy
import glob

# print sys.argv[1]
# job = sys.argv[1]
# processing command line arguments, get the
# jobname
if len(sys.argv)==1:
    print("No jobname given.")
    files=glob.glob("*.sta")
    if len(files)==1:
        print("Found", files[0])
        job=files[0][:-4]
    else:
        print("Available .sta files:")
        for f in files:
            print("  ", f)
        quit()
if len(sys.argv)>1:
    print("Jobname:",sys.argv[1])
    job = sys.argv[1]
try:
    sta=numpy.genfromtxt(job+'.sta',skip_header=2,delimiter=[6,11,7,6,14,14,14])
except:
    # before the first increment is completed, the sta-file is empty, so we
    # fake some contents to not crash later
    sta=numpy.array([[  1.   ,   1.   ,   1.   ,  0   ,   0  ,   0  ,   0  ]])
cvg=numpy.genfromtxt(job+'.cvg',skip_header=4)
if len(cvg)==0:
    # if the job is linear, cvg data is empty.
    print(job+".cvg contains no data. No plot is generated" )
    sys.exit()
# ensure 2dim array in case of single data line
if sta.ndim==1:
    sta=sta[numpy.newaxis,:]
"""
.sta
 0 STEP
 1 INC
 2 ATT
 3 ITRS
 4 TOT TIME
 5 STEP TIME
 6 INC TIME
 .cvg
 0 STEP
 1 INC
 2 ATT
 3 ITER
 4 CONT EL
 5 RESID FORCE
 6 CORR DISP
 7 RESID FLUX
 8 CORR TEMP"""
# iteration counter
iters=cvg.shape[0]  # number of iterations
it=range(iters)     # range for loop over iterations
# increment number for iteration
itinc=cvg.astype(int)[:,1]    # increment number for the iterations
itstep=cvg.astype(int)[:,0]   # step number for the iteration
itdt=numpy.empty([iters])     # time step for the iteration
itsteptime=numpy.empty([iters])  # Step time for iterations
for i in it:
    stp = itstep[i]
    inc = itinc[i]
	# ccx writes values below 1e-6 as zero,
    if (cvg[i,5]==0.0):
        cvg[i,5]=1.e-7
        
    found=0 
    for j in range(sta.shape[0]):
        if (stp==sta.astype(int)[j,0]) and (inc==sta.astype(int)[j,1]):
            itdt[i]=sta[j,6]
            itsteptime[i]=sta[j,5]
            print (i, stp, inc, j, itdt[i],itsteptime[i],cvg[i,5])
            istamax=i
            icvgmax=i
            found=1
    if (not found==1):
        print(i, stp, inc, cvg[i,4], cvg[i,5])
        icvgmax=i
## Plot force residuals, disp correction and time step
plt.subplot(2,1,1)
plt.title('sta and cvg data of job '+job )
plt.semilogy(it[:istamax],itdt[:istamax],'-',
               it[:icvgmax],cvg[:icvgmax,5],'g-',
               it[:icvgmax],cvg[:icvgmax,6],'r-')
plt.grid()
# enforce integer x ticks
ax = plt.gca()
ax.xaxis.get_major_locator().set_params(integer=True)
plt.legend(['dt','force','disp'],
  fontsize='small',framealpha=0.5, loc=2)
# step time and number of contact elements
sp1=plt.subplot(2,1,2)
plt.plot(it[:istamax],itsteptime[:istamax],'r-',
           it[:istamax],itsteptime[:istamax],'b-',)
plt.legend(['# cont. el.','step time'],
             fontsize='small',framealpha=0.5, loc=2)
plt.ylabel('step time')
plt.xlabel('Iteration')
plt.grid()
# enforce integer x ticks
ax = plt.gca()
ax.xaxis.get_major_locator().set_params(integer=True)
sp2=sp1.twinx()
plt.plot(it[:icvgmax],cvg[:icvgmax,4],'r-')
plt.ylabel('# of cont. elements')
plt.savefig(job, bbox_inches='tight' )
plt.show()
