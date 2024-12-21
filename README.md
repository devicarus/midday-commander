<h1 align="center">🌞 midday-commander 🌞</h1>

> A **TUI file manager** written in **C++** using ncurses, designed for **MacOS** and **Linux**

<br>

<p align="center">
    <img alt="Build Status" src="https://img.shields.io/github/actions/workflow/status/devicarus/midday-commander/cmake-build.yml?style=for-the-badge">
    <a href="https://nightly.link/devicarus/midday-commander/actions/runs/12445478658/midday-commander-linux.zip?h=9f653bc732cce7dcbf4f28b7dbc84a8a3167bd38"><img alt="Linux Download" src="https://img.shields.io/badge/Linux-Download-green?style=for-the-badge&logo=linux&logoColor=white"></a>
    <a href="https://nightly.link/devicarus/midday-commander/actions/runs/12445478658/midday-commander-macos.zip?h=9f653bc732cce7dcbf4f28b7dbc84a8a3167bd38"><img alt="MacOS Download" src="https://img.shields.io/badge/MacOS-Download-blue?style=for-the-badge&logo=apple&logoColor=white"></a>
    <a href="https://devicarus.github.io/midday-commander/"><img alt="Static Badge" src="https://img.shields.io/badge/Documentation-yellow?style=for-the-badge&logo=doxygen&logoSize=auto"></a>
</p>

## 📦 Requirements

Ensure you have the following installed before running **midday-commander**:
- ncurses
- OpenSSL

## 📂 Usage

#### Basic Operations
- `q` - quit the program
- `↑` - move the cursor up
- `↓` - move the cursor down
- `↵` - enter a folder
- `b` - go back one level

#### Record Selection
- `s` - select/deselect the item under the cursor
- `f` - select items using RegEx
- `u` - clear selection

#### Record Operations
- `n` - create a file
- `N` - create a folder
- `S` - create a symlink to the item under the cursor
- `d` - delete selected items
- `c` - copy selected items to the currently opened folder
- `m` - move selected items to the currently opened folder

> Tip: Selection persists while navigating folders

#### Advanced Operations
- `1` - select files by content (supports RegEx)
- `2` - deduplicate the file under the cursor (finds duplicates and replaces them with symlinks)
- `3` - merge selected files into a new one (concat)

## ⚙️ Configuration

> The default settings require a terminal with support for `8-bit color`. If colors are not displaying correctly in your terminal (e.g., the cursor/selection is not distinguishable, etc.), try adjusting them in the configuration to one of the standard ANSI colors (`0-15`).

Placement: `~/.midday.json`

If the configuration file is not found, the [default configuration](https://devicarus.github.io/midday-commander/classTheme.html#a0b04fe65dfbfe8caaa03328079064131) is used.

Example configuration:
```json
{
    "theme": {
        "primary": 1,
        "secondary": 2,
        "background": -1,
        "accent1": 3,
        "accent2": 4,
        "accent3": 5	
    }
}
```
> Explanation of the theme items can be found in the [documentation](https://devicarus.github.io/midday-commander/classTheme.html#ad22a813d93709abadb56b61df00ebb2d).