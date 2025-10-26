#!/bin/zsh

echo "Compiling the specified Programme..."
if [ -z "$1" ]; then
    echo "No file specified"
    echo "Usage : ./compiler.sh path-to-your-programme"
    exit 1
fi

if [ "$2" ]; then
    echo "Too many arguments"
    echo "Usage : ./compiler.sh path-to-your-programme"
    exit 1
fi

filepath="$1"
filename=$(basename "$filepath" .cpp)
dir=$(dirname "$filepath")

g++ "$filepath" -o "$dir/$filename.exe"

if [ $? -eq 0 ]; then
    echo "✓ Compilation successful: $dir/$filename.exe"
    echo "Running..."
    "$dir/$filename.exe"
else
    echo "✗ Compilation failed!"
    exit 1
fi