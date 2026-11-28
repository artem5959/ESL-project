#ifndef COMMAND_H
#define COMMAND_H

#define COMMAND_BUFF_SIZE 64
#define RETURN_BUFFER_SIZE 64

extern char command_buff[COMMAND_BUFF_SIZE];

extern char return_buffer[RETURN_BUFFER_SIZE];

//void write_in_command_buff(char *buff, char*com_buf);

void clear_command_buff(char*com_buff);

void send_commands(char*com_buff);





#endif