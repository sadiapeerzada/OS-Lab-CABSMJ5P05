#!/bin/bash
# List running processes that use more than 5% CPU
LIMIT=5
echo "Processes using more than ${LIMIT}% CPU:"
ps -eo pid,user,%cpu,%mem,comm --sort=-%cpu | awk -v lim="$LIMIT" '
    NR == 1 { print; next }
    $3 > lim { print; found = 1 }
    END { if (!found) print "  (no process above " lim "%)" }'
