# Broccoli Documentation  
  
## Intro  
  
This is the Broccoli programming language. The commands are based on the game Robot Turtles (Kickstarter edition).
  
## Syntax  
  
### Commands  
  
Commands follow the following syntax: `<command name>;`. You may have one command per line. To fire the turtle's laser, for example the command would be `laser;`.  Valid commands are:
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
## Code files

Code files contain: one or more commands, and zero or one function. Do NOT put blank lines in the code. The file should NOT end with a blank line, but the final line of code.

## To-do
- [x] Add walls
- [x] Add functions
- [ ] Add file IO
- [ ] Add ability to fire lasers in all directions
- [ ] Add sound effects