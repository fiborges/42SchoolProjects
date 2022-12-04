<h1 align="center">
	📖 MiniTalk
</h1>

<p align="center">
	<b><i>You must create a communication program in the form of a client and a server</i></b><br>
</p>

## Mandatory Part <br>

---

• You must create a communication program in the form of a client and server. <br> 
• The server must be launched first, and after being launched it must display its PID. <br>
• The client will take as parameters: <br>
◦ The server PID. <br>
◦ The string that should be sent. <br>
• The client must communicate the string passed as a parameter to the server. <br>
  &ensp; Once the string has been received, the server must display it. <br>
• Communication between your programs should ONLY be done using UNIX signals. <br>
• The server must be able to display the string pretty quickly. By quickly we mean that if you think it is too long, <br>
  &ensp; then it is probably too long (hint: 1 second   for 100 characters is COLOSSAL) <br>
• Your server should be able to receive strings from several clients in a row, without needing to be restarted. <br>
• You can only use the two signals SIGUSR1 and SIGUSR2. <br><br>

---

## Bonus

---

• The server confirms every signal received by sending a signal to the client. <br>
• Support Unicode characters! <br><br>


# What is signal?

A signal is a notification to a **process** that an event has occurred. Signals are sometimes described as software interrupts.
One process can send a signal to another process. In this use, signals can be employed as a primitive form of interprocess communication (IPC). 
Each signal is defined as a unique (small) integer, starting sequentially from 1. These integers are defined in <signal.h> with symbolic names of the form SIGxxxx. Since the actual numbers used for each signal vary across implementations, it is these symbolic names that are always used in programs. 
A signal is said to be _generated_ by some event. Once generated, a signal is later _delivered_ to a process, which then takes some action in response to the signal. Between the time it is generated and the time it is delivered, a signal is said to be _pending_.

## Standard Signals

The signals are defined in the header file signal.h as a macro constant. Signal name has started with a “SIG” and followed by a short description of the signal. So, every signal has a unique numeric value. Your program should always use the name of the signals, not the signals number. The reason is signal number can differ according to system but meaning of names will be standard.

The macro NSIG is the total number of signal defined. The value of NSIG is one greater than the total number of signal defined (All signal numbers are allocated consecutively).

Source: https://linuxhint.com/signal_handlers_c_programming_language/

# Signal Handling

The signal() call takes two parameters: the signal in question, and an action to take when that signal is raised.

The action can be one of three things:

- A pointer to a handler function.
- SIG_IGN to ignore the signal.
- SIG_DFL to restore the default handler for the signal.

Let’s write a program that you can’t CTRL-C out of. (Don’t fret—in the following program, you can also hit RETURN and it’ll exit.)

```c
#include <stdio.h>
#include <signal.h>

int main(void)
{
    char s[1024];

    signal(SIGINT, SIG_IGN);    // Ignore SIGINT, caused by ^C

    printf("Try hitting ^C... (hit RETURN to exit)\n");

    // Wait for a line of input so the program doesn't just exit
    fgets(s, sizeof s, stdin);
}
```

Check out line 8—we tell the program to ignore SIGINT, the interrupt signal that’s raised when CTRL-C is hit. No matter how much you hit it, the signal remains ignored. If you comment out line 8, you’ll see you can CTRL-C with impunity and quit the program on the spot.

## Writing Signal Handlers

I mentioned you could also write a handler function that gets called with the signal is raised.

These are pretty straightforward, are also very capability-limited when it comes to the spec.

Before we start, let’s look at the function prototype for the signal() call:

```
void (*signal(int sig, void (*func)(int)))(int);
```

Pretty easy to read, right?

WRONG! :)

Let’s take a moment to take it apart for practice.

signal() takes two arguments: an integer sig representing the signal, and a pointer func to the handler (the handler returns void and takes an int as an argument), highlighted below:

```
                sig          func
              |-----|  |---------------|
void (*signal(int sig, void (*func)(int)))(int);
```

Basically, we’re going to pass in the signal number we’re interesting in catching, and we’re going to pass a pointer to a function of the form:

```
void f(int x);
```

that will do the actual catching.

Now—what about the rest of that prototype? It’s basically all the return type. See, signal() will return whatever you passed as func on success… so that means it’s returning a pointer to a function that returns void and takes an int as an argument.

```
returned
function    indicates we're              and
returns     returning a                  that function
void        pointer to function          takes an int
|--|        |                                   |---|
void       (*signal(int sig, void (*func)(int)))(int);
```

Also, it can return SIG_ERR in case of an error.

### What is a process?

>A process is an instance of an executing **program**.
>
>We can recast the definition of a process given at the start of this section as follows: a process is an abstract entity, defined by the kernel, to which system resources are allocated in order to execute a program.
>
>From the kernel’s point of view, a process consists of user-space memory containing program code and variables used by that code, and a range of kernel data structures that maintain information about the state of the process. The information recorded in the kernel data structures includes various identifier numbers
(IDs) associated with the process, virtual memory tables, the table of open file descriptors, information relating to signal delivery and handling, process resource usages and limits, the current working directory, and a host of other information.

	
_**The server has to display the string pretty quickly**._
	
_The server acknowledges every message received by **sending back a signal to the
client**._
	
ℹ️  _Linux system does NOT queue signals when you already have pending
signals of this type!_

How to handle signals quickly since they don't queue when they are pending, without losing sent signals?
	
The _sleep()_ function suspends execution of the calling process** for the number of seconds specified in the seconds argument or **until a signal is caught** (thus interrupting the call).

### My Process:

Server:

DECODE_BINARY
	
	
With signals you cannot send any data, just communicate between processes i.e. send notifications. The kill function sends the signal. Depending on
whether SIGUSR1 or SIGUSR2 is send, the signal gets translated into 0 or 1.

Alternatively the bit shifting part can be performed the other way round:
	
	static int				bit = 7;
	if (signal == SIGUSR1)
		c += 1 << bit;
	bit--; 
	if (bit < 0)
	{
		ft_putchar_fd(c, 1);
		bit = 7;
		c = 0;
	}
	
SIGNAL_HANDLER
	
The function is called by sigaction, whenever the server receives a signal from the client.
Siginfo struct delivers the sender PID.
Signal handlers run asyncronously, which means they can interrupt the code at any point. Therefore you can only use signal-save functions, i.e. write.

The manual lists save functions.
	
	https://www.youtube.com/watch?v=PErrlOx3LYE
	
	
MAIN
	
	https://linuxhint.com/c-sigaction-function-usage/
	
Sigaction is to be preferred over the signal function according to the manual, because the behaviour of signal varies across UNIX versions and
has varied across Linux versions as well.
To use the sigaction function, you have to create a struct.
The sigaction function reacts, whenever a specific signal is sent and calls the handler, to which the sigaction function is bound.
The signals SIGUSR1 and SIGUSR2 are not used by Linux for generic process operations and can be used as needed by the user.
The signal() function does not block other signals when the current handler’s execution is under process. At the same time, the sigaction
function can block other signals until the current handler has returned.
SA_SIGINFO — queue this signal. The default is not to queue a signal delivered to a process. If a signal isn't queued, and the same signal is
set multiple times on a process or thread before it runs, only the last signal is delivered. If you set the SA_SIGINFO flag, the signals are
queued, and they're all delivered.

Client:

CLIENT_HANDLER	

The handle is called by sigaction in the main function, when the main receives a signal.
	
MT_TRANSFER_SIGNAL
		
The function mt_transfer_signal encodes the character string into binary and sends the single bits to the server function, using the signals SIGUSR1
(equals 1) and SIGUSR2 (equals 0).
The outer while loop loops through each character of the string. The inner while loop encodes the charcater into binary, containing of 8 bits (ASCII):

	Example: the character 'a' equals the decimal 97, which is in binary
	0	1	1	0	0	0	0	1
	128	64	32	16	8	4	2	1
	
	The loop loops 8 times to look at each bit.
	In the first loop, the function looks at the first bit (first position):
	i equals 0 in this loop, so no bit shifting is done. Then the bitwise
	operator & is applied to that bit:
	0	1	1	0	0	0	0	1 (97)
	1	0	0	0	0	0	0	0 (128)
	---------------------------------- &
	0	0	0	0	0	0	0	0
	
	The result of the & operation is 0, so the if statement is not true and the
	else statement sends SIGUSR2;
	In the second loop, i equals 1, so the character binary is shifted to the
	left by one bit. This operation results in the following:
	1	1	0	0	0	0	1	0 (97 after bit shift to the left by 1);
	1	0	0	0	0	0	0	0 (128)
	----------------------------------	&
	1	0	0	0	0	0	0	0
	
	The result of the & operation is 1, so the if statement is true and sends
	SIGUSR1 to the server function.
	
The encoding could also be done the other way round: starting with a bit shift by seven bits and comparing to to decimal one, which only holds a
1 in the leftmost position in binary (00000001);
Once, the string is sent, a terminating 0 (00000000 in binary) is sent to the server, to let it know that the transfer is finished.

Signals don't queue, therefore a microsecond break (usleep) is needed.
The kill() function sends a signal to a process or process group specified by PID.
	
	
MAIN

The main function in this file takes two arguments, the server PID and a user defined string.

	
