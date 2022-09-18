#!/bin/bash

expected_output="Line     Column   Token    Value
1        1        IF       if       
1        4        LPAREN   (        
1        5        IDENT    i        
1        7        EQ       ==       
1        10       NUMBER   0        
1        11       RPAREN   )        
1        13       LBRACE   {        
1        14                         
2        5        KEY_INT  int      
2        9        IDENT    i        
2        11       ASSIGN   =        
2        13       NUMBER   0        
2        14       SEMI     ;        
4        8        IF       if       
4        11       LPAREN   (        
4        12       IDENT    i        
4        13       RPAREN   )        
4        14       SEMI     ;        
4        15                         
6        5        KEY_INT  int      
6        9        IDENT    i        
6        22       ASSIGN   =        
6        24       NUMBER   0        
6        25       SEMI     ;        
6        26                         
7        1        RBRACE   } 
"

output="$(cat tests/test1.txt | ./program2)"
output="${output::-10}"
output="${output// /}"
expected_output="${expected_output::-6}"
expected_output="${expected_output// /}"

diff <(echo "$output") <(echo "$expected_output")

if [ "$output" = "$expected_output" ]; then
    echo 'Tests passed.'
else
    echo 'Tests failed.'
fi