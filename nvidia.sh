#!/bin/bash

gpu_output=$(nvidia-smi --query-gpu=utilization.gpu --format=csv,noheader,nounits)
gpu_utilization=$(echo "$gpu_output" | awk -F "," '{print $1}')

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

echo "$(generate_progress_bar "$gpu_utilization")"
