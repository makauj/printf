# Printf Project

Custom lightweight implementation of `printf`-style formatting for learning and testing.

Overview

- Implements a subset of `printf` format specifiers with a buffered output path.
- Includes a small test harness under `tests/` and a Makefile that is PowerShell-friendly on Windows.

Build

- Requirements: `gcc`, `ar` (for `libprintf.a`). `make` is recommended but optional.

Unix / WSL / MSYS2 (typical):

```sh
make            # builds libprintf.a
make test       # builds and runs tests
make clean
```

Windows (PowerShell)

- The `Makefile` includes OS-aware targets and a PowerShell-safe `clean`/`test` flow when `make` is available.
- If `make` is not installed, you can build and run tests manually in PowerShell:

```powershell
#$src files list
$src = @('_printf.c','flush_buffer.c','format_handler.c','handle_binary.c',
'handle_char.c','handle_custom_string.c','handle_hex.c','handle_integer.c',
'handle_octal.c','handle_pointer.c','handle_string.c','handle_unsigned.c',
'handle_unknown.c','my_itoa.c','my_ftoa.c')

# Compile objects
gcc -Wall -Wextra -pedantic -std=c99 -I. -c $src
# Create static library
ar rcs libprintf.a *.o
# Build and run tests
gcc -Wall -Wextra -pedantic -std=c99 -I. tests/test_runner.c tests/test_printf.c -L. -lprintf -o test_runner
.\test_runner
```

Running sample program

```sh
gcc -Wall -Wextra -pedantic -std=c99 -I. main.c _printf.c flush_buffer.c format_handler.c \
 handle_binary.c handle_char.c handle_custom_string.c handle_hex.c handle_integer.c \
 handle_octal.c handle_pointer.c handle_string.c handle_unsigned.c handle_unknown.c \
 my_itoa.c my_ftoa.c -o all_build
./all_build
```

Tests

- New behavioral tests were added: `tests/test_printf.c` (unknown specifiers, null strings, INT_MAX/INT_MIN)
- The test runner is in `tests/test_runner.c` and is integrated into the `test` target.

Notes

- `main.c` was updated to avoid using the non-standard `%r` in the system `printf` (keeps `_printf` unknown-spec demo).
- `handle_integer.c` was adjusted to avoid manual negation that broke `INT_MIN`.

Contributing

- Open an issue for bugs or propose PRs; run tests locally before submitting.

Credits

- Educational project / exercise implementation.
