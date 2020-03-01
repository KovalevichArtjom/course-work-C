typedef unsigned short Year;
typedef unsigned char Month;
typedef unsigned char Day;
typedef unsigned char Weekday;
typedef struct
{
	int day;
	int month;
	int year;
} Date;

// using "Perpetual calendar" algorithm
Weekday weekday(Year year, Month month, Day day) 
{
	if (month < 3u) {
		--year;
		month += 10u;
	}
	else {
		month -= 2u;
	}
		
	return (Weekday)((day + 31u * month / 12u + year + year / 4u - year / 100u + year / 400u) % 7u);
}

char* getNameWeekday(int day, int month, int year)
{
	char* weekDayName[] = {
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
		"Sunday"
	};

	int nWeekday = weekday(year, month, day);

	return weekDayName[--nWeekday];
}

void setBirthdayStudent(char fcontent[MAX][LEN])
{
	Date d[MAX];
	char dChar[3];
	char mChar[3];
	char yChar[5];
	char* weekday;
	auto errValidate;

	printf("WARNING: Students' birthdays are recorded in the format dd-mm-yyyy.\n");

	for (int i = 0; i < MAX; i++) {

		printf("Enter birthday %s: ", fcontent[i]);
		errValidate = scanf("%d-%d-%d", &d[i].day, &d[i].month, &d[i].year);
		getchar();

		if (errValidate != 3 || (d[i].day > 31 || d[i].month > 12 || d[i].year > 3000)) {
			printf("ERROR: Invalid date.\nPlease enter a date agree format dd-mm-yyyy\n");
			i--;
			continue;
		}

		strcat(fcontent[i], " ");
		sprintf(dChar, "%d", d[i].day);
		strcat(fcontent[i], dChar);
		strcat(fcontent[i], "-");
		sprintf(mChar, "%d", d[i].month);
		strcat(fcontent[i], mChar);
		strcat(fcontent[i], "-");
		sprintf(yChar, "%d", d[i].year);
		strcat(fcontent[i], yChar);
		strcat(fcontent[i], " ");

		weekday = getNameWeekday(&d[i].day, &d[i].month, &d[i].year);
		strcat(fcontent[i], weekday);
	}
}

char* date(char	fcontent[MAX][LEN])
{
	setBirthdayStudent(fcontent);
}