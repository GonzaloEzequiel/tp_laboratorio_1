
int suma(float* num1, float* num2, float* res, int flags)
{
    int error = 0;

    if(flags)
    {
		*res = *num1 + *num2;
    }
    else
    {
    	error = 1;
    }

    return error;
}

int resta(float* num1, float* num2, float* res, int flags)
{
    int error = 0;

    if(flags)
	{
		*res = *num1 - *num2;
	}
	else
	{
		error = 1;
	}

    return error;
}

int producto(float* num1, float* num2, float* res, int flags)
{
	int error = 0;

	if(flags)
	{
		*res = *num1 * *num2;
	}
	else
	{
		error = 1;
	}

	return error;
}

int division(float* num1, float* num2, float* res, int flags)
{
	int error = 0;

	if(flags && *num2)
	{
		*res = *num1 / *num2;
	}
	else
	{
		error = 1;
	}

	return error;
}

int factorial(float* num, long long int* res, int flag)
{
	int error = 0;
	long long int fact = 1;

	if(flag && *num > 0)
	{
		for(int i = *num; i > 0; i--)
		{
			fact *= i;
		}
	}
	else
	{
		error = 1;
	}

	*res = fact;

    return error;
}
