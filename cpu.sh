#!/usr/bin/bash

TMPFILE=/tmp/top_output.txt

top -bn 1 > $TMPFILE

cpu_line=$(grep "%Cpu" $TMPFILE)
cpu_usage=$(echo "$cpu_line" | awk '{print $2+$4}')
percentage=$(printf "%.0f" $cpu_usage)

generate_progress_bar() {
  local completed="$1"
  local total=100
  local length=10

  local completed_blocks=$((completed * length / total))
  local remaining_blocks=$((length - completed_blocks))

  if ((completed_blocks < length)); then
    if ((completed * length % total > 0)); then
      completed_blocks=$((completed_blocks + 1))
    fi
  fi

  printf "%s%s" "$(printf '▓%.0s' $(seq "$completed_blocks"))" "$(printf '░%.0s' $(seq "$remaining_blocks"))"
}

echo "$(generate_progress_bar "$percentage")"
rm $TMPFILE
