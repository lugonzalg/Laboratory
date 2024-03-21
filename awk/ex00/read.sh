#!/bin/bash

echo "Print every line of a text file."

awk {print} source.txt

echo "Print the first field of each line in a text file."

awk '{print $1}' source.txt

echo "Field manipulation"

awk '{print $2" "$1}' source.txt