#include "libft.h"

char	*ft_strjoin_range(char const *s1, char const *s2, int start, int end)
{
	char	*dst;
	char	*temp;
	int		n;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	dst = (char *)malloc(n * sizeof(char));
	if (dst == NULL)
		return (NULL);
	temp = dst;
	while (*s1)
		*temp++ = *s1++;
	i = start;
	while (s2[i] && i < end)
		*temp++ = s2[i++];
	*temp = 0;
	return (dst);
}

#include "libft.h"

char	*ft_strdup_range(const char *s1, int start, int end)
{
	int		size;
	char	*temp;
	char	*dst;
	int		i;

	size = ft_strlen(s1);
	dst = (char *)malloc((size + 1) * sizeof(char));
	if (dst == NULL || start < 0 || end > size)
		return (NULL);
	temp = dst;
	i = start;
	while (i < end)
		*temp++ = s1[i++];
	*temp = 0;
	return (dst);
}
