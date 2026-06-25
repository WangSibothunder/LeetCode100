# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

This is a LeetCode practice repository containing C++ solutions. File names follow the pattern `{problemNumber}{problemName}.cpp` (e.g., `2addTwoNumbers.cpp`, `394decodeString.cpp`). The `weekly/` subdirectory holds weekly contest solutions.

## Build & Run

- **Build single file**: `clang++ -std=c++17 -g <file>.cpp -o build/<file>` (binaries go to `build/`, which is gitignored)
- **Syntax check only** (for files without `main()`): `clang++ -std=c++17 -fsyntax-only <file>.cpp`
- **Run**: `./build/<file>`
- **Format code**: `clang-format -i <file>.cpp` (or save in VS Code — `formatOnSave` is enabled)
- **VS Code**: `F5` to debug, `Ctrl+F5` to run without debugging, or use the top-right ▶ button. Config is in `.vscode/launch.json` and `.vscode/tasks.json`.

There is no build system (no CMake/Makefile). Each `.cpp` file is a standalone solution compiled directly with clang++. Most files contain only a `Solution` class without `main()` — they will fail to link but pass syntax checks (LeetCode provides its own `main()`).

## VS Code Debug Configuration

`.vscode/launch.json` provides two configurations:
- **运行 (调试模式)** — Debug with breakpoints via lldb (Microsoft C/C++ extension, type: `cppdbg`)
- **运行 (不调试)** — Build and run without debugging

Both use `preLaunchTask` to build with `clang++ -std=c++17 -g` before launching. `.vscode/tasks.json` defines the build task.

## Code Architecture

**Utility headers** (shared data structures):
- `link.h` — Defines `ListNode` struct (singly-linked list node). Include this for linked-list problems.
- `tree.h` — Defines `TreeNode` struct (binary tree node). Include this for tree problems.

Both headers also `#include` common STL headers (`<iostream>`, `<queue>`, `<stack>`, `<unordered_map>`, `<unordered_set>`, `<vector>`) and declare `using namespace std;`.

**Solution files**: Each contains a `Solution` class with the LeetCode problem's method. Some files include `main()` for local testing (LeetCode ignores it). Debug print statements (`cout`) are often left in, commented out with `//`.

**Conventions**:
- Uses `using namespace std;` at file scope (non-standard but used consistently)
- Comments are in Chinese
- VS Code is configured with C++ IntelliSense disabled (`C_Cpp.autocomplete: "disabled"`), suggestions heavily restricted. The user relies on clang-format for formatting and manual coding without IDE assistance.

## Parent Repository

This `withoutHint/` directory is part of a larger monorepo at `/Users/wangsibo/program/leecode/` containing other LeetCode practice subsets (`CodeWounder/`, `daily/`, `firsttry/`, `HOT100_1/`, `systemStudy/`).
