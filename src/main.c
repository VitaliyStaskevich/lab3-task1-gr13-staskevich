#include <stdio.h>

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1; 
    else
        return 0; 
}

int daysInMonth(int month, int year) {
    switch (month) {
        case 2:
            return isLeapYear(year) ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

int daysSinceEpoch(int day, int month, int year) {
    int totalDays = 0;
    int y;

    for (y = 1970; y < year; y++) {
        totalDays += isLeapYear(y) ? 366 : 365;
    }

    for (int m = 1; m < month; m++) {
        totalDays += daysInMonth(m, year);
    }

    totalDays += day - 1;

    return totalDays;
}

int main() {
    int day1, month1, year1;
    printf("Input the first date (D, M, Y): ");
    scanf("%d %d %d", &day1, &month1, &year1);

    int day2, month2, year2;
    printf(("Input the second date (D, M, Y): ");
    scanf("%d %d %d", &day2, &month2, &year2);

    int days1 = daysSinceEpoch(day1, month1, year1);
    int days2 = daysSinceEpoch(day2, month2, year2);
    int daysDifference = days2 - days1;

    printf("Days beetween theese two dates %d\n", daysDifference);

    return 0;
}