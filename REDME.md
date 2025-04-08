

# KHASSANA NTRIMIW L CMND MN LOWAL



commmand not found: DONE<br>
ls && . : DONE<br>
ls && : DONE<br>
ls && (cat Makefile ) : SEGV DONE   |---->    Command not found : ) there is no execution for ls !!  <br>
ls && (cat Makefile ) (space)  2 doubl frees : SEGV <br>
cat Makefile (ls) : DONE <br>
cat "Makefile && (ls) : 2double free  : SEGV <br>