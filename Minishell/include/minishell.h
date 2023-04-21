#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <signal.h>
# include <dirent.h>
# include "libft.h"
# include <fcntl.h>
# include <termios.h>
# include <term.h>
# include <curses.h>

# define HIST_FILE		"./.minishell_history"
# define HIST_SIZE		20

//Parser Token Definitions
//normal word in the command line, such as a command or an argument.
#define WORD 1 
//represents a pipe symbol (|) used to connect the output of one command to the input of another command
#define PIPE 2
//epresents a redirection symbol (<, >, >>) used to redirect input or output between a command and a file
#define REDIR 3
//represents a semicolon symbol (;) used to separate multiple commands on a single line.
#define SEMICOLON 4

//Represents a token in the command input. It should help in parsing the input string into meaningful units.
typedef struct s_token
{
	char	*str;
	int		token_type;
}				t_token;

//Represents a command in a pipeline. It will be useful when handling piped commands, and managing the processes executing them.
typedef struct s_pipe
{
	char	*cmd;
	int		cmd_size;
	int		pipe_read;
	int		pipe_write;
	int		has_next_pipe;
	pid_t	child_pid;
}				t_pipe;

//Contains index variables and a quote field for parsing input strings. It could be useful during the tokenization process.
typedef struct s_parsing_state
{
	int	i;
	int	j;
	int	quote;
}				t_parsing_state;

//Represents a doubly-linked list node for history management. This will be useful for implementing the command history feature.
typedef struct s_history_node
{
	void			*content;
	struct s_hlist	*next;
	struct s_hlist	*previous;
}				t_history_node;

// Contains terminal control sequences for various actions like navigating through the history, clearing lines, etc. This will help in managing the terminal user interface.
typedef struct s_terminal_control
{
	char			*up_key;
	char			*down_key;
	char			*key_cariage_return;
	char			*key_clear_line;
	char			*end_key;
	char			*start_key;
}
					t_terminal_control;
//Represents the overall state of your minishell. It contains various fields to manage the shell state, environment, terminal, and history.
typedef struct s_minishell_state
{
	char			*prompt;
	char			*input;
	int				status;
	int				status_signal;
	char			**environment_variables;
	char			*pwd;
	int				fd_in;
	int				fd_out;
	int				any_redirection;
	int				is_interactive;
	struct termios	origin;
	struct termios	modified;
	t_history_node			*history_head;
	t_history_node			*history_index;
	t_terminal_control			*termc;
}	t_minishell_state;

/*
The termios structure is part of the <termios.h> header and is used to store terminal I/O settings in Unix-like 
systems. In your minishell project, you have two instances of this structure: origin and modified.

origin: This struct stores the original terminal settings before your minishell program starts. 
By preserving the original settings, you can restore them when your minishell exits or when it's not in
 the foreground. This ensures that the terminal behaves as expected when the user is not interacting with 
 your minishell.

modified: This struct stores the modified terminal settings specific to your minishell program.
These modified settings can include enabling non-canonical mode, disabling echo, or changing other terminal 
attributes to improve the user experience when interacting with your minishell.

In your code, you use tcsetattr() to switch between the original (origin) and modified (modified) terminal settings.
This is done to control the terminal's behavior depending on whether the user is currently interacting with your 
minishell or not.

To work with the termios structure, you need to include the <termios.h> header in your project.
*/

//function to print the prompt
void 	shell_image();
//set up the initial state of the minishell program
void	initialize_minishell_state(t_minishell_state *shell_state, char **env);
//cleaning up the resources used by the minishell before it exits
void	free_data(t_minishell_state *state, int exit_code);
//calculates the size of the environment variables array
int		envr_var_size(char **envr_var);
//creates a deep copy of the environment variables array
char	**copy_envr_var(char **envr_var);
//adds a new command to the history list of the minishell.
void	add_command_to_history(t_history_node **head_node, char *input_command);
//eads the command history from the history file and populates the history list in the minishell state
void	read_history_from_file(int fd, t_minishell_state *shell_state);
//oads the command history from the history file and updates the minishell state.
void	load_history_from_file(t_minishell_state *shell_state);
//sets up the history functionality for the minishell
int		initialize_history_mode(t_minishell_state *shell_state);
//responsible for setting up the terminal capabilities for the minishell
void	initialize_terminal_capabilities(t_minishell_state *shell_status);
//sets up a signal handler to catch SIGINT and SIGQUIT signals, which are generated when the user presses CTRL-C or CTRL-\ respectively.
void	handle_sig(int sig);
//initializes the signal handlers for SIGINT and SIGQUIT
void	init_signal_handling(void);
//write 2 chars
int	putchar_2(int c);
//creates a new history node
t_history_node	*ft_lstnew_2(void *content);
//checks for special statuses set in the t_minishell_state struct that indicate whether to exit or clear the input buffer
int	check_special_status(t_minishell_state *shell_status);
//eading user input in a history mode
void	handle_history_input(t_minishell_state *shell_status);
//Appends the current user input to the input buffer and prints the last character to the console.
void	add_to_input_buffer(char *buffer, t_minishell_state *shell_state);
//Adds the current input to the shell's command history, sets the history index to null, and prints a new line character to the console.
void	submit_input(t_minishell_state *shell_state);
//Deletes the last character from the user input buffer and prints the updated buffer to the console.
void	delete_last_character(t_minishell_state *shell_state);
//clears the current input line on the terminal and moves the cursor to the beginning of the line, ready for new input
int	clear_input_line(t_minishell_state *shell_state);
//saves the command history to a file
void	save_command_history(t_minishell_state *shell_state);
//Returns a string containing the content of the previous history entry given the current history node and the head of the history linked list.
char	*get_previous_history_entry(t_history_node **current_history_node, t_history_node **history_head);
//Returns a string containing the content of the next history entry given the current history node.
char	*get_next_history_entry(t_history_node **current_history_node);
//Sets the input buffer to the previous history entry and displays it in the terminal.
void	browse_history_previous(t_minishell_state *shell_state);
//Sets the input buffer to the previous history entry and displays it in the terminal.
void	browse_history_next(t_minishell_state *shell_state);
//Saves the command history to a file specified by HIST_FILE. The history is saved in reverse chronological order, with the most recent command at the top.
void	save_command_history(t_minishell_state *shell_state);
//function checks if the input buffer is empty and if so, it prints "exit" to stdout, sets the terminal attributes back to their original values, saves the command
//history to a file, and exits the program with a status of 0
void	end_of_file(t_minishell_state *data);
//navigates to the end of the linked list that represents the command history and sets the history_index pointer of the t_minishell_state struct to the last node in the list
void	set_history_tail(t_minishell_state *shell_state);
//checks if a character is printable or not
int	is_printable_character(char c);
//takes a user input string and a pointer to a t_data struct as input, performs some error checks on the input, 
//cleans it up, and calls the parser function to execute the parsed commands
int	execute_commands_from_input(char *input, t_minishell_state *shell_state);
//checks for parsing errors in the input string and returns an integer indicating the type of error encountered.
int	check_parse_errors(char *input);
//finalizes the parsing process by checking if there were any errors in the t_token structure
static int	parser_err_finalize(t_token *token);
// takes a substring of the input string based on the size parameter and passes it to either parser_err_ctrl or parser_err_word depending on the id parameter.
static int	update_parser_token(char *input, int size, t_token *previous_token, int id);
//handles the case when a word token is encountered in the input string
static int	validate_word_input(char *input, t_token *previous_token, char *str, int size);
//prints an error message to standard error output, including the command and argument (if provided) that caused the error
int	print_error(char *command, char *arg, char *err_msg, int exit_code);
//prints a parser error message to stderr, indicating a syntax error near an unexpected token.
int	print_parser_err(char *token);
//checks if the given input starts with a file descriptor number, which is a digit.
int	is_file_descriptor(char *input);
//hecks if a given character input is a quotation mark (either single or double) and returns an updated quote state
int	get_quote_status(char input, int quote);
//calculates the size of the next word in a given string input, which can be used for parsing purposes.
int	get_word_size(char *input);
//calculates the size of the next control operator (like semicolon, pipe, or redirection) in a given string input
int	get_control_op_size(char *input);
//checks if a given character input is a whitespace character
int	is_whitespace(char input);
//It is used to handle escaped characters in a string that is being parsed
void	insert_quotes(char **dst, char **src);
//copy characters from the source string to the destination string, but only while a quote character is open
void	get_text_within_quotes(char **src, char **dst, char quote);
//akes a source string and copies it to a destination string while performing some modifications. It removes unnecessary 
//consecutive spaces or tabs, and handles escaping and quoting of characters.
void	extract_tokens_from_input(char *dst, char *src);
//calculates the length of a substring within quotes
void	quote_size(char **str, int *i, char quote);
//Calculates the length of a given string `str` after removing unnecessary
//spaces and tab characters, and counting escaped and quoted character
static int	calculate_input_size(char *str, int *size, int quote);
//takes a string as input, cleans it by removing unnecessary spaces and tabs, and returns a newly allocated cleaned string
char	*clean_input_str(char *str);





