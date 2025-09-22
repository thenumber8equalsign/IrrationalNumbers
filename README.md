# IrrationalNumbers
C++ program and headers to compute some irrational constants (basically just opensource y-cruncher)

# Compilation
## Dependencies
If you are on Windows, I was too lazy to make a guide, so you have to figure out how to install the dependencies and whatnot.<br />
MacOS users, I do not have a Mac, so I never got to test homebrew
Ensure that CMake, g++, and boost libraries are installed, check you distribution's package manager, or their repos/websites
[CMake Website](https://cmake.org/) <br />
[CMake GitLab](https://gitlab.kitware.com/cmake/cmake) <br />
[Gnu Compiler Collection (g++)](https://gcc.gnu.org/) <br />
[Gnu Compiler Collection (g++) repository](https://gcc.gnu.org/git/gcc.git) <br />
[Homebrew MacOS](https://brew.sh/) <br />
[Homebrew MacOS repository](https://github.com/Homebrew/brew) <br />
[Boost Website](https://www.boost.org/) <br />
[Boost GitHub](https://github.com/boostorg/boost) <br />

Some distribution specific installation methods: <br />
Arch and Arch based:
```bash
sudo pacman -S cmake gcc boost boost-libs
```
Debian and Debian based:
```bash
sudo apt install cmake gcc libboost-all-dev
```
Fedora and Fedora based:
```bash
sudo dnf install cmake gcc boost boost-devel
```
MacOS:
1. Install homebrew (if not done already)
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
2. Install packages
```bash
brew install boost
brew install cmake
brew install gcc
```

## Compilation
### Using automated scripts:
1. Make the scripts executable
  ```bash
  chmod +x ./build.sh
  chmod +x ./build_and_run.sh
  ```
2. Run either build.sh, or build_and_run.sh
  ```bash
  ./build.sh
  ```
  ```bash
  ./build_and_run.sh
  ```
  When either one is ran, a folder titled `build` will apepar, and in `build/bin` will be the executable <br />
### Manual:
1. Compile
```bash
  mkdir build
  cd build
  cmake -DCMAKE_BUILD_TYPE=Release ../src
  make
```
2. Execute
```bash
./bin/IrrationalNumbers
```

# Running pre-compiled executable
You need the boost runtime libraries to run this program:
Arch and Arch based:
```bash
sudo pacman -S boost-libs
```
Debian and Debian based:
```bash
sudo apt install libboost-all-dev
```
Fedora and Fedora based:
```bash
sudo dnf install boost
```
MacOS:
1. Install homebrew (if not done already)
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
2. Install packages
```bash
brew install boost
```

# Credits
This project was inspired by y-cruncher, a "Multi-Threaded Pi-Program" <br />
[y-cruncher](https://www.numberworld.org/y-cruncher/)

The formulas used are from Wikipedia, "The Free Encyclopedia" <br />
[Pi - Wikipedia, Modern quest for more digits -> Rapidly convergent series](https://en.wikipedia.org/wiki/Pi#Rapidly_convergent_series) <br />
[e (mathematical constant) - Wikipedia, Definitions](https://en.wikipedia.org/wiki/E_(mathematical_constant)#Definitions) <br />
[Newton's method - Wikipedia, Examples -> Use of Newton's method to compute square roots](https://en.wikipedia.org/wiki/Newton%27s_method#Use_of_Newton's_method_to_compute_square_roots) <br />
[Natural logarithm - Wikipedia, Efficient computation -> High precision](https://en.wikipedia.org/wiki/Natural_logarithm#High_precision) <br />
