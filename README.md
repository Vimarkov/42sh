# 42sh

Co created with viclucas kdumarais.

Mandatory part:
* Prompt without line edition.
* Builtins `cd`, `echo`, `exit`, `env`, `setenv`, `unsetenv` with there options.
* Executing simple commands with there parameters using `PATH`.
* Support for redirection `>`, `>>`, `<` and `|`.
* Logical operand `&&`and `||`.
* Separator `;`.

Optional feature (five of theses are mandatory to validate the project):

* Inhibitors `"`, `'`and `\`.
* Advanced redirections: aggregation of file output and heredoc `<<`.
* Globbing: `*`, `?`, `[]`, `{}`, etc.
* Backquotes `.
* Subshell with operand `()`.
* Local variable and builtin `unset` and `export`.
* History with builtin `history`and `!` with options.
* Advanced line edition.
* File descriptors and builtin `read` with options.
* Dynamical autocompletion.

Optional feature highly appreciated:

* Job Control and builtins `job`, `fg`, `bg` and operand `&`.
* Shell Scripting in POSIX standards: for, while, until, if/elif/else, {}, bang (!), case, functions, variable assignements

## Shell/Subshell
## Line editing


|   **Keys**  | **Functions**|
| ----------- | ----------------------------------- |
|`Opt`+`c`<br/>`Opt`+`x`<br/>`Opt`+`v`| Copy<br/>Cut<br/>Paste |
|`Opt`+`<`<br/>`Opt`+`>`| Move per words.  |
|`Opt`+`v`<br/>`Opt`+`^`| Move per line.|
|`Ctrl`+ `L`| Clear screen. |
|`Ctrl`+ `C`| Terminate/Kill current foreground process. |
|`Ctrl`+ `Z`| Suspend/Stop current foreground process. |

## History

|   **Keys**  | **Functions**|
| ----------- | ----------------------------------- |
|`^`<br/>`v`| Browse the history. |
|`Ctrl` + `R`| Research function.  |
|`!!`| Retype the last command.|
|`!n`| Retype the `n` (numerical value) command from the begin of history. |
|`!-n`| Retype the `-n` (numerical value) command from the last command. |
|`!name`| Search for a command beginning with `name`. |
|`!?name`| Search for a command which contain `name`. |

## autocompletion

|   **Keys**  | **Functions**|
| ----------- | ----------------------------------- |
|`$> l[tab]`| Search for binary. |
|`$> ls s[tab]`| Search for path/files.  |
|`$> $[tab]`| Search for variables in env.|

## Globing

|   **Keys**  | **Functions**|
| ----------- | ----------------------------------- |
|`*`| Everything. |
|`**`| Match directory and sub-directory.  |
|`?`| Single char.|
|`[a-z]`| Match range from a to z. |
|`[!a-z]` `[^a-z]`| Exclude range from a to z. |
|`{ab, ac}`| Match ab or ac. |

## Hash table

|   **Keys**  | **Functions**|
| ----------- | ----------------------------------- |
|`hash`| List the content of the hash table. |
|`hash -r`| Clear the memory of the hash table. |

## Job Control

|   **Keys**  | **Functions**|
| ----------- | ----------------------------------- |
|`job`| List all the current running jobs. |
|`fg`| Bring the most recent process to foreground. |
|`fg n`| Bring the specified jobs to foreground where n is the numerical value of the process found in jobs.|

## Scripting

`while compound-list ; do compound-list ; done`<br/>

`until compound-list ; do compound-list ; done`<br/>

`if compound-list ; then compound-list ; elif compound-list ; then compound-list ; else compound-list`<br/>

`for i in list ; do compound-list ; done`<br/>

`case pattern1 in ( pattern2 ) compound-list ;; ( pattern1) compound-list ;; esac`<br/>
`{ compound-list }`<br/>

`! command`<br/>

`func() { compound-list }`<br/>

`VAR="hello world"`
