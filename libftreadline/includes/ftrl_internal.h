/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftrl_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:46:30 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/15 14:35:21 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTRL_INTERNAL_H
# define FTRL_INTERNAL_H

# include "libftreadline.h"
# include "ftrl_termcap.h"
# include "ftrl_dev.h"
# include <termios.h>
# include <sys/ioctl.h>

/*
** Macros
*/

# define DFL_LINEBUFFSIZE	10
# define RL_READBUFFSIZE	6
# define TERMCAPS_DFL_FD	STDIN_FILENO

/*
** ANSI Sequences Codes
*/

# define ESC_BACKSPACE		"\177"
# define ESC_SHIFTL			"\033[1;2D"
# define ESC_SHIFTR			"\033[1;2C"
# define ESC_SHIFTU			"\033[1;2A"
# define ESC_SHIFTD			"\033[1;2B"
# define ESC_ALTU			"\033\033[A"
# define ESC_ALTD			"\033\033[B"
# define ESC_MOVL			"\033b"
# define ESC_MOVR			"\033f"
# define ESC_CTRLL			"\014"

/*
** cpy/paste structs
*/

typedef struct	s_cpypste
{
	char			*dat;
	unsigned long	mkrs[2];
	t_uint8			idx;
	t_uint8			cpyed;
	char			reserved_pad[6];
}				t_cpypste;

/*
** quit functions data
*/

typedef enum	e_abort
{
	kAbortNone,
	kAbortQuit,
	kAbortReload,
	kAbortClear
}				t_abort;

typedef struct	s_quit
{
	void			(*func)(void *);
	void			*func_data;
	void			(*free_func)(void *);
	t_abort			reason;
	char			reserved_pad[4];
}				t_quit;

/*
** struct for moving around data
*/

typedef struct	s_readline
{
	t_rl_opts		*opts;
	char			*prompt;
	const char		*origpr;
	size_t			prlen;
	char			*line;
	size_t			bufflen;
	t_mov			movs;
	t_keys			keys;
	t_cpypste		cpypste;
	t_cursor		csr;
	unsigned long	min_y;
	unsigned long	max_y;
	unsigned long	prefered_x;
	t_quit			quit;
	int				ret;
	t_uint8			dumb;
	t_uint8			heap_opts;
	char			reserved_pad[2];
}				t_readline;

/*
** some enums
*/

typedef enum	e_keyact
{
	kKeyNone,
	kKeyOK,
	kKeyFail,
	kKeyFatal
}				t_keyact;

typedef enum	e_direct
{
	kDirectLeft,
	kDirectRight
}				t_direct;

/*
** line edit (keys)
*/

t_keyact		rl_input_add_text(char *buff, t_readline *rl);
t_keyact		rl_input_rm_text(char *buff, t_readline *rl);
t_keyact		rl_clear_line(t_readline *rl);
t_keyact		rl_eof_key(t_readline *rl);

t_keyact		rl_clscr_key(t_readline *rl);

/*
** line edit (sys)
*/

t_uint8			rl_line_rm(size_t len, t_readline *rl);
t_uint8			rl_line_add(char *add, t_readline *rl);

/*
** line buffer
*/

t_uint8			rl_linebuff_create(t_readline *rl);
int				rl_linebuff_rm(size_t len, t_readline *rl);
int				rl_linebuff_add(char *add, size_t addlen, t_readline *rl);

/*
** cursor motion (left/right - home/end - alt+left/alt+right)
*/

t_keyact		rl_right_key(t_readline *rl);
t_keyact		rl_left_key(t_readline *rl);
t_keyact		rl_home_key(t_readline *rl);
t_keyact		rl_end_key(t_readline *rl);

t_keyact		rl_movl_key(t_readline *rl);
t_keyact		rl_movr_key(t_readline *rl);

t_keyact		rl_moveline_up(t_readline *rl);
t_keyact		rl_moveline_down(t_readline *rl);

/*
** navigation funcs
*/

void			get_line_info_for_pos(t_point *pt, unsigned long pos,
									t_readline *rl);
void			get_line_info(t_point *pt, t_readline *rl);

void			go_to_pos(unsigned long to, unsigned long from, t_readline *rl);
void			go_to_point(unsigned long idx,
							t_point *to,
							t_point *from,
							t_readline *rl);

/*
** copy/paste
*/

t_keyact		rl_paste_key(t_readline *rl);
t_keyact		rl_cpy_key(t_readline *rl);
t_keyact		rl_rightcpy_key(t_readline *rl);
t_keyact		rl_leftcpy_key(t_readline *rl);

/*
** csr keys utils
*/

t_uint8			check_height(t_point *gtc, t_readline *rl);
void			check_selection(t_readline *rl);

/*
** autocompletion
*/

t_keyact		rl_acroutine(t_readline *rl);
t_list			*search_files_begin(const char *f_path, char *s_dir,
									int exec);

/*
** history
*/

t_keyact		hist_nav(char *buff, t_readline *rl, t_dlist **hist);

/*
** dumb mode
*/

void			rl_erase_dumb_line(void);

/*
** terminal
*/

void			tcaps_set_extern(struct termios *pterm);
int				rl_set_term(t_uint8 echo);
t_uint8			rl_set_timeout(t_uint8 enable, cc_t timeout);

/*
** init
*/

t_uint8			rl_prompt_init(char **dest, size_t *len, t_readline *rl);
void			rl_deinit(t_readline *rl);
t_uint8			rl_init(t_readline *rl, const char *prompt, t_rl_opts *opts);

/*
** signals
*/

void			set_signals(void);
void			restore_signals(void);

/*
** quit functions
*/

t_uint8			quit_with_reason(t_abort reason,
								void (*func)(void *),
								void *data,
								void (*free_func)(void *));

/*
** utils
*/

char			*ft_prompt_nocolor(const char *prompt);
size_t			ft_prompt_len(const char *s);

t_readline		*rl_latest_session(t_uint8 set, t_readline *new_session);

#endif
