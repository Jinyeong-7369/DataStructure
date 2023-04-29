int Reverse(char s[], int size)
{
	if (size == 0) return 0;

	
	cout << s[size - 1];
	return Reverse(s, size - 1);
	
}