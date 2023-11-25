## crc32

**crc32** is a command line utility to compute for file crc32

### Prerequisite for building

[CMake 3.16](https://cmake.org/cmake/help/latest/release/3.16.html)

[for Ubuntu 20.04 LTS - CMake 3.16.3 suite maintained and supported by Kitware](https://www.kitware.com/cmake-3-16-3-available-for-download/)

[for macBook - CMake 3.25.2 suite maintained and supported by Kitware](https://www.kitware.com/cmake-3-25-2-available-for-download/)

[GNU 9.4.0 compiler source](https://ftp.gnu.org/gnu/gcc/gcc-9.4.0/)

[gcc (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0](https://packages.ubuntu.com/focal/gcc-9)

<br/>

<details><summary>Building, Testing, installing crc32 on Ubuntu 20.04 (focal)</summary>

### The Ubuntu 20.04 LTS OS

```bash
$ uname -a
# Linux * 5.15.0-89-generic #99~20.04.1-Ubuntu SMP Thu Nov 2 15:16:47 UTC 2023 x86_64 x86_64 x86_64 GNU/Linux

$ lsb_release -a
# No LSB modules are available.
# Distributor ID:	Ubuntu
# Description:	Ubuntu 20.04.6 LTS
# Release:	20.04
# Codename:	focal

```

### The compiler

#### CMake

```bash
$ cmake --version
# cmake version 3.16.3

# CMake suite maintained and supported by Kitware (kitware.com/cmake).

```

#### gcc on Ubuntu 20.04 LTS

```bash
$ gcc --version
# gcc (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0
# Copyright (C) 2019 Free Software Foundation, Inc.
# This is free software; see the source for copying conditions.  There is NO
# warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

```

### Running make install

```bash
make clean && make install

# if [ -d build/ ]; then rm -rf ./build ; fi

mkdir -p build && cd ./build && cmake ../ && cp -f Makefile Makefile.crc32 && make -f Makefile.crc32 1> /dev/null

# -- The C compiler identification is GNU 9.4.0
# -- The CXX compiler identification is GNU 9.4.0
# -- Check for working C compiler: /usr/bin/cc
# -- Check for working C compiler: /usr/bin/cc -- works
# -- Detecting C compiler ABI info
# -- Detecting C compiler ABI info - done
# -- Detecting C compile features
# -- Detecting C compile features - done
# -- Check for working CXX compiler: /usr/bin/c++
# -- Check for working CXX compiler: /usr/bin/c++ -- works
# -- Detecting CXX compiler ABI info
# -- Detecting CXX compiler ABI info - done
# -- Detecting CXX compile features
# -- Detecting CXX compile features - done
# -- Configuring done
# -- Generating done
# -- Build files have been written to: /project/github/crc32/crc32/build

cd ./build && sudo make -f Makefile.crc32 install
# [100%] Built target crc32
# Install the project...
# -- Install configuration: ""
# -- Installing: /usr/local/bin/crc32

# List the installed crc32
ls -vlt /usr/local/bin/crc32
# -rwxr-xr-x 1 root root 19304 Nov 25 19:38 /usr/local/bin/crc32

# Check if it works on itself
crc32 /usr/local/bin/crc32
# d94a6b0d    /usr/local/bin/crc32

```

### Running make test

```bash
make clean && make test

# if [ -d build/ ]; then rm -rf ./build ; fi

mkdir -p build && cd ./build && cmake ../ && cp -f Makefile Makefile.crc32 && make -f Makefile.crc32 1> /dev/null

# -- The C compiler identification is GNU 9.4.0
# -- The CXX compiler identification is GNU 9.4.0
# -- Check for working C compiler: /usr/bin/cc
# -- Check for working C compiler: /usr/bin/cc -- works
# -- Detecting C compiler ABI info
# -- Detecting C compiler ABI info - done
# -- Detecting C compile features
# -- Detecting C compile features - done
# -- Check for working CXX compiler: /usr/bin/c++
# -- Check for working CXX compiler: /usr/bin/c++ -- works
# -- Detecting CXX compiler ABI info
# -- Detecting CXX compiler ABI info - done
# -- Detecting CXX compile features
# -- Detecting CXX compile features - done
# -- Configuring done
# -- Generating done
# -- Build files have been written to: /project/github/crc32/crc32/build

# Testing crc32.c w/o -id
35f69a1b    crc32.c

# Testing crc32.c with -id
35f69a1b

```

### Clean temporary files

```bash
make clean

# if [ -d build/ ]; then rm -rf ./build ; fi

ls -vlt ./build
# ls: cannot access './build': No such file or directory

```

</details>
<br/>

<details><summary>Building, Testing, installing crc32 on Windows 10+</summary>

### Running make install

- TODO: Running make install on Windows 10+

### Running make test

- TODO: Running make test on Windows 10+

### Clean temporary files

- TODO: Clean temporary files on Windows 10+

</details>
<br/>

<details><summary>Building, Testing, installing crc32 on macBook ventura 13.6.1</summary>

### The macBook OS

```bash
$ uname -a
# Darwin *-MacBook-Pro.local 22.6.0 Darwin Kernel Version 22.6.0: Wed Oct  4 21:25:26 PDT 2023; root:xnu-8796.141.3.701.17~4/RELEASE_X86_64 x86_64

```

### The compiler

#### CMake

```bash
$ cmake --version
# cmake version 3.25.2

# CMake suite maintained and supported by Kitware (kitware.com/cmake).

```

#### gcc alias apple clang on macBook ventura 13.6.1

```bash
$ gcc --version
# Apple clang version 15.0.0 (clang-1500.0.40.1)
# Target: x86_64-apple-darwin22.6.0
# Thread model: posix
# InstalledDir: /Library/Developer/CommandLineTools/usr/bin

```

### Running make install

```bash
$ make clean && make install

# if [ -d build/ ]; then rm -rf ./build ; fi

mkdir -p build && cd ./build && cmake ../ && cp -f Makefile Makefile.crc32 && make -f Makefile.crc32 1> /dev/null

# -- The C compiler identification is AppleClang 15.0.0.15000040
# -- The CXX compiler identification is AppleClang 15.0.0.15000040
# -- Detecting C compiler ABI info
# -- Detecting C compiler ABI info - done
# -- Check for working C compiler: /Library/Developer/CommandLineTools/usr/bin/cc - skipped
# -- Detecting C compile features
# -- Detecting C compile features - done
# -- Detecting CXX compiler ABI info
# -- Detecting CXX compiler ABI info - done
# -- Check for working CXX compiler: /Library/Developer/CommandLineTools/usr/bin/c++ - skipped
# -- Detecting CXX compile features
# -- Detecting CXX compile features - done
# -- Configuring done
# -- Generating done
# -- Build files have been written to: /project/github/crc32/crc32/build

cd ./build && sudo make -f Makefile.crc32 install
# [100%] Built target crc32
# Install the project...
# -- Install configuration: ""
# -- Installing: /usr/local/bin/crc32

# List the installed crc32
$ ls -vlt /usr/local/bin/crc32
-rwxr-xr-x  1 root  admin  49984 Nov 26 05:43 /usr/local/bin/crc32

# Check if it works on itself
$ crc32 /usr/local/bin/crc32
ebef386a    /usr/local/bin/crc32

```

### Running make test

```bash
$ make clean && make test

# if [ -d build/ ]; then rm -rf ./build ; fi

mkdir -p build && cd ./build && cmake ../ && cp -f Makefile Makefile.crc32 && make -f Makefile.crc32 1> /dev/null

# -- The C compiler identification is AppleClang 15.0.0.15000040
# -- The CXX compiler identification is AppleClang 15.0.0.15000040
# -- Detecting C compiler ABI info
# -- Detecting C compiler ABI info - done
# -- Check for working C compiler: /Library/Developer/CommandLineTools/usr/bin/cc - skipped
# -- Detecting C compile features
# -- Detecting C compile features - done
# -- Detecting CXX compiler ABI info
# -- Detecting CXX compiler ABI info - done
# -- Check for working CXX compiler: /Library/Developer/CommandLineTools/usr/bin/c++ - skipped
# -- Detecting CXX compile features
# -- Detecting CXX compile features - done
# -- Configuring done
# -- Generating done
# -- Build files have been written to: /project/github/crc32/crc32/build

# Testing crc32.c w/o -id
35f69a1b    crc32.c

# Testing crc32.c with -id
35f69a1b

```

### Clean temporary files

```bash
make clean

# if [ -d build/ ]; then rm -rf ./build ; fi

ls -vlt ./build
# ls: ./build: No such file or directory

```

</details>
<br/>

<br/>
<br/>

#### MIT LICENSE

[MIT LICENSE](https://github.com/tmalbonph/crc32/blob/master/LICENSE)

```s
MIT License

Copyright © 2010 - 2023 [Teddy Albon][tmalbon].

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

  [tmalbon]: https://tmalbon.com

```
