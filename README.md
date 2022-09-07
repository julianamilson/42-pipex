<div align="center">
 
 # 42-pipex
 
  ![image](https://user-images.githubusercontent.com/67876847/188769152-68652ce3-cb6c-44ee-9c4f-ed239fa4d4ad.png)

</div>

## Introduction
This project aims to reproduce UNIX's mechanism *pipe* (`|`), which can be simply used as:

`cmd1 file1 | cmd2 > file2`

Where `cmd1` does something with `file1`'s data and the result goes to `cmd2` in order to be changed. Then the output redirection (`>`) saves its result. 
On this project, the same command is expressed as `infile cmd1 cmd2 outfile`.


## How to run

1. Clone this repository on your terminal. 
```bash
git clone https://github.com/julianamilson/42-pipex/
```

2. Access 42-pipex repository on your computer and compile the program.
```bash
cd 42-pipex && make
```

3. In order to run the program, you have to specify the file used for input, two commands and the output file's name.

```bash
./pipex infile cmd1 cmd2 outfile
```

Just like the example bellow:
```bash
./pipex infile cat "tr ' ' '-'" outfile
```

4. Won't use it anymore? Here you go!
```bash
make fclean
```

