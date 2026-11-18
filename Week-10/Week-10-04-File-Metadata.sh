#!/bin/bash
# Usage: ./w10_04.sh <filename>
if [ $# -ne 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi
if [ ! -e "$1" ]; then
    echo "Error: '$1' does not exist"
    exit 1
fi
echo "File name     : $1"
echo "Size          : $(stat -c %s "$1") bytes"
echo "Permissions   : $(stat -c '%A (%a)' "$1")"
echo "Owner         : $(stat -c %U "$1")"
echo "Last modified : $(stat -c %y "$1" | cut -d. -f1)"
