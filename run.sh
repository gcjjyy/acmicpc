g++ -o $1 $1.cpp
if [ -f "$1.txt" ]; then
	./$1 < $1.txt
else
	./$1
fi
