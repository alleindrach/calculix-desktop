# Prool's makefile
all:
	cd ARPACK;sh ./fixhome.sh;make lib
	cd ..
	cd SPOOLES.2.2;make lib
	cd ..
	cd CalculiX/ccx_2.19/src;make
	cd ../../..
	cp CalculiX/ccx_2.19/src/ccx_2.19 ccx
clean:
	cd ARPACK;make clean
	cd ..
	cd SPOOLES.2.2;make clean
	cd ..
	cd CalculiX/ccx_2.19/src;make clean
	cd ../../..
	rm ccx
