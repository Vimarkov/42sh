# libftreadline
Line editing library for 42 projects

This is a small C library that implements 2 functions:

- `ft_readline()` reads a line from <b>stdin</b> with editing functionalities
- `ft_confirm()` displays a message and asks for user confirmation

It uses termcaps and passes norminette, so it can be used for 42 projects.

# Compiling

To compile your project with libftreadline, ensure your Makefile compiles the lib before. Because it is a static library, it is not required to be alongside your compiled binary.

You must add these flags to the linker:<br/>
`-L/path/to/libft -L/path/to/libftreadline -lftreadline -lft -ltermcap`

# Manpages
The lib includes manpages for each function.
To view them with `man(1)`, you can issue (assuming `$PWD` is the repo dir):<br/>
`$> man -M man ft_readline`<br/>
or<br/>
`$> man -M man ft_confirm`<br/>
or even<br/>
`$> man -M man libftreadline`<br/>

If you want to view them all in a row, issue:<br/>
`$> man man/man3/*`

# Autocompletion
`ft_readline()` has its own autocompletion routine. It calls 2 functions passed
in the func ptrs in the `t_rl_opts` struct. If a ptr is `NULL`, `ft_readline()` will use
its builtin version.

By default, `ft_readline()` will search the current directory or the directory in the line
for similar starting entries. If there are multiple entries, `ft_readline()` displays the list.

# History
`ft_readline()` can browse a line history, via the third argument you pass to it.
It is your resposability to create the ptr, add the returned lines to the history via the lib functions, pass it to `ft_readline()` and free it when you're done with it.

# Copy/Cut/Paste
`ft_readline()` has a copy/cut/paste feature. By using the Shift+Left or Shift+Right keys, you can select text. With Shift+Up you can copy or cut if you double-press it.
With Shift+Down, you paste the copied text. If nothing is copied, nothing happens.

# Bell
When a key fails, but not because of an internal error, `ft_readline()` makes the terminal ring a bell.

# Dumb mode
`ft_readline()` implements a \`\`dumb mode''. It is used when the terminal is not
known to provide line-editing. In dumb mode, there is only one line that flicks
through multiples \`\`pages''. Copy/Cut/Paste, history and autocompletion features
are still available although with some limitations:

- No bell suppport.
- When scrolling thru history, lines containing the `\n`character will be ignored.
- `ac_show_result` func ptr is ignored. Use `ac_show_result_dumb` instead.
- Copy/Paste selection is made by making the characters uppercase (the copied characters are untouched of course).
- Your prompt's _xterm_ colors are automatically disabled. If the shell is too small, \`\`$> '' is used instead.

# Considerations
If `line` is `NULL`, the function will _segv_ on press of the return key.
The `t_rl_opts` struct is optional. Passing `NULL` will make `ft_readline()` allocate the struct and set default values.
