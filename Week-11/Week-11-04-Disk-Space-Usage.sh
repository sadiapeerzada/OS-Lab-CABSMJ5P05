#!/bin/bash
# Display disk space usage
FMT="%-14s %6s %6s %6s %5s  %s\n"
echo "Disk space usage"
df -hP | awk -v fmt="$FMT" '
    NR == 1       { printf fmt, "Filesystem", "Size", "Used", "Avail", "Use%", "Mounted on"; next }
    $1 ~ /^\/dev\// { printf fmt, $1, $2, $3, $4, $5, $6 }'
echo
df -P | awk '$1 ~ /^\/dev\// { gsub("%", "", $5)
                               if ($5 >= 80) printf "WARNING: %s is %s%% full\n", $6, $5 }'
echo "Disk usage of the current directory: $(du -sh . 2>/dev/null | cut -f1)"
