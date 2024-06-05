/*
*
*perpetual calendar
*
*/
#include <stdio.h>
#include <stdbool.h>

int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int first_day_of_month(int year, int month) {
     int offset = (year - 1900) * 365 + (year - 1901) / 4 - (year - 1901) / 100 + (year - 1901) / 400;
    for (int i = 1; i < month; ++i) {
        offset += days_in_month[i - 1];
    }
    return (offset + 1) % 7;
}

void print_calendar(int year) {
    printf("Calendar for the year %d:\n\n", year);

    for (int month = 1; month <= 12; ++month) {
        if (month == 2 && is_leap_year(year)) {
            days_in_month[1]++;
        }
        printf("Month %d:\n", month);
        printf("   Sun Mon Tues Wed Thur Fri Sat\n");
        printf("-------------------------------\n");
        int day = 1;
        int weekday = first_day_of_month(year, month);
        while (day <= days_in_month[month - 1]) {
            for (int i = 0; i < weekday; ++i) {
                printf(" ");
            }
            printf("%3d ", day++);
            weekday = (weekday + 1) % 7;
            if (weekday == 0) {
                printf("\n");
            }
        }
        printf("\n");
        if (month == 2 && is_leap_year(year)) {
            days_in_month[1]--;
        }
    }
}

int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    print_calendar(year);

    return 0;
}
