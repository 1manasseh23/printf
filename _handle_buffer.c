#include <stdio.h>
#include <stdarg.h>
#include "main.h"

static char output_buffer[BUFFER_SIZE];
static int buffer_index = 0;

void write_char(char c) {
    if (buffer_index < BUFFER_SIZE - 1) {
        output_buffer[buffer_index++] = c;
    }
}

void flush_buffer() {
    output_buffer[buffer_index] = '\0';
    printf("%s", output_buffer);
    buffer_index = 0;
}
