#include "libft.h"

char	*ft_strdup_range(const char *s1, int start, int end)
{
	int		size;
	char	*dst;
	int		i;

	size = ft_strlen(s1);
	if (start < 0 || end < 0 || start > size || end > size || start > end)
		return (NULL);
	size = end - start;
	dst = (char *)malloc((size + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		dst[i] = s1[i + start];
	dst[i] = 0;
	return (dst);
}
