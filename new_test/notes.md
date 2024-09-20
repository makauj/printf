# Printf

### Key Concepts to Learn

1. **Variadic Functions**:
   - Functions that accept a variable number of arguments.
   - Use of `stdarg.h` library which provides macros to handle variable arguments.

2. **Format Specifiers**:
   - Understanding different format specifiers like `%d`, `%s`, `%f`, etc.

3. **String Manipulation**:
   - Functions like `strlen`, `strcpy`, and `strcat`.

### Step-by-Step Guide to Building a Custom `printf`

1. **Include Necessary Headers**:
   - Include the standard input/output and variadic function headers.
   ```c
   #include <stdio.h>
   #include <stdarg.h>
   ```

2. **Define the Custom `printf` Function**:
   - Use `va_list`, `va_start`, `va_arg`, and `va_end` macros to handle variable arguments.
   ```c
   Void my_printf(const char *format, ...) {
       Va_list args;
       Va_start(args, format);

       For (const char *p = format; *p != ‘\0’; p++) {
           If (*p == ‘%’) {
               P++;
               Switch (*p) {
                   Case ‘d’: {
                       Int i = va_arg(args, int);
                       Printf(“%d”, i);
                       Break;
                   }
                   Case ‘c’: {
                       Int c = va_arg(args, int);
                       Putchar(c);
                       Break;
                   }
                   Case ‘s’: {
                       Char *s = va_arg(args, char *);
                       Printf(“%s”, s);
                       Break;
                   }
                   Default:
                       Putchar(‘%’);
                       Putchar(*p);
                       Break;
               }
           } else {
               Putchar(*p);
           }
       }

       Va_end(args);
   }
   ```

3. **Handle Different Format Specifiers**:
   - Extend the switch-case to handle more specifiers like `%f` for floating-point numbers, `%x` for hexadecimal, etc.
   ```c
   Case ‘f’: {
       Double d = va_arg(args, double);
       Printf(“%f”, d);
       Break;
   }
   Case ‘x’: {
       Int x = va_arg(args, int);
       Printf(“%x”, x);
       Break;
   }
   ```

4. **Test Your Custom `printf` Function**:
   - Write a main function to test various cases.
   ```c
   Int main() {
       My_printf(“Hello, %s!\n”, “world”);
       My_printf(“Number: %d\n”, 42);
       My_printf(“Character: %c\n”, ‘A’);
       My_printf(“Hex: %x\n”, 255);
       My_printf(“Float: %f\n”, 3.14);
       Return 0;
   }
   ```

### Additional Tips

- **Error Handling**: Add error handling for unsupported format specifiers.
- **Buffer Management**: For more advanced implementations, consider managing an output buffer instead of directly printing to the console.
