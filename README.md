<!-- Author (Created): Roger "Equah" Hürzeler -->
<!-- Date (Created): 12019.12.26 HE -->
<!-- License: apache-2.0 -->

**SBSInt [C]**
================================================================================

[SBSInt](https://github.com/TheEquah/SBSInt/) C library implementation.

--------------------------------------------------------------------------------

# Architecture

SBSInt architecture.

## SBSInt

A SBSInt are bytes added together, while the first and following is `0xFF`. As soon as a byte is not `0xFF`, it will be added to the number and finish reading there.

Example
```
[0x00, 0x00, 0x00] => 0
[0x0A, 0x00, 0x00] => 10
[0xFF, 0x00, 0x00] => 255
[0xFF, 0xA5, 0x00] => 420
```

--------------------------------------------------------------------------------

# Compile

To compile a C file using SBSInt, use the `#include "equah/sbsint.h"` at the beginning of the file.

The file can then be compiled by adding the `-I ./<path_to_src> -x c ./<path_to_src>/equah/sbsint.c` to the `gcc` command where `<path_to_src>` is the path to the [`/src/`](https://github.com/TheEquah/SBSInt-c/tree/master/src/) directory.

It will probably look something like `gcc -I ./SBSInt-c/src -x c ./SBSInt-c/src/equah/sbsint.c -x c ./main.c -o main.o`.

--------------------------------------------------------------------------------

# Examples

This repository provides the following example uses for SBSInt.

## Convert

Example which converts an integer to SBSInt and back.

Directory: [`/example/convert`](https://github.com/TheEquah/SBSInt-c/tree/master/example/convert/)

--------------------------------------------------------------------------------
