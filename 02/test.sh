#!/bin/bash

expected_output="Line     Column   Token    Value
1        1        6        if       
1        4        4        (        
1        5        7        i        
1        7        1        ==       
1        10       8        0        
1        11       4        )        
1        13       4        {        
1        14       11                
2        5        7        int      
2        9        7        i        
2        11       10       =        
2        13       8        0        
2        14       5        ;        
4        8        6        if       
4        11       4        (        
4        12       7        i        
4        13       4        )        
4        14       5        ;        
4        15       11                
6        5        7        int      
6        9        7        i        
6        22       10       =        
6        24       8        0        
6        25       5        ;        
6        26       11                
7        1        4        }
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