/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) {

	//for calculating string length

	int dob1_len = 0, dob2_len = 0;

	int i = 0;
	while (dob1[i] != '\0')
	{
		dob1_len++;
		i++;
	}
	i = 0;
	while (dob2[i] != '\0')
	{
		dob2_len++;
		i++;
	}

	if ((dob1_len != 10) || (dob2_len != 10))
		{
			return -1;
		}

	int dob1_year, dob1_month, dob1_day, dob2_year, dob2_month, dob2_day;

	dob1_year = (dob1[6] - '0') * 1000 + (dob1[7] - '0') * 100 + (dob1[8] - '0') * 10 + (dob1[9] - '0') * 1;

	dob2_year = (dob2[6] - '0') * 1000 + (dob2[7] - '0') * 100 + (dob2[8] - '0') * 10 + (dob2[9] - '0') * 1;

	dob1_month = (dob1[3] - '0') * 10 + (dob1[4] - '0') * 1;

	dob2_month = (dob2[3] - '0') * 10 + (dob2[4] - '0') * 1;

	dob1_day = (dob1[0] - '0') * 10 + (dob1[1] - '0') * 1;

	dob2_day = (dob2[0] - '0') * 10 + (dob2[1] - '0') * 1;

	// checking whether the date is valid or not.
	
	

	if ((dob1[2] != '-') || (dob1[5] != '-') || (dob2[2] != '-') || (dob2[5] != '-'))
	{
		return -1;
	}
		

	if (dob1_month > 12)
	{
		return -1;
	}


	if (dob2_month > 12)
	{
		return -1;
	}

	
	if (dob1_day >= 29)
	{
		if (dob1_day == 29)
		{
			if (dob1_month == 2)
			{
				if (dob1_year % 4 != 0)
				{
					return -1;
				}
			}
		}

		if (dob1_day == 31)
		{
			if ((dob1_month == 4) || (dob1_month == 6) || (dob1_month == 9) || (dob1_month == 11))
			{
				return -1;
			}
		}

	}

	if (dob2_day >= 29)
	{
		if (dob2_day == 29)
		{
			if (dob2_month == 2)
			{
				if (dob2_year % 4 != 0)
				{
					return -1;
				}
			}
		}

		if (dob2_day == 31)
		{
			if ((dob2_month == 4) || (dob2_month == 6) || (dob2_month == 9) || (dob2_month == 11))
			{
				return -1;
			}
		}

	}

	if (dob1_year < dob2_year)
	{
		return 1;
	}
	else
	{
		if (dob2_year < dob1_year)
		{
			return 2;
		}
	}

	if (dob1_month < dob2_month)
	{
		return 1;
	}
	else
	{
		if (dob2_month < dob1_month)
		{
			return 2;
		}
	}


	if (dob1_day < dob2_day)
	{
		return 1;
	}
	else
	{
		if (dob2_day < dob1_day)
		{
			return 2;
		}
	}

	return 0;

}
