#!/bin/bash

# Convert CPU burst time from milliseconds to nanoseconds,
# microseconds, and seconds.

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <time_in_milliseconds>"
    exit 1
fi

ms="$1"

# Validate numeric input (integer or decimal).
if ! [[ "$ms" =~ ^[0-9]+([.][0-9]+)?$ ]]; then
    echo "Error: Please enter a non-negative numeric value in milliseconds."
    exit 1
fi

ns=$(awk "BEGIN { printf \"%.6f\", $ms * 1000000 }")
us=$(awk "BEGIN { printf \"%.6f\", $ms * 1000 }")
s=$(awk "BEGIN { printf \"%.6f\", $ms / 1000 }")

echo "CPU Burst Time: $ms ms"
echo "Nanoseconds:     $ns ns"
echo "Microseconds:    $us us"
echo "Seconds:         $s s"
