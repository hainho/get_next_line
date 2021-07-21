#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_strdup(char *s)
{
	int		len;
	char	*temp;
	char	*dst;

	len = ft_strlen(s);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	temp = dst;
	while (len--)
		*temp++ = *s++;
	*temp = '\0';
	return(dst);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*join_str;
	char	*temp;
	int 	len;
	int		idx;


	if (!(str1) && !(str2))
		return (NULL);
	if (!(str1) || !(str2))
		return (!(str1) ? ft_strdup(str2) : ft_strdup(str1));
	idx = 0;
	len = ft_strlen(str1);
	len += ft_strlen(str2);
	join_str = (char *)malloc(sizeof(char) * (len + 1));
	temp = join_str;
	if (join_str == NULL)
		return NULL;
	while (str1[idx])
		*temp++ = str1[idx++];
	idx = 0;
	while (str2[idx])
		*temp++ = str2[idx++];
	*temp = '\0';
	free(str1);
	return (join_str);
}