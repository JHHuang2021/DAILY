#include <bits/stdc++.h>

using namespace std;
int A[10005] = {0};
int temp[20010] = {0};
int tail = 0;//全局变量，成为下一个head
int _flag = 0;

int main() {
    int NumReading(int head, string str);//找到下一个数字
    int n;
    string str;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    getline(cin, str);
    while (!cin.eof()) {
        int h, flg = 0;
        getline(cin, str);
        for (h = 0; h < str.length(); h++)//找到op（1or2or3）
            if (str[h] >= '0' && str[h] <= '9') {
                flg = 1;
                break;
            }
        if (!flg)
            continue;
        //进入switch case
        switch (str[h]) {
            case '1': {
                h += 2;
                int tem = NumReading(h, str);
                if (_flag == 1) {//如果找到非法字符
                    printf("Bad\n");
                    _flag = 0;
                    break;
                } else
                    printf("%d\n", A[tem]);
                _flag = 0;
                break;
            }
            case '2': {
                memset(temp, 0, sizeof(temp));
                h += 2;
                int k = NumReading(h, str), flag = 0, i;
                if (_flag == 1) {
                    printf("Bad\n");
                    _flag = 0;
                    continue;
                }
                h = tail;
                for (i = 0;; i++) {
                    temp[i] = NumReading(h, str);
                    h = tail;
                    if (_flag == 2)//一行读完了
                    {
                        _flag = 0;
                        break;
                    }
                    if (_flag == 1) {//读到非法字符
                        printf("Bad\n");
                        flag = 1;
                        _flag = 0;
                        break;
                    }
                }
                if (i % 2 && !flag) {//如果多输入一个数字
                    printf("Fail\n");
                    flag = 1;
                }
                if (flag)
                    continue;
                for (int j = 0; j < i; j += 2)
                    A[temp[j]] = temp[j + 1];
                _flag = 0;
                break;
            }
            case '3': {
                memset(temp, -1, sizeof(temp));
                h += 2;
                int flag = 0, i;
                for (i = 0;; i++) {
                    temp[i] = NumReading(h, str);
                    h = tail;
                    if (_flag == 2)//一行读完了
                    {
                        _flag = 0;
                        break;
                    }
                    if (_flag == 1) {//读到非法字符
                        printf("Bad\n");
                        flag = 1;
                        _flag = 0;
                        break;
                    }
                }
                if (i % 2 && !flag) {//如果多输入一个数字
                    printf("Fail\n");
                    flag = 1;
                }
                if (flag)
                    continue;
                for (int j = 0; j < i; j += 2)
                    A[temp[j]] = temp[j + 1];
                _flag = 0;
                break;
            }
        }
    }
    return 0;
}

int NumReading(int head, string str) {
    int num = 0, i, flag = 0, flagm = 0;//flagm判断数字是否为负数
    for (i = head; i < str.length(); i++) {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\r')//直到空格结束
            continue;
        if (((str[i] < '0' || str[i] > '9') && str[i] != '-') || (str[i] == '-' && flagm))//读到非法字符
        {
            _flag = 1;
            return 0;
        }
        if (str[i] == '-' && (i == str.length() - 1 || str[i + 1] == ' ' || str[i + 1] == '\n' || str[i + 1] == '\r')) {
            _flag = 1;
            return 0;
        }
        if (str[i] == '-' && flagm) {
            _flag = 1;
            return 0;
        }
        if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9') {
            flagm = -1;
            continue;
        }
        flag = 1;//说明有读到数字
        if (flagm != -1)
            flagm = 1;
        num = num * 10 + str[i] - '0';
        if (str[i + 1] == 32)//之后是空格，结束数字读取
            break;
    }
    if (!flag) {
        _flag = 2;//no numbers
        return 0;
    }
    tail = i + 1;
    if (flagm == -1)
        return -1 * num;
    return num;
}