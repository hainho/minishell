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
