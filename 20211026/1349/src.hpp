#pragma once //include guard

#undef strcmp
#undef strcpy

int Min(int x, int y) {
    if (x > y)
        return y;
    else
        return x;
}

int strcmp(const char *s1, const char *s2);

char *strcpy(char *__restrict dest, const char *__restrict src);

int strcmp(const char *s1, const char *s2) {
    int length_s1 = strlen(s1), length_s2 = strlen(s2);
    for (int i = 0; i < Min(length_s1, length_s2); i++) {
        if (s1[i] < s2[i])
            return -1;
        if (s1[i] > s2[i])
            return 1;
    }
    if (length_s1 == length_s2)
        return 0;
    else if (length_s1 > length_s2)
        return 1;
    else if (length_s1 < length_s2)
        return -1;
}

char *strcpy(char *__restrict dest, const char *__restrict src) {
    for (int j = 0; j < strlen(src); j++)
        if (dest == src + j)
            return dest;
    for (int j = 0; j < strlen(src) * 2; j++)
        if (dest + j == src)
            return dest;
    for (int i = 0; i < strlen(src); i++)
        dest[i] = src[i];
    dest[strlen(src)] = '\0';
    return dest;
}

