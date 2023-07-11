#!/bin/bash

disk_output=$(df -h /)
used_disk=$(echo "$disk_output" | awk 'NR==2{print $3}')
available_disk=$(echo "$disk_output" | awk 'NR==2{print $4}')
disk_usage=$(echo "$disk_output" | awk 'NR==2{sub("%","",$5); print $5}')

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

echo "$(generate_progress_bar "$disk_usage")"
