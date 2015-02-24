# build-cross-tools.sh #

Compile given GNU projects (gcc, binutils, newlib, gdb) with C and C++
front-ends for a given target (--target, GNU syntax (arch-abi)) and
install it in the given prefix (--prefix).

It is also possible to compile cross-compilation binaries without
target libraries (standard nor runtime libraries) by activating
--without-newlib switch.

```
Usage: build-cross-tools.sh OPTIONS

      --binutils=DIR         Binutils source directory absolute path.
      --gcc=DIR              GCC source directory absolute path.
      --gdb=DIR              GDB source directory absolute path.
  -h, --help                 Show this message and exit.
      --newlib=DIR           Newlib source directory absolute path.
      --prefix=DIR           Prefix (installation) directory absolute
                              path. Mandatory.
      --target=VAL           GNU tools target name E.g. : powerpc-eabi,
                              arm-eabi, i386-elf... Mandatory.
      --without-newlib       Compile gcc without runtime libraries.
```


## Notes: ##

- every paths must be absolute.
- root password is asked when installing in a directory (--prefix
  option argument) without write access.


## Requirements: ##

The following packages must be installed to be able to compile the toolchain:
- Texinfo
- MPFR
- GMP
- MPC
- Flex
- Bison
- Libexpat

## Examples: ##

- Full cross-compilation toolchain with target libraries (standard and
  runtime) to build nucleus for powerpc target:


```sh
./build-cross-tools.sh --target=powerpc-eabi              \
                       --gcc=/<path>/gcc-4.8.0            \
                       --binutils=/<path>/binutils-2.23.2 \
                       --gdb=/<path>/gdb-7.5.1            \
                       --newlib=/<path>/newlib-2.0.0
```

- Cross-gdb and cross-binutils only for arm targets:


```sh
./build-cross-tools.sh --target=arm-eabi                  \
                       --binutils=/<path>/binutils-2.23.2 \
                       --gdb=/<path>/gdb-7.5.1
```

- Full cross-compilation for i386 targets without target libraries:


```sh
./build-cross-tools.sh --target=i386-elf                  \
                       --gcc=/<path>/gcc-4.8.0            \
                       --binutils=/<path>/binutils-2.23.2 \
                       --gdb=/<path>/gdb-7.5.1            \
                       --without-newlib
```


## Compilation order (n depends on n-1): ##

- binutils
- gcc without libraries

--- stopped here when using --without-newlib

- newlib
- full gcc (with target libraries)

gdb is independent from other cross-tools.


## Bug: ##

The newlib's makefile has a known bug preventing launching this script
from your home directory.
