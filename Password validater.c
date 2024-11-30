#include <stdio.h>
#include <ctype.h>
#include <string.h>

int checkPasswordCriteria(char password[]) {
    int length = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUpper = 1;
        } else if (islower(password[i])) {
            hasLower = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        } else if (ispunct(password[i])) { 
            hasSpecial = 1;
        }
    }

    if (!hasUpper) {
        printf("Password must contain at least one uppercase letter.\n");
    }
    if (!hasLower) {
        printf("Password must contain at least one lowercase letter.\n");
    }
    if (!hasDigit) {
        printf("Password must contain at least one digit.\n");
    }
    if (!hasSpecial) {
        printf("Password must contain at least one special character (e.g., @, #, $, etc.).\n");
    }

    if (hasUpper && hasLower && hasDigit && hasSpecial) {
        return 1;
    }
    
    return 0;
}

int main() {
    char password[100];

    printf("Enter a password to check: ");
    scanf("%s", password);

    if (checkPasswordCriteria(password)) {
        printf("Password meets all the criteria.\n");
    } else {
        printf("Password does not meet the required criteria.\n");
    }

    return 0;
}
