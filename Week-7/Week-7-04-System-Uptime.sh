#!/bin/bash
# Display system uptime and running processes
echo "===== SYSTEM UPTIME ====="
uptime
uptime -p
echo
echo "===== PROCESSES ====="
echo "Total processes   : $(ps -e --no-headers | wc -l)"
echo "Running (state R) : $(ps -eo stat --no-headers | grep -c '^R')"
echo
echo "Top 5 processes by CPU usage:"
ps -eo pid,ppid,stat,%cpu,%mem,comm --sort=-%cpu | head -n 6
