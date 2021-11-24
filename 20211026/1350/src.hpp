#pragma once //include guard

#undef strcspn
#undef strstr


size_t strcspn(const char *s, const char *reject);

const char *strstr(const char *haystack, const char *needle);
//char *strstr (char *haystack, const char *needle);


size_t strcspn(const char *s, const char *reject) {
    int rej[128] = {0};
    for (int i = 0; i < strlen(reject); i++)
        rej[reject[i]]++;
    for (int i = 0; i < strlen(s); i++)
        if (!rej[s[i]])
            return i;
    return strlen(s);
}

const char *strstr(const char *haystack, const char *needle) {
    for (int head = 0; head <= strlen(haystack) - strlen(needle); head++) {
        int flag = 0;
        for (int i = 0; i < strlen(needle); i++)
            if (haystack[head + i] != needle[i]) {
                flag = 1;
                break;
            }
        if (!flag)
            return haystack + head;
    }
    return nullptr;
}


//char *strstr (char *haystack, const char *needle) {
//	return const_cast<char*>(strstr(const_cast<const char*>(haystack), needle));
//}


