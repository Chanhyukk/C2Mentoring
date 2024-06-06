#include <stdio.h>
#include <time.h>

void printCalendar(int month, int year) {
    struct tm firstDay = {0};
    firstDay.tm_mday = 1;
    firstDay.tm_mon = month - 1;
    firstDay.tm_year = year - 1900;

    mktime(&firstDay);

    int monthDay;
    if (month == 2) {
        monthDay = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        monthDay = 30;
    }
    else {
        monthDay = 31;
    }

    printf("    %4d년 %2d월\n", year, month);
    printf("일 월 화 수 목 금 토\n");

    int startDay = firstDay.tm_wday;

    for (int i = 0; i < startDay; i++) {
        printf("   ");
    }

    for (int day = 1; day <= monthDay; day++) {
        printf("%-3d", day);
        if ((startDay + day) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    int month, year;
    printf("Input year and month: ");
    scanf("%d %d", &year, &month);
    printCalendar(month, year);
    return 0;
}
