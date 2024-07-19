clear ;
while getopts "f:" opt;
	do case $opt in f)
		cat $OPTARG
		cat | echo
	esac
done

