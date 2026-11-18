#!/bin/bash
# Display the top 5 memory-consuming processes
echo "Top 5 memory-consuming processes"
FMT="%-8s %-10s %-6s %-10s %s\n"
ps -eo pid,user,%mem,rss,comm --sort=-%mem | head -n 6 | awk -v fmt="$FMT" '
    NR == 1 { printf fmt, "PID", "USER", "%MEM", "RSS(KB)", "COMMAND"; next }
            { printf fmt, $1, $2, $3, $4, $5 }'
