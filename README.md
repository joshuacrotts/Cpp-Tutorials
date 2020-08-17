# Cpp-Tutorials
This is a repository for the information and code in the data structures &amp; algorithms discord.

## Rebuilding C - Standards

**Windows**: To rebuild the code, clone the repository to your computer. This project is compiled with MinGW and a makefile. Depending on how you want to compile the project (e.g. with Visual Studio, CodeBlocks, etc.), you may need to alter the makefile to suit your needs. Downloading and installing the dependencies on Windows takes a little more effort than MacOS or Linux:
1. Download [mingw-get-setup.exe](https://osdn.net/projects/mingw/releases/).
2. Install all packages except mingw32-gcc-ada-base, mingw32-gcc-fortran-base, and mingw32-gcc-objc-base through the installer.
3. At this point, your code should be good to go. If you are using VSCode, make sure to set the compiler to gcc-x86, and set the compiler path to C:/MinGW/bin/gcc.exe. Compile the code via mingw32-make.

**MacOS / Linux**: Theoretically, this should just work with the normal make system. Try it out.
