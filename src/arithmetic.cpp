#include "arithmetic.h"
#include <stdio.h>

#include "stack.h"

bool checkBrackets(std::string s)
{
	TStack<char> St;
	for (char i : s)
	{
		if (i == '(')
		{
			St.push('(');
		}
		if (i == ')')
		{
			if (St.isEmpty())
			{
				return false;
			}
			else
			{
				St.put();
			}
		}
	}
	if (St.isEmpty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int DType(char c)
{
	std::string operand = "+-*/";
	bool flag = false;

	if (isdigit(c))
	{
		return 1;
	}
	else if (isalpha(c))
	{
		return 2;
	}
	else if((c == '.') || (c == ','))
	{
		return 4;
	}
	else 
	{
		for (int i = 0; i < 4; i++)
		{
			if (c == operand[i])
			{
				flag = true;
				break;
			}
		}

		if(flag)
		{
			return 3;
		}
		else 
		{
			return 0;
		}
	}

}
bool checkOperands(std::string s)
{
	std::string operand = "-+*/";
	bool flag = false;
	for (int i = 1; i < 4; i++)
	{
		if (s[0] == operand[i])
		{
			flag = true;
			break;
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (s[s.length() - 1] == operand[i])
		{
			flag = true;
			break;
		}
	}
	if (flag==1)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool checkOper(std::string s)
{
	std::string operand = "-+*/";
	bool flag = false;
	for (int i = 0; i < s.length(); i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if (s[i] == operand[j])
			{
				for(int j = 0; j < 4; j++)
				{
					if (s[i+1] == operand[j])
					{
						flag = true;
						break;
					}
				}
				if (flag)
				{
					return false;
				}
			}
		}
	}
	return true;
}
bool checkAll(std::string s)
{
	if((checkBrackets(s)) && (operand_true_1(s)) && (checkOperands(s)) && (checkOper(s)))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void inPoint(std::string s)
{
	for (char& i : s)
	{
		if (DType(i)==4)
		{
			if (i == ',')
			{
				i = '.';
			}
		}
	}
}
int priority (char c)
{
	switch(c)
  {
	case '=' : return 0;
	case '(' : return 1;
	case '-' :
	case '+' : return 2;
	case '*' :
	case '/' : return(3);
	default: throw std::logic_error("");
	}
}
bool operand_true(char c) 
{
	if((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || 
		c == '.' || c == '+' || c == '-' || c == '*' || c == '/' || c =='(' || c == ')')
	{
		return true;
	}
	return false;
}
bool operand_true_1(std::string s)
{
	int n = 0;
	for (char i : s)
	{
		if (operand_true(i))
		{
			n++;
		}
	}
	if (n == s.length())
	{
		return true;
	}

	return false;
}
void inputVar (std::string s)
{
	int j = 0;
	char b[MaxSize];
	for (char i : s)
	{
		if(isalpha(i))
		{
			char a[MaxSize];
			gets_s(a);
			int len1 = strlen(a);
			for (int k = 0; k < len1; k++)
			{
				b[k] = a[k];
			}
			for (int k = 0; k < len1; k++)
			{
				a[k]=0;
			}
		}
		else
		{
			b[j++] = s[i];
		}
	}
	b[j] = '\0';
	for (int i = 0; i <= j; i++)
	{
		s[i] = b[i];
	}
}

void unarMinus(std::string s)
{
	std::string a;
	int j = 0;
	if (s[0]=='-')
	{
		a[j++]='0';
		a[j++]='-';
	}
	else
	{
		a[j++] = s[0];
	}
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == '-')
		{
			if((s[i - 1] == '(') && ((DType(s[i + 1]) == 1)||(DType(s[i + 1]) == 2)))
			{
				a[j++] = '0';
				a[j++] = '-';
			}
			else
			{
				a[j++] = '-';
			}
		}
		else
		{
			a[j]=s[i];
			j++;
		}
	}
	a[j] = '\0';
	for (char& c : s)
	{
		c = '0';
	}
	for (int i = 0;i <= j; i++)
	{
		s[i]=a[i];
	}
}
bool checkUnarMinus(std::string s)
{
	bool flag = false;
	if (s[0] == '-')
	{
		flag = true;
	}
	for(const char& c : s)
	{
		if (c == '-')
		{
			if((c == '(') && ((DType(c) == 1) || (DType(c) == 2)))
			{
				flag = true;
				break;
			}
		}
	}
	if (flag)
	{
		return true;
	}
}