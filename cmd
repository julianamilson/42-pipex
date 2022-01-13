./pipex infile "ls-l" "grepzao x" output
./pipex infile "cat" "trzero a b" output
./pipex infile "catzado" "wc -w" output
./pipex infile "cat" "cat -e" output
./pipex file1 "cat" "grep x" output/outfile5 ok
