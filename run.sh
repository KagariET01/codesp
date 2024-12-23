clear
vim 0.in
timeout 5s /usr/bin/time -v ./run < 0.in > 0.out 2> 0.log
#vim 0.out
echo "-----cerr-----"
cat 0.log
echo "-----cout-----"
cat 0.out
