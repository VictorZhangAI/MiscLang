#include <stdio.h>

int main() {
    char *code = "#include <stdio.h>%c%cint main() {%c    char *code = %c%s%c;%c    printf(code, 10, 10, 10, 34, code, 34, 10, 10);%c    return 0;%c}%c";
    printf(code, 10, 10, 10, 34, code, 34, 10, 10);
    return 0;
}
