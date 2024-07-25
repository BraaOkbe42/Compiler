#!/bin/bash

# Directory to store generated files
GENERATED_DIR="./generated_files"

# Create the directory if it doesn't exist
mkdir -p $GENERATED_DIR

# Run lex and yacc
lex scanner.l
yacc -d parser.y

# Move generated files to the specified directory
mv lex.yy.c y.tab.c y.tab.h $GENERATED_DIR

# Change to the directory with generated files
cd $GENERATED_DIR

# Compile the generated files
gcc lex.yy.c y.tab.c -o myparser -ll

# Move back to the original directory
cd ..

# Run the parser with the input file
./generated_files/myparser < input.txt
