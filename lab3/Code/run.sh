#!/bin/bash

# 检查是否提供了参数 P
if [ -z "$1" ]; then
  echo "Usage: $0 <parameter P>"
  exit 1
fi

P=$1

# Step 1: 运行 parser，并将输出重定向到 cur.asm
echo "Running ./parser with parameter $P..."
if ! ./parser "$P" > cur.asm; then
  echo "Parser failed. Stopping script."
  exit 1
fi

# Step 2: 运行 qtspim
echo "Running qtspim with cur.asm..."
if ! qtspim cur.asm; then
  echo "qtspim failed. Stopping script."
  exit 1
fi

echo "Script completed successfully."

