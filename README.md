![](/images/demo.jpg.png)

# Simple XOR Encryption 

---

## About
* Simple XOR Encryption is a command line tool to encrypt files that contains confidential information (files, images, videos...etc).
* Available on Windows, Linux and MacOS.

## Build

### For Ubuntu, Debian

1. Install g++, git through `apt`
```sh
sudo apt install g++ git 
```
2. Clone the repository
```sh
git clone https://github.com/jackiesogi/Simple_XOR_Encryption.git
```
3. Modify the **directory you want to encrypt** and a **encryption key** you want to apply in...
   * /src/close.cpp line 40, 41.
   * /src/open.cpp line 44, 45.
4. Compile the source code using g++
```sh
g++ -std=c++17 -Wall ./src/open.cpp -o ./bin/open
g++ -std=c++17 -Wall ./src/close.cpp -o ./bin/close
```
5. Put the ./bin/open and ./bin/close to the directory you want to encrypt, or set a environment variable by modifying the `~/.bashrc` or other shell environment configuration file you're using. 

### For Windows

1. Download `MSYS2` from [MSYS Website](https://www.msys2.org/)

```plain
The source code includes <filesystem> library,
which is recently not provided in mingw include folder,
the solution is to install MSYS2 environment.
```

2. Download `GitBash` from [Git](https://git-scm.com/downloads)
3. Make sure you've added `C:\\MINGW\` and `C:\\Program Files\Git\cmd\` into environment variables
![](/images/win-build.png)
4. Same as the step for ubuntu and debian from step 2 to step 5.