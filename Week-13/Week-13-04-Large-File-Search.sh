#!/bin/bash
# Usage: ./w13_04.sh [directory]   (default: /)
DIR=${1:-/}
echo "Files larger than 100 MB under $DIR:"
results=$(find "$DIR" -xdev -type f -size +100M -printf '%s\t%p\n' 2>/dev/null \
          | sort -rn | numfmt -d $'\t' --field=1 --to=iec)
if [ -z "$results" ]; then
    echo "  No file larger than 100 MB found"
else
    echo "$results"
    echo "Total: $(echo "$results" | wc -l) file(s)"
fi
