/*void check_convers(char *str, va_list *list_printf)
{
	int i;
	int verif;
	int precision;
	int width;

	i = 0;
	verif = 0;
	width = 0;
	precision = 0;

	while (str[i])
	{		
		if (str[i] == '-')
		{
			printf("[minus]\n");
			i++;
		}
		else if (str[i] == '0')
		{
			printf("[zero]\n");
			i++;
		}
		else if (str[i] == '*')
		{
			printf("[star]\n");
			i++;
		}

		else if (verif == 0 && str[i - 1] == '.' && ft_isdigit(str[i]) == 1)
		{
			verif = verif + 1;
			printf("[width]\n");
			while (ft_isdigit(str[i]) == 1)
				i++;
			//width
			i++;
		}

		else if (str[i - 1] == '.' && (str[i] == '*' || ft_isdigit(str[i]) == 1))
		{
			printf("[precision]\n");
			verif = verif + 1;
			while (ft_isdigit(str[i] == 1) || str[i] == '*')
				i++;
			//precision and size
			i++;
		}
		else
			i++;
	}
	if (verif == 0)
		printf("[Acune precise ni width]\n");
	if (verif == 2)
		printf("[precision and  width]\n");

	if ((str[strlen(str) - 1]) == 's')
		myprintf_s(list_printf);
	if ((str[strlen(str) - 1]) == 'c')
		myprintf_c(list_printf);
	if ((str[strlen(str) - 1]) == 'd')
		myprintf_d(list_printf);
	if ((str[strlen(str) - 1]) == 'i')
		myprintf_d(list_printf);
	if ((str[strlen(str) - 1]) == 'u')
		myprintf_u(list_printf);
}*/

//==============================================Appli conv=============================================
/*
void apply_diu(t_prtf *structprtf, va_list *list_printf)
{
	if (structprtf->flag == 'd')
	{
		myprintf_d(&list_printf, &structprtf);
	}
	if (structprtf->flag == 'i')
	{
		if (verif_mod(structprtf) == 1)
			myprintf_d(list_printf, &structprtf);
	}
	if (structprtf->flag == 'u')
	{
		if (verif_mod(structprtf) == 1)
			myprintf_u(list_printf, &structprtf);
	}
}

void apply_scp(t_prtf *structprtf, va_list *list_printf)
{
	if (structprtf->flag == 's')
		myprintf_s(list_printf, structprtf);

	if (structprtf->flag == 'c')
		myprintf_c(list_printf, structprtf);

	if (structprtf->flag == 'p')
		myprintf_p(list_printf, structprtf);
}

void apply_mod(t_prtf *structprtf, va_list *list_printf)
{
	if (structprtf->flag == 'c' || structprtf->flag == 's' || structprtf->flag == 'p')
	{
		apply_scp(structprtf, list_printf);
	}
	if (structprtf->flag == 'd' || structprtf->flag == 'i' || structprtf->flag == 'u')
	{
		apply_diu(structprtf, list_printf);
	}
}*/


/*
C S D I U xX P
0 	0 1  0 0 0 0 
64 32 16 8 4 2 1		
+ - . * 0
0 1 0 0 0

uint 
FLAG |= FLAGC

if (FLAG & FLAGC)
*/

/*
void	tabconv(char **tab, va_list *list_printf, t_prtf *structprtf)
{
	tab[0] = &myprintf_s(&list_printf, &structprtf);
	tab[1] = &myprintf_c(&list_printf, &structprtf);
	tab[2] = &myprintf_p(&list_printf, &structprtf);
	tab[3] = &myprintf_d(&list_printf, &structprtf);
	tab[4] = &myprintf_i(&list_printf, &structprtf);
	tab[5] = &myprintf_u(&list_printf, &structprtf);
	tab[6] = &myprintf_x(&list_printf, &structprtf);
	tab[7] = &myprintf_X(&list_printf, &structprtf);
	tab[8] = &myprintf_s(&list_printf, &structprtf);
	tab[9] = &myprintf_%(&list_printf, &structprtf);

}
*/


//==========================================================================================

/*if (structprtf->minus == 0)
			{
				if (ft_strlen(str) <= structprtf->precision)
					write(1, str, ft_strlen(str));
				else
				{
					print_recursiv(' ', ((structprtf->width) - ft_strlen(str)));
					write(1, str, structprtf->precision);
				}
			}
			if (structprtf->minus == 1)
			{
				if (ft_strlen(str) <= structprtf->precision)
					write(1, str, ft_strlen(str));
				else
				{
					write(1, str, structprtf->precision);
					print_recursiv(' ', ((structprtf->width) - ft_strlen(str)));
				}
			}
			*/
