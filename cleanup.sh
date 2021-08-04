#!/usr/bin/env bash

# skrypt powloki, ktory usuwa podkatalogi build oraz .vscode

for file in *; do
    if [ -d "$file" ] # sprawdzanie czy w danym katalogu znajduja sie jakiekolwiek podkatalogi
    then	
        if [ -d ${file}/build ] # sprawdzanie czy katalog zawiera podkatalog build
        then	
        	echo "Removing ${file}/build..."
        	rm -r ${file}/build
        	echo "${file}/build was removed"
        fi
        if [ -d ${file}/.vscode ] # sprawdzanie czy katalog zawiera podkatalog .vscode
        then
        	echo "Removing ${file}/.vscode..."
        	rm -r ${file}/.vscode
        	echo "${file}/.vscode was removed"
        fi
    fi
done
