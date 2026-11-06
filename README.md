# Unreal C++ Sandbox

A clean Unreal Engine C++ gameplay and systems sandbox configured with Git LFS and Unreal-specific ignore rules.

## Repository Structure
- `Source/` — C++ gameplay classes, components, and systems
- `Config/` — Engine, input, and project configuration files
- `Content/` — Blueprints, levels (`.umap`), and binary assets (`.uasset`) tracked via Git LFS

## Setup & Usage
1. Clone the repository with Git LFS enabled:
   `git lfs install && git clone <repo-url>`
2. Right-click the `.uproject` file and select **Generate Xcode Project** (macOS) or **Generate Visual Studio project files** (Windows).
3. Open the `.uproject` in **Unreal Engine 5** to compile the C++ modules and launch the editor.

## Tech Stack
- **Unreal Engine 5**
- **C++**
- **Git & Git LFS**
