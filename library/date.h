typedef unsigned short Year;
typedef unsigned char Month;
typedef unsigned char Day;
typedef unsigned char Weekday;

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

char* date()
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

	int nWeekday = weekday(2020, 02, 24);

	return weekDayName[--nWeekday];
}