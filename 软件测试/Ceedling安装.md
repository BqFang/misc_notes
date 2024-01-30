# Ceeding安装步骤(Windows)

## 1. 安装Ruby

 官网下载Ruby，使用rubyinstaller-devkit-2.7.2-1-x64版本；

> 官网地址：[Download Archives (rubyinstaller.org)](https://rubyinstaller.org/downloads/archives/)

下载完成后一直点击下一步（注意勾选安装向导中添加到Path选项），安装完成后在cmd检测是否安装成功；

```shell
$ ruby -v
ruby 2.7.2p137 (2020-10-01 revision 5445e04352) [x64-mingw32]
```

## 2. 安装Ceeding

Ceeding是ruby gem镜像源中的一个软件。

RubyGems 是 Ruby 的一个包管理器，它提供一个分发 Ruby 程序和库的标准格式，还提供一个管理程序包安装的工具。RubyGems 旨在方便地管理 gem 安装的工具，以及用于分发 gem 的服务器。这类似于 Ubuntu 下的apt-get, Centos 的 yum，Python 的 pip。

需要修改国内网络才可以下载，更换国内源步骤如下：

+ 查看当前源

```shell
$ gem sources -l

https://rubygems.org/
```

+ 移除当前源

```shell
$ gem sources --remove https://rubygems.org/
```

+ 添加国内源并查看

```shell
$ gem sources -a https://gems.ruby-china.com/
$ gem sources -l

# 请确保只有 gems.ruby-china.com
```

完成以上操作后可安装Ceeding，建议使用0.30.0版本；安装过程中会卡一下，稍等一两分钟即可;注意安装在ruby相同的安装路径；

```shell
$ gem install ceedling --version=0.30.0

Fetching constructor-2.0.0.gem
Fetching ceedling-0.30.0.gem
Fetching thor-1.3.0.gem
Successfully installed constructor-2.0.0
Successfully installed thor-1.3.0
Successfully installed ceedling-0.30.0
Parsing documentation for constructor-2.0.0
Installing ri documentation for constructor-2.0.0
Parsing documentation for thor-1.3.0
Installing ri documentation for thor-1.3.0
Parsing documentation for ceedling-0.30.0
Installing ri documentation for ceedling-0.30.0
Done installing documentation for constructor, thor, ceedling after 1 seconds
3 gems installed
```

## 3. 安装gcc

下载官网：[MinGW-w64 - for 32 and 64 bit Windows - Browse Files at SourceForge.net](https://sourceforge.net/projects/mingw-w64/files/)

下载MinGW-W64 GCC-8.1.0下[x86_64-win32-seh](https://sourceforge.net/projects/mingw-w64/files/Toolchains targetting Win64/Personal Builds/mingw-builds/8.1.0/threads-win32/seh/x86_64-8.1.0-release-win32-seh-rt_v6-rev0.7z)；并解压到任意目录，将bin目录添加到系统环境变量中；

安装完成后使用命令行进行检查：

```shell
$ gcc -v

Using built-in specs.
COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=D:/MinGW/x86_64-8.1.0-release-win32-seh-rt_v6-rev0/mingw64/bin/../libexec/gcc/x86_64-w64-mingw32/8.1.0/lto-wrapper.exe
Target: x86_64-w64-mingw32
Configured with: ../../../src/gcc-8.1.0/configure --host=x86_64-w64-mingw32 --build=x86_64-w64-mingw32 --target=x86_64-w64-mingw32 --prefix=/mingw64 --with-sysroot=/c/mingw810/x86_64-810-win32-seh-rt_v6-rev0/mingw64 --enable-shared --enable-static --disable-multilib --enable-languages=c,c++,fortran,lto --enable-libstdcxx-time=yes --enable-threads=win32 --enable-libgomp --enable-libatomic --enable-lto --enable-graphite --enable-checking=release --enable-fully-dynamic-string --enable-version-specific-runtime-libs --disable-libstdcxx-pch --disable-libstdcxx-debug --enable-bootstrap --disable-rpath --disable-win32-registry --disable-nls --disable-werror --disable-symvers --with-gnu-as --with-gnu-ld --with-arch=nocona --with-tune=core2 --with-libiconv --with-system-zlib --with-gmp=/c/mingw810/prerequisites/x86_64-w64-mingw32-static --with-mpfr=/c/mingw810/prerequisites/x86_64-w64-mingw32-static --with-mpc=/c/mingw810/prerequisites/x86_64-w64-mingw32-static --with-isl=/c/mingw810/prerequisites/x86_64-w64-mingw32-static --with-pkgversion='x86_64-win32-seh-rev0, Built by MinGW-W64 project' --with-bugurl=https://sourceforge.net/projects/mingw-w64 CFLAGS='-O2 -pipe -fno-ident -I/c/mingw810/x86_64-810-win32-seh-rt_v6-rev0/mingw64/opt/include -I/c/mingw810/prerequisites/x86_64-zlib-static/include -I/c/mingw810/prerequisites/x86_64-w64-mingw32-static/include' CXXFLAGS='-O2 -pipe -fno-ident -I/c/mingw810/x86_64-810-win32-seh-rt_v6-rev0/mingw64/opt/include -I/c/mingw810/prerequisites/x86_64-zlib-static/include -I/c/mingw810/prerequisites/x86_64-w64-mingw32-static/include' CPPFLAGS=' -I/c/mingw810/x86_64-810-win32-seh-rt_v6-rev0/mingw64/opt/include -I/c/mingw810/prerequisites/x86_64-zlib-static/include -I/c/mingw810/prerequisites/x86_64-w64-mingw32-static/include' LDFLAGS='-pipe -fno-ident -L/c/mingw810/x86_64-810-win32-seh-rt_v6-rev0/mingw64/opt/lib -L/c/mingw810/prerequisites/x86_64-zlib-static/lib -L/c/mingw810/prerequisites/x86_64-w64-mingw32-static/lib '
Thread model: win32
gcc version 8.1.0 (x86_64-win32-seh-rev0, Built by MinGW-W64 project)
```

## 4. 安装gcov

gcov主要用于生成覆盖率报表；安装gcov需要使用pip命令，所以需要安装python3；

python下载路径：[Download Python | Python.org](https://www.python.org/downloads/)；选择合适版本即可；

下载完成后一直下一步，注意添加到PATH；

安装gcov：

```shell
$ pip install gcovr
```

查看版本;

```shell
$ gcov -v
gcov (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0
Copyright (C) 2018 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.
There is NO warranty; not even for MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.
```

