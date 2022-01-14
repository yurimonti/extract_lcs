# extract_lcs
it's a terminal's program in C that allows to extract into an output file an LCS (Longest Common Subsequence) between two binary files.

##Usage
Command to run this program is: 
```bash
extractlcs <first_input_file_path> <second_input_file_path> <output_file_path>
```

##Compiling
To Compile and get the executable needs [cmake](https://cmake.org/) tools
open the terminal in the project folder and exec: 
```bash
cmake CMakeLists.txt
```

Now it's possible to run make command in the same folder: 

```bash
make
```

This creates an executable file named extractlcs.

##Run
Now you can exec this program : 
```bash
extractlcs <first_input_file_path> <second_input_file_path> <output_file_path>
```

##License & copyright

© Yuri Monti , Unicam University of Camerino

Licensed under the [MIT License](LICENSE).
