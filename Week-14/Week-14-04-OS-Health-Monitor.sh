#!/bin/bash
# OS Health Monitor - combined CPU, memory and disk report
WARN=80

cpu_usage() {                                  # sample /proc/stat twice, 1 second apart
    read -r _ u1 n1 s1 i1 w1 q1 sq1 _ < /proc/stat
    sleep 1
    read -r _ u2 n2 s2 i2 w2 q2 sq2 _ < /proc/stat
    local idle=$(( (i2 + w2) - (i1 + w1) ))
    local total=$(( (u2+n2+s2+i2+w2+q2+sq2) - (u1+n1+s1+i1+w1+q1+sq1) ))
    echo $(( 100 * (total - idle) / total ))
}
flag() { [ "$1" -ge "$WARN" ] && echo "WARNING" || echo "OK"; }

echo "================ OS HEALTH MONITOR ================"
echo "Host   : $(hostname)"
echo "Time   : $(date '+%Y-%m-%d %H:%M:%S')"
echo "Uptime : $(uptime -p)"
echo
cpu=$(cpu_usage)
read -r l1 l5 l15 _ < /proc/loadavg
echo "[CPU]    usage ${cpu}% -> $(flag $cpu)"
echo "         load average (1/5/15 min): $l1 $l5 $l15, cores: $(nproc)"
set -- $(free -m | awk '/^Mem:/ {printf "%d %d %d", $3, $2, $3*100/$2}')
echo "[MEMORY] used $1 MB of $2 MB (${3}%) -> $(flag $3)"
disk=$(df -P / | awk 'NR == 2 { gsub("%", "", $5); print $5 }')
echo "[DISK]   / is ${disk}% full -> $(flag $disk)"
echo
echo "Top 3 CPU consumers:"
ps -eo pid,%cpu,%mem,comm --sort=-%cpu | head -n 4
