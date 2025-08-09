#!/bin/bash

for pidd in /proc/[0-9]*; do
pid=$(basename "$pidd")

if [ -f "$pidd/status" ]; then
	statusCode=$(awk '/^State:/ {print $2}' "$pidd/status")
	if [ "$statusCode" = "R" ]; then
		name=$(awk '/^Name:/ {print $2}' "$pidd/status")
		echo "PID: $pid , Name: $name"
	fi
fi
done
