<h1> Get Next Line </h1>

<p>
Get next line reads an entire line from a file descriptor <i><b>fd</b></i>, storing the address of the buffer 
containing the string into <i><b>line</b></i>.
The buffer is null-terminated and does <b>not</b> include the newline character.
</p>
<h4> This is how the function is prototyped </h4>
<code>
int	get_next_line(const int fd, char **line);</li>
</code>
<br></br>
<p>
This function also has multiple file descriptors support for reading from multiple file descriptors simultaneously without loosing the thread it was on for each file descriptor.
It also handles reading from standard input/output.
</p>
