ptask UpdateDateAndTime[1000](playerid)
{
	new time[3],
		date[3],
		str[64];

	static const MonthNames[][] =
    {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

	// hour - minute - second
	gettime(time[0], time[1], time[2]);
	// year - month - day
	getdate(date[0], date[1], date[2]);

	format(str, sizeof(str), "%02d:%02d:%02d", time[0], time[1], time[2]);
	PlayerTextDrawSetString(playerid, DateAndTime[playerid][2], str);

	format(str, sizeof(str), "%d, %s %d", date[2], MonthNames[date[1] - 1], date[0]);
	PlayerTextDrawSetString(playerid, DateAndTime[playerid][3], str);

	if(time[0] != LastWorldHour)
	{
		LastWorldHour = time[0];
		SetWorldTime(time[0]);
	}
	return 1;
}