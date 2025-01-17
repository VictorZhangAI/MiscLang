#!/bin/bash

# 遍历当前目录下所有子文件夹
for dir in */; do
  # 检查子文件夹中是否存在Cargo.toml文件，确保是Rust项目
  if [ -f "$dir/Cargo.toml" ]; then
    echo "Cleaning project in directory: $dir"
    cd "$dir"  # 进入子文件夹
    cargo clean  # 执行cargo clean
    sudo rm -rf .git .gitignore
    cd ..  # 返回到上层目录
  else
    echo "No Cargo.toml found in $dir, skipping..."
  fi
done

echo "All clean tasks completed."
