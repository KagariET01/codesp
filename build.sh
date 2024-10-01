clear ;
while getopts "f:" opt;
	do case $opt in f)
		if g++ -DDBG -g -o run $OPTARG ; then
			echo "build successful";
			sh run.sh;
		fi;
	esac
done

