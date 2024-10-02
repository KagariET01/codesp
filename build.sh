clear ;
while getopts "f:" opt;
	do case $opt in f)
		if g++ -DDBG -g -o run $OPTARG 2> compile.log ; then
			echo "build successful";
			sh run.sh;
		else
			cat compile.log;
		fi;
	esac
done

