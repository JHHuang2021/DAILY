#include <cstdio>
#include <iostream>
/** You can not use other libraries.*/

//TODO:
struct node {
    int item_a = 0;
    int item_b = 0;
    int group = 0;
    int raw = 0;
    int products = 0;
} today, yesterday;

void getItem(int a, int b) {
    yesterday.item_a += a;
    yesterday.item_b += b;
}

int half() {
    today.group = std::min(yesterday.item_b, yesterday.item_a);
    today.item_a = yesterday.item_a - today.group;
    today.item_b = yesterday.item_b - today.group;
    return yesterday.group;
}

int remain() {
    return today.item_b + today.item_a;
}

int product() {
    today.products = yesterday.raw;
    today.raw = yesterday.group;
    int ans = today.products * 0.95;
    today.item_a += (today.products - ans);
    today.item_b += (today.products - ans);
    yesterday = today;
    return ans;
}

int (*factory[3])() ={remain, half, product};