#!/bin/bash

# expected_output_test.bash -i tfile -o ofile -a pfile
# -a prog - optional - if given is the name of the program to execute
#           if not given, a.out is assumed.
# -o ofile - 
# -i tfile - required - specifies the root name of input and expected output
#
# -i foo
#		foo.input will be the input file
#		foo.output will be the expected output file

temp_file="_tmp.txt"
root=""
prog="./a.out"
while getopts "i:a:" opt
do
	case ${opt} in
	a ) 
		prog=$OPTARG
		;;
	i )	
		root=$OPTARG
		;;
	\? ) # prints command line options
		echo "Usage:"
		echo "-i <rootname> [ required - specifies root name for test input and expected output"
		echo "-a <prog>     [ optional - if missing a.out is assumed"
		exit 0
		;;
	esac
done

if [ -z $root ]
then
	echo "-i root_file_name not specified"
	exit 1
fi

if [ ! -x $prog ]
then
	echo $prog "does not exist or is not an executable"
	exit 1
fi

input_file=$root".input.txt"
expected_output=$root".expected_output.txt"

echo "Test input file:      " $input_file
echo "Expected output file: " $expected_output
echo "Expected output (must match letter for letter):"
cat $expected_output
$prog $input_file > $temp_file
echo "Your output:"
cat $temp_file
echo "Differences:"
diff $temp_file $expected_output
a=$?
if [ $a -eq 0 ]
then
	echo "PASSED"
else
	echo "FAILED"
fi
echo "Test finished"
rm -f $temp_file
exit $a



