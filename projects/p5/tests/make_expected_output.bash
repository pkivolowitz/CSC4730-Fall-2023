#!/bin/zsh
setopt verbose
../next < test_01.txt > test_01.expected_output.txt
../next < test_02.txt > test_02.expected_output.txt
../next < test_03.txt > test_03.expected_output.txt
../next < test_04.txt > test_04.expected_output.txt
../next < test_05.txt > test_05.expected_output.txt
../next < test_06.txt > test_06.expected_output.txt
../next < test_07.txt > test_07.expected_output.txt
../next < test_08.txt > test_08.expected_output.txt
../next < test_09.txt > test_09.expected_output.txt
../next < test_10.txt > test_10.expected_output.txt
../next < test_11.txt > test_11.expected_output.txt
../next < test_12.txt > test_12.expected_output.txt
../next < test_13.txt > test_13.expected_output.txt
../next < test_14.txt > test_14.expected_output.txt
../next < test_15.txt > test_15.expected_output.txt

../best < test_20.txt > test_20.expected_output.txt
../best < test_21.txt > test_21.expected_output.txt
../best < test_22.txt > test_22.expected_output.txt
../best < test_23.txt > test_23.expected_output.txt
../best < test_24.txt > test_24.expected_output.txt
../best < test_25.txt > test_25.expected_output.txt
../best < test_26.txt > test_26.expected_output.txt
../best < test_27.txt > test_27.expected_output.txt
../best < test_28.txt > test_28.expected_output.txt
../best < test_29.txt > test_29.expected_output.txt
../best < test_30.txt > test_30.expected_output.txt
../best < test_31.txt > test_31.expected_output.txt
../best < test_32.txt > test_32.expected_output.txt
unsetopt verbose

