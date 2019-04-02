<h1> Get Next Line </h1>

<p>
Get next line reads an entire line from a file descriptor <i><b>fd</b></i>, storing the address of the buffer 
containing the string into <i><b>line</b></i>.
The buffer is null-terminated and does <b>not</b> include the newline character.
</p>
<p>In order to use this function you <b>must</b> compile the library inside the <b><i>libft</i></b> directory.</p>
<code>
  make -C libft/
</code>
<h4> This is how the function is prototyped </h4>
<code>
int	get_next_line(const int fd, char **line);
</code>
<p>

This function also has multiple file descriptors support for reading from multiple file descriptors simultaneously without loosing the thread it was on for each file descriptor.
It also handles reading from standard input/output.</p>
<h4>Return Values</h4>
get_next_line returns an integer indicating the status of the line read from the file descriptor
<ul>
  <il>
    <b>1</b> Whenever the reading from the file descriptor was succesfull and there is a valid buffer stored into <i>line</i>.
  </il>
  <il>
    <b>0</b> Whenever the reading from the file descriptor was succesfull but there is nothing left to read from a the file descriptor.
  </il>
  <il>
    <b>-1</b> When the reading from the file descriptor was unsuccesfull as an <b>error</b> management solution.
  </il>
</ul>
