#pragma once //include guard

#undef strtok

char *strtok(char *__restrict str, const char *__restrict delim);


char *strtok(char *__restrict str, const char *__restrict delim) {
    static char *last;
    if (str == nullptr) {
        if (last == nullptr)
            return nullptr;
        int rej[128] = {0}, head = 0;
        for (int i = 0; i < strlen(delim); i++)
            rej[delim[i]]++;
        while (rej[last[head]]) {
            if (head == strlen(last) - 1)
                return nullptr;
            head++;
        }
        char *ans = last + head;
        for (int i = head; i < strlen(last); i++) {
            if (rej[last[i]]) {
                if (i + 1 < strlen(last)) {
                    last[i] = '\0';
                    last += (i + 1);
                } else {
                    last[i] = '\0';
                    last = nullptr;
                }
                return ans;
            }
        }
        last = nullptr;
        return ans;
    } else {
        int rej[128] = {0}, head = 0;
        for (int i = 0; i < strlen(delim); i++)
            rej[delim[i]]++;
        while (rej[str[head]]) {
            if (head == strlen(str) - 1)
                return nullptr;
            head++;
        }
        for (int i = head; i < strlen(str); i++) {
            if (rej[str[i]]) {
                str[i] = '\0';
                last = str + i + 1;
                return str + head;
            }
        }
        last = nullptr;
        return str + head;
    }
}


