#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTIONS 10
#define MAX_SIZE 100

int main() {
    char ip[MAX_SIZE], op1[MAX_SIZE], op2[MAX_SIZE], temp[MAX_SIZE];
    int sizes[MAX_PRODUCTIONS] = {0};
    char c;
    int n, j, l;

    printf("Enter the Parent Non-Terminal : ");
    scanf(" %c", &c);

    ip[0] = c;
    ip[1] = '\0';

    strcat(op1, ip);
    strcat(op1, "\'->");
    strcat(op2, ip);
    strcat(op2, "\'\'->");
    strcat(ip, "->");

    printf("Enter the number of productions : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Production %d : ", i + 1);
        scanf("%s", temp);
        sizes[i] = strlen(temp);
        strcat(ip, temp);

        if (i != n - 1)
            strcat(ip, "|");
    }

    printf("Production Rule : %s\n", ip);

    char x = ip[3];
    for (int i = 0, k = 3; i < n; i++) {
        if (x == ip[k]) {
            if (ip[k + 1] == '|') {
                strcat(op1, "#");
                ip[k + 1] = ip[0];
                ip[k + 2] = '\'';
                k += 4;
            } else {
                strcat(op1, "|");
                strcat(op1, ip + k + 1);
                memmove(ip + k - 1, ip + k + sizes[i], strlen(ip + k + sizes[i]) + 1);
            }
        } else {
            while (ip[k++] != '|');
        }
    }

    char y = op1[6];
    for (int i = 0, k = 6; i < n - 1; i++) {
        if (y == op1[k]) {
            if (op1[k + 1] == '|') {
                strcat(op2, "#");
                op1[k + 1] = op1[0];
                op1[k + 2] = '\'';
                k += 5;
            } else {
                memmove(temp, op1 + k + 1, strlen(op1 + k + 1) + 1);
                strcat(op2, "|");
                strcat(op2, temp);
                memmove(op1 + k - 1, op1 + k + strlen(temp) + 2, strlen(op1 + k + strlen(temp) + 2) + 1);
            }
        }
    }

    op2[strlen(op2) - 1] = '\0';

    printf("After Left Factoring:\n");
    printf("%s\n", ip);
    printf("%s\n", op1);
    printf("%s\n", op2);

    return 0;
}

