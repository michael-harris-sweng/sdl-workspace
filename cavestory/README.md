# Cavestory - C++ Remake

## Environment Setup

<hr />

### Unix
<details>
    <summary>Instructions</summary>

1. Install SDL 2.0 development library `libsdl2-dev`:
   * e.g. `sudo apt-get install libsdl2-dev`
2. Install `make`:
   * e.g. `sudo apt-get install make`
3. Install `g++`:
   * e.g. `sudo apt-get install g++`
</details>

<hr />

### Windows (MinGW & VS Code)
<details>
    <summary>Instructions</summary>

1. Install `MSYS2` platform for Windows:
   * Follow the latest [install instructions](https://www.msys2.org/)
2. Install `cmder` console emulator:
   * Follow the latest [install instructions](https://github.com/cmderdev/cmder)
3. Create a new `cmder` task for `mingw`:
   * Name: `bash::mingw64`
   * Task parameters: `/icon "%USERPROFILE%\AppData\Local\lxss\bash.ico"`
   * Commands: `-new_console:d:D:\dev set CHERE_INVOKING=1 & set MSYSTEM=MINGW64 & set MSYS2_PATH_TYPE=inherit & "c:\msys64\usr\bin\bash.exe" --login -i zsh`
4. Install requires packages:
   * `pacman -S <package>`
   * Where `<package>` is each of [`zsh`, `man`, `neofetch`, `git`, `make`, `mingw-w64-x86_64-gcc`]
5. Configure utilities
   * `oh-my-zsh` - Run [install script](https://ohmyz.sh/#install)
   * Copy [dotfiles/zsh/.zshrc](https://github.com/michael-harris-sweng/dotfiles/blob/master/zsh/.zshrc) to local `~/.zshrc`
   * Copy [dotfiles/git/.gitconfig](https://github.com/michael-harris-sweng/dotfiles/blob/master/git/.gitconfig) to local `~/.gitconfig`, un-commenting the `core.autocrlf = true` config.
   * Copy the changes from [dotfiles/nano/nanorc](https://github.com/michael-harris-sweng/dotfiles/blob/master/nano/nanorc) to `/etc/nanorc`.
   * Add `zsh` to the end of your `~/.bashrc` config to run `zsh` on startup.
6. Install SDL 2.0
   * Download the latest [release of
SDL2-devel-2.24.0-mingw.tar.gz](https://github.com/libsdl-org/SDL/releases/tag/release-2.24.0). 
   * Extract the contents to a dedicated development library directory for MinGW e.g. `C:\mingw_dev_lib`.
   * Copy the contents of `x86_64-w64-mingw32/` to `C:\mingw_dev_lib` (e.g. `lib`, `shared`, `bin`, `include`).
   * Add `C:\mingw_dev_lib` to your environment PATH.
7. Setup GitHub SSH Key 
   * Run `ssh-keygen -t ed25519 -C "<your@email.here>"`.
   * Accept the defaults, then run `cat ~/.ssh/id_ed25519.pub`.
   * Copy the output into the GitHub SSH key field.
8. Clone Repo
   * Make a development folder, for example `D:\dev\`.
   * Inside the dev folder, run `gcl git@github.com:michael-harris-sweng/sdl-workspace.git`.
9. Build and Execution (CLI)
   * Open `cmder` using profile `bash::mingw64` and run `cd /d/dev/sdl-workspace/cavestory`
   * Run `make` from `cavestory/`
   * Run `./cavestory.exe`
   * To debug in the CLI, run `gdb ./cavestory.exe`
10. Install VS Code
   * Download latest from [their site](https://code.visualstudio.com/download).
   * Open a new VS Code workspace in `sdl-workspace/`.
11. Setup Makefile Extensions
   * Install the following extensions: [`C/C++`, `Makefile Tools`].
   * Update `@ext:ms-vscode.makefile-tools` settings
      * `Makefile Path` = `./cavestory/makefile`
      * `Make Director` = `./cavestory`
   * Select `Build target: [compile_win]`, and `Launch target: [build\cavestory.exe]` on the Makefile tab.
   * You can now compile and run by pressing `Makefile: Run the selected binary target in the terminal`
12. Setup GDB debugging
   * Create `sdl-workspace/.vscode/launch.json` with the following:
      ```
      {
         // Use IntelliSense to learn about possible attributes.
         // Hover to view descriptions of existing attributes.
         // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
         "version": "0.2.0",
         "configurations": [
            {
                  "name": "Debug Cavestory",
                  "type": "cppdbg",
                  "request": "launch",
                  "program": "${workspaceFolder}/cavestory/build/cavestory.exe",
                  "args": [],
                  "stopAtEntry": false,
                  "cwd": "${workspaceFolder}/cavestory",
                  "environment": [],
                  "externalConsole": false,
                  "MIMode": "gdb",
                  "miDebuggerPath": "C:/msys64/usr/bin/gdb.exe",
                  "setupCommands": [
                     {
                        "description": "Enable pretty-printing for gdb",
                        "text": "-enable-pretty-printing",
                        "ignoreFailures": true
                     }
                  ],
            }
         ]
      }
      ```
   * You can now debug the executable created above by debugging (F5). 
</details>

<hr />

## Credit
All code within this sub-repo is based off the tutorial series from @limeoats -> https://github.com/Limeoats

<hr />

## Assets
Download from the [fan-hosted site](http://www.cavestory.org/download/cave-story.php)
