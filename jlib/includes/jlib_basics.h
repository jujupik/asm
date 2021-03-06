/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jlib_basics.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <jrouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:39:21 by jrouchon          #+#    #+#             */
/*   Updated: 2020/03/08 20:53:46 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JLIB_BASICS_H
# define JLIB_BASICS_H

int					get_next_line(int fd, char **line);
int					open_fd(char *path, int mode);
void				close_fd(int fd);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t len);
void				*ft_memcpy(void *dest, void *src, size_t len);
void				*ft_memccpy(void *dest, void *src, int c, size_t len);
void				*ft_memmove(void *dest, void *src, size_t len);
void				*ft_memchr(void *str, int c, size_t len);
int					ft_memcmp(void *s1, void *s2, size_t len);
size_t				ft_strlen(char *str);
char				*ft_strdup(char *src);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
void				ft_strcat(char *dest, char *src);
void				ft_strncat(char *dest, char *src, size_t n);
size_t				ft_strlcat(char *dst, char *src, size_t size);
BOOL				ft_strschr(char *s, char *model);
char				*ft_strrchr(char *str, char c);
char				*ft_strstr(char *str, char *find);
char				*ft_strnstr(char *str, char *find, size_t len);
BOOL				ft_strcmp(char *s1, char *s2);
BOOL				ft_strncmp(char *s1, char *s2, size_t n);
int					ft_atoi(char *str);
BOOL				ft_isalpha(int c);
BOOL				ft_isdigit(int c);
BOOL				ft_isalnum(int c);
BOOL				ft_isascii(int c);
BOOL				ft_isprint(int c);
BOOL				ft_isnum(int c);
BOOL				ft_strisalpha(char *str);
BOOL				ft_strisdigit(char *str);
BOOL				ft_strisalnum(char *str);
BOOL				ft_strisascii(char *str);
BOOL				ft_strisprint(char *str);
BOOL				ft_strisnum(char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void(*f)(unsigned int, char *));
char				*ft_strmap(char *s, char (*f)(char));
char				*ft_strmapi(char *s, char (*f)(unsigned int, char));
int					ft_strequ(char *s1, char *s2);
int					ft_strnequ(char *s1, char *s2, size_t n);
char				*ft_strsub(char *s, unsigned int start, size_t len);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strtrim(char *s);
char				**ft_strsplit(char *s, char c);
char				*ft_itoa(long long n);
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_putendl(char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				error_exit(int nb, char *str);
size_t				ft_tab_len(char **tab);
void				ft_tab_free(char **tab);
char				**ft_tab_new(size_t len);
char				**ft_tabdup(char **tab);
int					*ft_intparse_tab(char **tab);
int					**ft_inttab_new(int size);
int					*ft_int_str_new(int size);
void				ft_inttab_cpy(int **dest, int **src);
void				ft_puttab(char **tab);
void				ft_putinttab(int **tab, int len);
int					ft_abs(int src);
void				ft_swap_int(int *a, int *b);
void				ft_swap_float(float *a, float *b);
int					ft_min(int nb_number, ...);
int					ft_max(int nb_number, ...);
int					ft_strncchr(char *str, char c);
BOOL				ft_strcchr(char *str, char c);
char				*ft_strcut(char **src, char delim);
int					nbr_len(long long n, int base);
void				ft_str_replace_front(char *s2, char **s1);
void				ft_str_replace_back(char **s1, char *s2);
void				ft_target_strncat(char *s1, char *s2,
						size_t start, size_t len);
void				ft_str_toupper(char *str);
void				ft_str_fill(char *str, char c, size_t size);
char				*ft_strnew_c(size_t len, char c);
char				*ft_itoa_base(long long n, int base);
char				*ft_uitoa_base(unsigned long long n, int base);
char				*ft_uitoa(unsigned long long n);
void				ft_str_replace_front(char *s2, char **s1);
void				ft_str_replace_back(char **s1, char *s2);
void				ft_delchar(char **str, char *to_remove);
void				ft_delchar_begin(char **str, char *to_remove);
void				ft_changechar(char *str, char *target, char c);
BOOL				is_only_compose(char *src, char c);
BOOL				is_str_only_compose(char *src, char *delim);
BOOL				ft_strisdigit(char *str);
char				*convert_int_str(long long value, size_t len);
void				write_int(long long value, size_t len);
char				**ft_strsplit_emptyspace(char *s, char c);
char				**ft_strsplit_first(char *s, char c);
FILE_STATE			check_file_exist(char *path);
void				remove_file(char *path);

#endif
