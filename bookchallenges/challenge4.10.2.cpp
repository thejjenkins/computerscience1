for (i=0; i<simonPattern.size(); ++i)
{
	char x = simonPattern[i];
	for (int j=0; j<userPattern.size(); ++j)
	{
		char y = userPattern[j];
		if (y == x)
		{
			++userScore;
			break;
		}
		else
		{
			break;
		}
	}
}
