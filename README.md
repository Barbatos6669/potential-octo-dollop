# potential-octo-dollop

A feature-rich, console-based to-do list application written in modern C++.  
Now starting integration with SFML for GUI support!

---

## ✅ Features (Console Version)

- Add tasks with a name, description, and optional due date
- Validate input and prevent duplicates
- Remove tasks by ID
- Mark tasks as completed or undo them
- View tasks with due date status and days remaining
- Auto-save/load tasks from file
- Robust input validation and structured code
- Expandable with future features like search, sort, and reminders

---

## 🧰 Build Instructions

### Requirements:
- **MinGW-w64** (g++ 14+)
- **CMake** (if building SFML yourself)
- **SFML 2.6.2 built from source**  
  (Prebuilt SFML won’t work with modern g++ versions!)

### Building SFML from source:
> Only needed once. Skip if you already built it.

1. Download [SFML 2.6.2 source](https://github.com/SFML/SFML/releases/tag/2.6.2)
2. Use CMake GUI:
   - Source: `C:/SFML-2.6.2`
   - Build: `C:/SFML-2.6.2-Build`
   - Generator: **MinGW Makefiles**
   - Enable `BUILD_SHARED_LIBS=ON`
3. Run `mingw32-make` in the build folder

### Building the project:
1. Open this folder in **Visual Studio Code**
2. Press `Ctrl+Shift+B` to build using the provided `tasks.json`
3. Output will appear in the `bin/` folder

---

## ▶️ How to Run

1. Copy these `.dll` files from your SFML build (`/bin`) into your project `bin/` folder:
   - `sfml-graphics-2.dll`
   - `sfml-window-2.dll`
   - `sfml-system-2.dll`
   - `sfml-audio-2.dll`
   - `sfml-network-2.dll`
2. Run your program:
```sh
./bin/main.exe

## 🧪 SFML GUI (WIP)

We're working on building a simple GUI for the to-do list using SFML.
This will:

Render tasks visually

Allow mouse/keyboard interaction

Eventually replace the console UI

Stay tuned 👀

📝 License
This project is open-source and available under the MIT License.

---

