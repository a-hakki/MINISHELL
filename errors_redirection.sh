
# error: syntax error near unexpected token `newline`
    - echo hello >
    - echo hello >>
    - echo hello <
    - cat <<
    - echo hi &&
    - echo hi ||

# error: syntax error near unexpected token `|, &&, ||, ) or (`
    - echo hello > |
    - ( echo hi > | cat )
    - echo hello > &&
    - echo hello > ||
    - echo hello > )
    - ( echo hello > )
    - echo hello > (

# error: syntax error near unexpected token `>>`
    echo hello >>> file

# error: syntax error near unexpected token `<<`
    - cat <<<< file
    - << EOF
something
EOF

# error: syntax error near unexpected token `>`
    - > file
    - echo hi && > file
    - ( > out.txt )

# error: syntax error near unexpected token `<`
    - < file
    - echo hi || <
    - ( < infile ) && echo done

# Bash allows this, but you must decide: either support it or treat as syntax error (most 42 shells don't support it)
    - > out.txt echo hi
