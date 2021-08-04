#!/usr/bin/env bash

# prosty skrypt powloki kompilujacy wszystkie projekty jednoczesnie

for dir in $(find $PWD -maxdepth 1 -regex '.*Lab[0-9]+$' -type d)	# szuka po podkatalogach ktorych nazwa konczy sie na LabXX
do 
	if [[ (-f ${dir}/CMakeLists.txt) && (! -d ${dir}/build) ]]
	then	# sprawdzanie czy katalog zawiera plik CMakeLists.txt oraz katalog build (bo projekty juz moga byc skompilowane)
        	mkdir ${dir}/build
	 	cd ${dir}/build
	 	cmake ../
	 	make
        else
        	echo "${dir}: CMakeLists.txt was not found or 'build' directory already exists"
        fi
	 
done
