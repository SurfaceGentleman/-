#include<stdio.h>
#include<string.h>
char a[120] = { 0 }, b[120] = { 0 };
char sum[500] = { 0 };
char temp[400] = { 0 };
int flag = 0;
int i, j, t;
int s;
int main(void)
{
    scanf("%s%s", a, b);
    int len1 = strlen(a);
    int len2 = strlen(b);
    for(i = len1 - 1; i >= 0; i--) {
        for(t = len1, j = len1 - 1; j >= 0; j--, t--) {
            temp[t] += (a[j] - '0')*(b[i] - '0');
        }
        for(t = len1; t >= 1; t--) {
            if(temp[t] > 9) {
                temp[t-1] += temp[t] / 10;
                temp[t] %= 10;
            }
        }
        for(s = len1 + len2 - flag, t = len1; t >= 0; t--, s--) {
            sum[s]+=temp[t];
        }
        for(t = len1; t >= 0; t--) {
            temp[t] = 0;
        }
        for(s = len1 + len2; s >= 1;s--) {
            if(sum[s] > 9) {
                sum[s-1] += sum[s]/10;
                sum[s] %= 10;
            }
        }
        flag++;
    }
    sum[len1 + len2 + 1] = '\0';
    for(s = 0; s <= len1 + len2; s++) {
        sum[s] = sum[s] + '0';
    }
    for(s = 0; s < len1 + len2;s++) {
        if(sum[0] == '0') {
            for(t = 0; t <= len1 + len2 - s; t++) {
                sum[t] = sum[t+1];
            }
        }
        else {
            break;
        }
    }
    printf("%s\n", sum);
    return 0;
}
