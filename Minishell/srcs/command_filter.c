#include "../includes/minishell.h"

// char	*list_to_string(t_list *list)
// {
// 	t_list	*temp;
// 	char	*str;
// 	int		len;
// 	int		i;
// 	int		j;

// 	temp = list;
// 	len = 0;
// 	while (temp)
// 	{
// 		printf("temp->content : [%s]\n", (char *)temp->content);
// 		len += ft_strlen((char *)temp->content);
// 		temp = temp->next;
// 	}
// 	str = (char *)malloc(sizeof(char *) * (len + 1));
// 	if (str)
// 	{
// 		str[len] = 0;
// 		i = 0;
// 		temp = list;
// 		while (temp)
// 		{
// 			j = 0;
// 			while (((char *)(temp->content))[j])
// 				str[i++] = ((char *)(temp->content))[j++];
// 			temp = temp->next;
// 		}
// 	}
// 	return (str);
// }

// // 앞 뒤로 자르기..
// int	make_param(t_info *info, char *input, int len)
// {
// 	int		i;
// 	int		s;
// 	int		cnt;
// 	t_list	*list;
// 	t_list	*data;
// 	t_list	*temp_list;
// 	char	*content;

// 	list = 0;
// 	cnt = 0;
// 	i = 0;
// 	temp_list = 0;
// 	// 1. 앞에있는 스페이스 뛰어넘기.
// 	while (input[i] && input[i] == ' ')
// 		i++;
// 	content = 0;
// 	s = i;
// 	while (i < len && input[i])
// 	{
// 		//abcd
// 		//"a""b"

// 		// 따옴표 일때 처리하기.
// 		if (i < len && is_quotation(input[i]))
// 		{
// 			char c = input[i];
// 			// a="bcd";
// 			// 0123456

// 			// a=까지 자르고
// 			char *front = ft_substr(input + s, 0, i - s);
// 			i++;
// 			// "버리고 b부터 "닫힐때까지
// 			s = i;
// 			// i를 움직여 준다.
// 			// i는 닫힌 "에서 멈춘다.
// 			while (i < len && input[i] != c)
// 				i++;
// 			// 일단 거기까지 뽑는다. content는 임시변수로 사용 됨.
// 			char *back = ft_substr(input + s, 0, i - s);
// 			char *temp = ft_strjoin(front, back);
// 			ft_free(front);
// 			ft_free(back);
// 			// 닫힌 " 버리기
// 			s = i + 1;
// 			//printf("temp : [%s]\n", temp);
// 			data = ft_lstnew(temp);
// 			ft_lstadd_back(&temp_list, data);
// 		}
// 		// 중간에 ' ' 만난경우에는
// 		else if (i < len && input[i] == ' ')
// 		{
// 			// export a="bcd"
// 			// 01234567890123
// 			// 만약 temp가 채워져 있다면.
// 			if (temp_list)
// 			{
// 				char *front = list_to_string(temp_list);
// 				ft_lstclear(&temp_list, ft_free);
// 				char *back = ft_substr(input + s, 0, i - s);
// 				content = ft_strjoin(front, back);

// 				ft_free(front);
// 				ft_free(back);
// 				// // 문자열을 이어서 붙여준다.
// 				// temp2 = ft_substr(input + s, 0, i - s);
// 				// content = ft_strjoin(temp, temp2);
// 				// ft_free(temp);
// 				// ft_free(temp2);
// 			}
// 			else
// 				content = ft_substr(input + s, 0, i - s);
// 			// substr하고 이후에 연속 된 ' '를 처리한다.
// 			// 이 때 i는 다음 문자가 시작되는 곳이다.
// 			// 따라서 다음 문자가 시작되는 곳을 start로 변경한다.
// 			// 그리고 i값은 아래애서 i++되기때문에 하나를 빼준다.
// 			while (i < len && input[i] == ' ')
// 				i++;
// 			s = i--;

// 			// 이어 붙이기
// 			data = ft_lstnew(content);
// 			ft_lstadd_back(&list, data);
// 			cnt++;
// 			content = 0;
// 		}
// 		i++;
// 	}
// 	if (temp_list)
// 	{
// 		char *front = list_to_string(temp_list);
// 		ft_lstclear(&temp_list, ft_free);
// 		char *back = ft_substr(input + s, 0, i - s);
// 		content = ft_strjoin(front, back);

// 		ft_free(front);
// 		ft_free(back);
// 	}
// 	else
// 		content = ft_substr(input + s, 0, i - s);
// 	data = ft_lstnew(content);
// 	ft_lstadd_back(&list, data);
// 	cnt++;

// 	char **param = (char **)malloc(sizeof(char *) * (cnt + 1));
// 	if (!param)
// 		return (0);
// 	printf("cnt : [%d]\n", cnt);
// 	param[cnt] = 0;
// 	i = 0;
// 	while (list && i < cnt)
// 	{
// 		param[i++] = (char *)list->content;
// 		list = list->next;
// 	}
// 	i = 0;
// 	while (param[i])
// 	{
// 		printf("param : [%d] : [%s]\n", i, param[i]);
// 		i++;
// 	}
// 	info->param = param;
// 	return (1);
// }

int		quote_filter(t_info *info, char **input, int s, int *e)
{
	int		dollar_idx;
	char	is_db_q;

	is_db_q = (*input)[s];
	if (is_db_q == DOUBLE_Q)
	{
		dollar_idx = exist_dollar(*input, s, *e);
		if (dollar_idx)
		{
			if(!replace_env(info->envp, input, dollar_idx, e))
				return (0);
		}
	}
	return (1);
}

int	filter_input(t_info *info, char **input, int len)
{
	int		s;
	int		e;

	e = 0;
	while (e < len && (*input)[e])
	{
		if (is_quotation((*input)[e]))
		{
			s = e++;
			while ((*input)[e] && (*input)[e] != (*input)[s])
				e++;
			if (e < len && (*input)[s] == (*input)[e])
			{
				if (!quote_filter(info, input, s, &e))
					return (0);
			}
		}
		else if ((*input)[e] == DOLLAR)
		{
			if (!replace_env(info->envp, input, e, &e))
				return (0);
			len = ft_strlen(*input);
		}
		e++;
	}
	return (1);
}

int	command_filter(t_info *info, char **content)
{
	char	*new_input;
	int		len;
	int		r;

	len = ft_strlen((char *)(*content));
	if (!filter_input(info, content, len))
		return (error_occur_std(FILTER_INPUT_ERR));
	len = ft_strlen((char *)(*content));
	r =  make_param(info, *content, len);
	ft_lstclear(&info->param_list, content_not_rm);
	ft_lstclear(&info->temp_list, ft_free);
	return (r);
}