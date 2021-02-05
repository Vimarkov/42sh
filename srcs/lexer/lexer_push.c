/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdumarai <kdumarai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 16:13:18 by kdumarai          #+#    #+#             */
/*   Updated: 2018/08/15 20:05:26 by kdumarai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_lexer.h"

inline static t_quoting	detect_quote(char *s, t_quoting curr)
{
	if (*s == '\\'
		&& ((curr == kDQuote && (s[1] == '$' || s[1] == '"' || s[1] == '\\'))
			|| (curr != kDQuote && s[1])))
		return (kEscape);
	if (*s == '"' && curr != kSQuote)
		return ((curr == kDQuote) ? kQuoteNone : kDQuote);
	if (*s == '\'' && curr != kDQuote)
		return ((curr == kSQuote) ? kQuoteNone : kSQuote);
	return (curr);
}

static int				cpy_string_norm(t_quoting *curr, t_quoting *old,
		t_str *vs, char *s)
{
	if (*curr == kEscape)
	{
		if ((s[1] == '"' || s[1] == '\'' || s[1] == '$')
			&& !ft_tstrncat(vs, ++s, 1))
			return (-1);
		*curr = *old;
	}
	return (0);
}

static int				cpy_string(char *s, t_str *vs, t_list **ret)
{
	t_quoting		curr;
	t_quoting		old;
	int				rval;

	old = kQuoteNone;
	curr = kQuoteNone;
	rval = FALSE;
	while (*s)
	{
		if ((curr = detect_quote(s, curr)) != kQuoteNone && curr != kEscape)
			rval = TRUE;
		if (curr == old && !(*s == '$' && curr != kSQuote
			&& lexer_expand_var(&s, vs, ret, curr)) && !ft_tstrncat(vs, s, 1))
			return (-1);
		if (cpy_string_norm(&curr, &old, vs, s))
			return (-1);
		old = curr;
		s++;
	}
	if (!rval && start_checking_globing(ret, vs->s))
		ft_tstrclr(vs);
	return (rval);
}

static t_uint8			get_tokens_strings(t_list **ret, char *s)
{
	t_list			*new;
	t_str			vs;
	int				cpy_rval;

	if (!ft_tstrnew(&vs))
		return (FALSE);
	*ret = NULL;
	if (!lexer_expand_tilde(&s, &vs))
	{
		ft_tstrdel(&vs);
		return (FALSE);
	}
	new = NULL;
	if ((cpy_rval = cpy_string(s, &vs, ret)) == -1
		|| ((*vs.s || cpy_rval) && !(new = ft_lstnew(vs.s, vs.len + 1))))
	{
		ft_lstdel(ret, &ft_lstnodefree);
		return (FALSE);
	}
	else if (new && (*vs.s || cpy_rval))
		ft_lstpush(ret, new);
	ft_tstrdel(&vs);
	return (TRUE);
}

t_uint8					add_token(t_dlist **tokens,
								t_str *vs,
								t_toktype type)
{
	t_dlist	*newtok;
	t_token	tokdat;
	t_list	*tokstrs;
	t_list	*toksbw;

	if (!vs || vs->len < 1)
		return (TRUE);
	tokstrs = NULL;
	if ((type == WORD && !get_tokens_strings(&tokstrs, vs->s))
		|| (type != WORD && !(tokstrs = ft_lstnew(vs->s, vs->len + 1))))
		return (FALSE);
	toksbw = tokstrs;
	while (toksbw)
	{
		ft_bzero(&tokdat, sizeof(t_token));
		tokdat.s = (char*)toksbw->content;
		tokdat.type = type;
		if (!(newtok = ft_dlstnew(&tokdat, sizeof(t_token))))
			return (FALSE);
		ft_dlstpush(tokens, newtok);
		toksbw = toksbw->next;
	}
	ft_lstdel(&tokstrs, NULL);
	ft_tstrclr(vs);
	return (TRUE);
}
