#include "../minishell.h"

int	open_filee(char *filename, t_file_mode mode)
{
	int	flags;
	int	fd;

	if (mode == READ_MODE)
		flags = O_RDONLY;
	else if (mode == WRITE_TRUNC_MODE)
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	else
		flags = O_WRONLY | O_CREAT | O_APPEND;
	fd = open(filename, flags, 0644);
	if (fd < 0)
		print_error(NULL, filename);
	return (fd);
}

void	redirect_fd(int old_fd, int new_fd)
{
	dup2(old_fd, new_fd);
	close(old_fd);
}

void	handle_heredoc(t_infile *infile)
{
	int		fd;
	char	*content;

	fd = open_file(infile->filename, WRITE_TRUNC_MODE);
	content = read_heredoc(infile->delimiter);
	write(fd, content, ft_strlen(content));
	if (!infile->next)
		redirect_fd(open_file(infile->filename, READ_MODE), STDIN_FILENO);
	free(content);
	close(fd);
}

void	handle_input_redirection(t_pipeline *pipeline)
{
	t_infile	*infile;
	int			fd;

	infile = pipeline->word->infiles;
	while (infile)
	{
		if (infile->type == INPUT)
		{
			fd = open_file(infile->filename, READ_MODE);
			redirect_fd(fd, STDIN_FILENO);
		}
		else if (infile->type == HDOC)
			handle_heredoc(infile);
		infile = infile->next;
	}
}

void	handle_output_redirection(t_pipeline *pipeline)
{
	t_outfile	*outfile;
	int			fd;

	outfile = pipeline->word->outfiles;
	while (outfile)
	{
		if (outfile->ambiguous_red == TRUE)
			print_error("ambiguous redirect\n", NULL);
		else if (outfile->type == OUTPUT)
		{
			fd = open_file(outfile->filename, WRITE_TRUNC_MODE);
			redirect_fd(fd, STDOUT_FILENO);
		}
		else if (outfile->type == APPEND)
		{
			fd = open_file(outfile->filename, WRITE_APPEND_MODE);
			redirect_fd(fd, STDOUT_FILENO);
		}
		outfile = outfile->next;
	}
}
