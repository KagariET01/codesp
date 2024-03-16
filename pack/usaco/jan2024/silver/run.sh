



# { while getopts "f:" opt; do case $opt in f)  if g++ -o run $OPTARG ; then ./run; fi; esac done }
# { while getopts "f:" opt ; do rm ./run & g++ -o run $OPTARG & ./run ; done }
clear & { while getopts "f:" opt; do case $opt in f) if g++ -o run $OPTARG ; then echo "build successful"& ./run; fi; esac done }

# read -p "檔名: " f
# clear & if g++ -o run $OPTARG ; then ./run; fi
