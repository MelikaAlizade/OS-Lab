#!/bin/bash

read -p "Enter PID: " pid

if [ ! -d "/proc/$pid" ]; then
	echo "process NOT found!"
	exit 1
fi
exe=$(readlink -f "/proc/$pid/exe" 2>/dev/null)
memory=$(awk '/VmRSS/ {print $2 * 1024}' "/proc/$pid/status" 2>/dev/null)
args=$(tr '\0' ' ' < "/proc/$pid/cmdline" 2>/dev/null)
envs=$(tr '\0' '\n' < "/proc/$pid/environ" 2>/dev/null)

echo "EXE: $exe"
echo "Memory Usage: ${memory:-0}"
echo "Exe Args: $args"
echo "Environment Variables:"
echo "$envs"
