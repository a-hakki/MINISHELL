# #!/bin/bash

# echo "---- MiniShell Grammar Parsing Test ----"

# tests=(
#   # ✅ Valid Commands
#   "echo hello"                         # ✅
#   "echo 'hello world'"                # ✅
#   "echo \"hello \$USER\""             # ✅
#   "ls -l | grep minishell"            # ✅
#   "cat < infile > outfile"            # ✅
#   "echo hi >> file"                   # ✅
#   "cat << EOF\nhello\nEOF"            # ✅
#   "echo hi | grep h | wc -l"          # ✅
#   "export VAR=123"                    # ✅
#   "export VAR+=456"                   # ✅
#   "unset VAR"                         # ✅

#   # ❌ Invalid Commands
#   "|"                                 # ❌ starts with pipe
#   "| ls"                              # ❌ starts with pipe
#   "ls || grep minishell"              # ❌ double pipe not supported
#   "echo > > file"                     # ❌ invalid redirection
#   "echo < > file"                     # ❌ ambiguous redirection
#   ">"                                 # ❌ just redirection without command
#   "<"                                 # ❌ same here
#   "echo hello |"                      # ❌ ends with pipe
#   "cat <<EOF"                         # ❌ missing heredoc end
#   "echo 'unclosed string"             # ❌ unclosed quote
#   "export 1INVALID=42"                # ❌ invalid identifier
# )

# for test in "${tests[@]}"
# do
#   echo -e "\n🧪 Test: $test"
#   echo "$test" | bash -c "$test" 2>/dev/null && echo "✅ Valid" || echo "❌ Invalid"
# done

#!/bin/bash

MINISHELL=./minishell  # Change this to your minishell binary path

run_test() {
	echo "🧪 Test: $1"
	echo "$1" | $MINISHELL > out.txt 2>&1
	if [ $? -eq 0 ]; then
		echo "✅ Success"
	else
		echo "❌ Failed"
	fi
	cat out.txt
	echo "---------------------------"
}

# Valid exports
run_test "export VAR=hello"
run_test "export VAR2=123"
run_test "export VAR3="
run_test "export VAR_4=value"
run_test "export VAR5=\"quoted value\""
run_test "export VAR6='single quoted'"
run_test "export VAR7+=appended"
run_test "export VAR7+=again"
run_test "export VAR8=\$USER"
run_test "export VAR9=value=with=equals"
run_test "export VAR10=\"va\\\"lu\\\"e\""
run_test "export VAR+="

# Invalid exports
run_test "export 1INVALID=value"
run_test "export =value"
run_test "export VAR+"
run_test "export +VAR=value"
run_test "export VAR@name=value"
run_test "export VAR-name=value"
run_test "export VAR#=value"
run_test "export VAR!=value"
run_test "export VAR\$=value"
run_test "export VAR=value other"

# Edge behavior
run_test "export VAR"
run_test "export VAR=      "
run_test "export"  # Show all exports
