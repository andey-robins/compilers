#!/bin/bash

expected_output="Line     Column   Type     Length   Value
1        1        6        2        if       
1        4        4        1        (        
1        5        7        1        i        
1        7        1        2        ==       
1        10       8        1        0        
1        11       4        1        )        
1        13       4        1        {        
1        14       11       1                 
2        5        7        3        int      
2        9        7        1        i        
2        11       10       1        =        
2        13       8        1        0        
2        14       5        1        ;        
4        8        6        2        if       
4        11       4        1        (        
4        12       7        1        i        
4        13       4        1        )        
4        14       5        1        ;        
4        15       11       1                 
6        5        7        3        int      
6        9        7        1        i        
6        22       10       1        =        
6        24       8        1        0        
6        25       5        1        ;        
6        26       11       1                 
7        1        4        1        }
"

output="$(cat tests/test1.txt | ./program2)"
output="${output::-10}"
output="${output// /}"
expected_output="${expected_output::-10}"
expected_output="${expected_output// /}"

diff <(echo "$output") <(echo "$expected_output")

if [ "$output" = "$expected_output" ]; then
    echo 'Tests passed.'
else
    echo 'Tests failed.'
fi