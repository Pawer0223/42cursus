#include "../../headers/printf.h"

void		all_print()
{
	t_printf_print();
	t_input_print();
}

void		t_printf_print()
{
	printf("\n\n ################# Printf ############# \n");
	printf("length : [%s], ", g_info->length);
	printf("flag : [%c], ", g_info->flag);
	printf("specifier : [%c], ", g_info->specifier);
	printf("width : [%d], ", g_info->width);
	printf("precision_len : [%d] \n", g_info->precision_len);
	printf("################# Printf End############# \n");
}

void		t_input_print()
{
	t_input *input = g_info->input;

	if (!input)
	{
		printf("input is not init\n");
		return;
	}
	printf("\n\n ################# Input ############# \n");
	printf("str : [%s], ", input->str);
	printf("sign : [%c], ", input->sign);
	printf("len : [%d]\n", input->len);
	printf("################# Input End############# \n");

}