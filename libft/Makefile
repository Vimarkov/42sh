# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/04 06:10:18 by kdumarai          #+#    #+#              #
#    Updated: 2018/08/16 05:35:52 by kdumarai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

INCDIR = includes
INCFILES = libft.h \
			btree.h \
			char.h \
			file.h \
			ft_int.h \
			get_next_line.h \
			list.h \
			mem.h \
			misc.h \
			nbr.h \
			print.h \
			str.h \
			t_str.h \
			t_tab.h \
			viclucas.h \
			read_libft.h \
			wordtab.h
INCLUDES = $(addprefix $(INCDIR)/, $(INCFILES))

SRCDIR = srcs
SRCFILES = get_next_line.c \
	mem/ft_bzero.c \
	mem/ft_memalloc.c \
	mem/ft_memccpy.c \
	mem/ft_memchr.c \
	mem/ft_memcmp.c \
	mem/ft_memcpy.c \
	mem/ft_memdel.c \
	mem/ft_memmove.c \
	mem/ft_memset.c \
	list/ft_lstnew.c \
	list/ft_lstnewom.c \
	list/ft_lstnew_nomalloc.c \
	list/ft_lstadd.c \
	list/ft_lstpush.c \
	list/ft_lstdel.c \
	list/ft_lstdelone.c \
	list/ft_lstiter.c \
	list/ft_lstmap.c \
	list/ft_lstlen.c \
	list/ft_lstnnext.c \
	list/ft_lstbubblesort.c \
	list/ft_lstmergesort.c \
	list/ft_lstinssort.c \
	list/ft_ltot.c \
	list/ft_lstnodefree.c \
	list/ft_dlstnew.c \
	list/ft_dlstadd.c \
	list/ft_dlstpush.c \
	list/ft_dlstdel.c \
	list/ft_dlstdelone.c \
	list/ft_dlstlen.c \
	list/ft_dlstnnext.c \
	btree/ft_btnew.c \
	btree/ft_btattach.c \
	btree/ft_btdelone.c \
	btree/ft_btdel.c \
	nbr/ft_nbrlen.c \
	nbr/ft_nbrlen_base.c \
	nbr/ft_nbrcpy.c \
	nbr/ft_nbrcat.c \
	nbr/ft_atoi.c \
	nbr/ft_secatoi.c \
	nbr/ft_itoa.c \
	nbr/ft_lltoa.c \
	print/ft_putchar.c \
	print/ft_putchar_fd.c \
	print/ft_putnchar.c \
	print/ft_putnchar_fd.c \
	print/ft_putendl.c \
	print/ft_putendl_color.c \
	print/ft_putendl_color_fd.c \
	print/ft_putendlmax.c \
	print/ft_putendlmax_fd.c \
	print/ft_putendl_fd.c \
	print/ft_putendlsec.c \
	print/ft_putendlsec_fd.c \
	print/ft_putlst.c \
	print/ft_putlst_fd.c \
	print/ft_putnbr.c \
	print/ft_putnbr_fd.c \
	print/ft_putnbrl.c \
	print/ft_putnbrl_fd.c \
	print/ft_putstr.c \
	print/ft_putstrmax.c \
	print/ft_putstrmax_fd.c \
	print/ft_putstrsec.c \
	print/ft_putstrsec_fd.c \
	print/ft_putstr_color.c \
	print/ft_putstr_color_fd.c \
	print/ft_putstr_fd.c \
	print/ft_puttab.c \
	print/ft_puttab_fd.c \
	print/ft_putnbr_ll.c \
	print/ft_putnbr_ll_fd.c \
	print/ft_putubt.c \
	misc/ft_readfd.c \
	misc/ft_returnmsg.c \
	misc/ft_isatty.c \
	misc/ft_switch.c \
	misc/ft_args_opts.c \
	string/ft_strcat.c \
	string/ft_strchr.c \
	string/ft_strpbrk.c \
	string/ft_strclr.c \
	string/ft_strcmpi.c \
	string/ft_strchrf.c \
	string/ft_strcmp.c \
	string/ft_strcpy.c \
	string/ft_strdel.c \
	string/ft_strdup.c \
	string/ft_strndup.c \
	string/ft_strequ.c \
	string/ft_striter.c \
	string/ft_striteri.c \
	string/ft_strjoin.c \
	string/ft_strnjoin.c \
	string/ft_stradd.c \
	string/ft_strnadd.c \
	string/ft_strisnumeric.c \
	string/ft_strlcat.c \
	string/ft_strlen.c \
	string/ft_strclen.c \
	string/ft_strmap.c \
	string/ft_strmapi.c \
	string/ft_strncat.c \
	string/ft_strncmp.c \
	string/ft_strncpy.c \
	string/ft_strnequ.c \
	string/ft_strnew.c \
	string/ft_strnew_replace.c \
	string/ft_strnstr.c \
	string/ft_strrchr.c \
	string/ft_strstart.c \
	string/ft_strdiff.c \
	string/ft_strsplit.c \
	string/ft_strsplit_charset.c \
	string/ft_strrmc.c \
	string/ft_strstr.c \
	string/ft_strsub.c \
	string/ft_strtrim.c \
	string/get_last_component.c \
	char/ft_tolower.c \
	char/ft_toupper.c \
	char/ft_isalnum.c \
	char/ft_isalpha.c \
	char/ft_isascii.c \
	char/ft_isdigit.c \
	char/ft_islower.c \
	char/ft_isprint.c \
	char/ft_isupper.c \
	wordtab/ft_tabnew.c \
	wordtab/ft_tabfree.c \
	wordtab/ft_tabjoin.c \
	wordtab/ft_tabaddstr.c \
	wordtab/ft_tabadd.c \
	wordtab/ft_tabdup.c \
	wordtab/ft_tablen.c \
	wordtab/ft_tabsort.c \
	t_str/ft_tstrnew.c \
	t_str/ft_tstrnew_cpy.c \
	t_str/ft_tstrdel.c \
	t_str/ft_tstrclr.c \
	t_str/ft_tstrcpy.c \
	t_str/ft_tstr_cpycore.c \
	t_str/ft_tstrncpy.c \
	t_str/ft_tstrcat.c \
	t_str/ft_tstrncat.c \
	t_str/tstrcpy_core.c \
	t_str/tstrcat_core.c \
	t_tab/ft_ttabnew.c \
	t_tab/ft_ttabnew_cpy.c \
	t_tab/ft_ttabcat.c \
	t_tab/ft_ttabdel.c \
	file/get_name_from_path.c \
	file/get_name_from_path_2.c \
	file/get_basedir.c \
	file/get_elem_path.c \
	viclucas/ft_access.c \
	viclucas/ft_error.c \
	viclucas/ft_free_db_tab.c \
	viclucas/ft_free_thoses.c \
	viclucas/ft_quotes_check.c \
	viclucas/ft_souder.c \
	viclucas/print_db.c \
	read_libft/ft_format_internal.c \
	read_libft/ft_format.c \
	read_libft/ft_ntsarr_new.c \
	read_libft/ft_ntsarr_push.c \
	read_libft/ft_ntsarr_app.c \
	read_libft/ft_ntsarr_len.c \
	read_libft/ft_ntsarr_free.c \
	read_libft/ft_ntsarr_print.c \
	read_libft/ft_put.c \
	read_libft/ft_strapp.c \
	read_libft/ft_strappf.c \
	read_libft/ft_strappc.c \
	read_libft/ft_strappcf.c \
	read_libft/ft_gnl.c \
	read_libft/ft_readsplit.c \
	read_libft/ft_strlenp.c
SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))

NSRC = $(shell echo "$(SRCS)" | awk '{print NF}')
ifeq ($(shell [ ! -z "`which bc`" ] && [ ! -z "`which awk`" ] && echo true),true)
	CSRC = 1
else
	CSRC = 0
endif

OBJDIR = objs
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

PROJTEXT = \033[1;34mlibft: \033[0;39m

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	@ printf "\033[K$(PROJTEXT)Compiling\n"
	@ printf "$(PROJTEXT)Linking\n"
	@ ar rcs $(NAME) $?
	@ printf "$(PROJTEXT)\033[1;32mLib built at $(NAME)\033[0;39m\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES)
	@ if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	@ printf "\033[K$(PROJTEXT)Compiling \033[1;33m$<"
ifneq ($(CSRC),0)
	@ printf " %.0s" {1..$(shell expr 40 - $(shell printf "$<" | wc -m))}
	@ export LC_ALL=C; printf "\033[1;34m[%3.0f%%]" "$(shell bc <<< "scale=1; $(CSRC) / $(NSRC) * 100")"
	@ $(eval CSRC = $(shell expr $(CSRC) + 1))
endif
	@ printf "\033[0;39m\r"
	@ gcc $(CFLAGS) -I includes -c $< -o $@

clean:
	@ rm -f $(OBJS)
	@ printf "$(PROJTEXT)Removed objects\n"

fclean: clean
	@ rm -f $(NAME)
	@ printf "$(PROJTEXT)Removed $(NAME)\n"

re: fclean all

.PHONY: all clean fclean re
