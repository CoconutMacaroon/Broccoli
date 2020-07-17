# Broccoli Documentation  
  
## Intro  
  
This is the Broccoli programming language. The commands are based on the game Robot Turtles (Kickstarter edition).
  
## Syntax  
  
### Commands  
  
Commands follow the following syntax: `<command name>;<newline>`. You may only have one command per line; so the newline is required. You may have one command per line. Do not have a space between `<command name>` and `;`. To fire the turtle's laser, for example the command would be `laser;`.  Valid commands are:

	- `laser;`
	- `function;`*
	- `forward;`
	- `left;`
	- `right;`

  *See also _Functions_
### Functions  
  
Functions are defined as follows:
`function<optional whitespace>{<newline><one or more valid commands, seperated by newlines><newline>}`. Each code file must have zero or one functions. Having multiple results in undefined behavior. Here is an example function, that fires the laser, and then moves forward. A function should be defined prior to its use. Not doing so results in undefined results.
```
function {
    laser;
    forward;
}
```
Functions are called by running `function;`.
### Comments
You may comment your code with the traditional syntax of `//<your comment here>` To be more specific, your comment must match this regex: `\/\/[ a-zA-Z0-9]*`. It defines that a comment starts with two slashes, then it may contain any number of spaces, letters (upper-and-lower case), and digits (`0 - 9`). It must span one and only one line.

## Code files

Code files contain: one or more commands, and zero or one function. Do NOT put blank lines in the code; however, one blank line at the end of the code is REQUIRED. If the blank line at the end of the file is ommited, the final line of your code will be ignored.

## Other Files

There are two main file types: `*.broc` and `*.brocc`. They represent code files and compiled Broccoli code files respectively. Compiled code files should _not_ be modified. But they have instructions, with one `char` per instruction, and NO newline at the end.

## To-do
- [x] Add walls
- [x] Add functions
- [x] Validate code inside functions
- [x] Add file IO
- [x] Add comments
- [ ] Add ability to fire lasers in all directions
- [x] Add sound effects
- [x] Add win condition
- [x] Add command line agruments
- [x] Add interacitveness NOTE: This isn't _interactive_, in that you can interact with it, but it is the only thing on the screen (technically the console). Note that interactivity can be overridden with flags.

## Flags

The command format is `broc [-c] [-r] [-?]`. Compile/run Broccoli code. It reads (uncompiled) code from the parameter from the `-f` argument. Reads compiled code from `main.brocc`.

The options are:
```
-c   Compile code file specified by the -f argument
-s   Do not play sounds
-r   Run code
-?   Display help and exit
-n   Run the code in noninteractive mode
```


