#include "get_next_line.h"

char    *read_file(int fd, char *saved)
{
    char    *buffer;
    ssize_t read_bytes;
    size_t  i;

    i = 0;
    buffer = malloc (BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    read_bytes = read (fd, buffer, BUFFER_SIZE);
    if (read_bytes > 0)
        buffer[read_bytes] = '\0';
    if (read_bytes == -1)
    {
        free(buffer);
        free()
    }
    buffer = ft_strjoin (saved, buffer);
    while (buffer[i] && read_bytes != 0 && ft_strchr(buffer, '\n') == NULL)
    {
        i++;
    }
    return (buffer);




}