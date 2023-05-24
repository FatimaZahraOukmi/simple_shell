#include <ctype.h>
#include "shell.h"

int is_interactive() {  
    return isatty(STDIN_FILENO) && !isatty(STDERR_FILENO);
}

int is_delim(char c, char *delims) {
    while (*delims) {
        if (c == *delims) return 1;
        delims++;  
    }
    return 0;
}

int is_alphabetic(int c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int str_to_int(char *str) {    
    int result = 0;
    
    while (*str) {
        if (*str >= '0' && *str <= '9')
            result = result * 10 + (*str++ - '0'); 
        else
            break;        
    }
    
    return result;
}
