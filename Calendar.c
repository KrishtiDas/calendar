#include <stdio.h>

// Function to return day for date DD/MM/YYYY
int dayNumber(int day, int month, int year) {
    static int t[] = {0, 3, 2, 5, 0, 3,
                      5, 1, 4, 6, 2, 4};
    year -= month < 3;
    return (year + year / 4 - year / 100
            + year / 400 + t[month - 1] + day) % 7;
}

// Function to return name of the given month
char* getMonthName(int monthNumber) {
    char* months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};
    return months[monthNumber];
}

// Function to return number of days in a month
int numberOfDays(int monthNumber, int year) {
    if (monthNumber == 0) return 31;
    if (monthNumber == 1)
        return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28;
    if (monthNumber == 2) return 31;
    if (monthNumber == 3) return 30;
    if (monthNumber == 4) return 31;
    if (monthNumber == 5) return 30;
    if (monthNumber == 6) return 31;
    if (monthNumber == 7) return 31;
    if (monthNumber == 8) return 30;
    if (monthNumber == 9) return 31;
    if (monthNumber == 10) return 30;
    if (monthNumber == 11) return 31;
    return 0; // Safety
}

// Function to print the calendar of the given year
void printCalendar(int year) {
    printf("          Calendar - %d\n\n", year);
    int days;
    int current = dayNumber(1, 1, year); // day index position from 0 to 6

    for (int i = 0; i < 12; i++) {
        days = numberOfDays(i, year);

        printf("\n  ------------%s-------------\n", getMonthName(i));
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        int k;
        for (k = 0; k < current; k++)
            printf("    "); // 4 spaces for alignment

        for (int j = 1; j <= days; j++) {
            printf("%4d", j);

            if (++k > 6) {
                k = 0;
                printf("\n");
            }
        }

        if (k != 0)
            printf("\n");

        current = k;
    }
}

// Driver code
int main() {
    int year = 2025; // you can change this to your desired year
    printCalendar(year);
    return 0;
}
