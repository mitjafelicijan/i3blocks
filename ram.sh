#!/bin/bash

ram_output=$(free -m | grep "Mem")
total_ram=$(echo "$ram_output" | awk '{print $2}')
used_ram=$(echo "$ram_output" | awk '{print $3}')
available_ram=$(echo "$ram_output" | awk '{print $7}')
ram_usage=$((used_ram * 100 / total_ram))

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

echo "$(generate_progress_bar "$ram_usage")"
