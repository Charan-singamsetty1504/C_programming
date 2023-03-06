#include <stddef.h>
#include<stdio.h>

struct my_struct {
    int field1;
    char field2;
    float field3;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

int main() {
    struct my_struct s;
    int *p_field1 = &s.field1;
    struct my_struct *p_s = container_of(p_field1, struct my_struct, field1);

    // Now p_s points to the whole struct s
    return 0;
}
`