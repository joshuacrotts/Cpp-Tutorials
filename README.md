# Cpp-Tutorials
This is a repository for the information and code in the data structures &amp; algorithms discord.

## Rebuilding C - Standards

**Windows**: To rebuild the code, clone the repository to your computer. This project is compiled with MinGW and a makefile. Depending on how you want to compile the project (e.g. with Visual Studio, CodeBlocks, etc.), you may need to alter the makefile to suit your needs. Downloading and installing the dependencies on Windows takes a little more effort than MacOS or Linux:
1. Download [mingw-get-setup.exe](https://osdn.net/projects/mingw/releases/).
2. Install all packages except mingw32-gcc-ada-base, mingw32-gcc-fortran-base, and mingw32-gcc-objc-base through the installer.
3. Download the four libraries above. The SDL2.0.12 link only provides a DLL file. The rest come in a .tar.gz file to extract. Make sure to choose the MinGW developer version.
4. Inside these archives exists two folders: an i686-w64, and x86_64-w64 version. Choose the former (i686-w64). This is the 32-bit version, which is what we will use.
5. There are three folders in each extension: bin, include, and lib. The bin/ folder provides the .dll files. Store these in C:/MinGW/bin. The include/ folder has an SDL2 folder with the respective .h file. Drag the SDL2 folder into C:/MinGW/include (do not take the .h file out!). Lastly, the lib/ folder contains necessary libraries (.a files) that accompany the addon. Drag these into C:/MinGW/lib.
6. At this point, your code should be good to go. If you are using VSCode, make sure to set the compiler to gcc-x86, and set the compiler path to C:/MinGW/bin/gcc.exe. Compile the code via mingw32-make.

**MacOS / Linux**: Theoretically, this should just work with the normal make system. Try it out.
