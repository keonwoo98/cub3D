# cub3D Subject

## Makefile
- all, clean, fclean, re, bonus

## Arguments
- a map in format *.cub

## External Functs
- open, close, read, write, printf, malloc, free, perror, strerror, exit
- All functions of the math library
- All functions of the MinilibX
- Libft authorized : Yes

## Mandatory
- minilibX를 사용해야 한다.
- window는 부드럽게 관리 되어야 한다. : 다른 윈도우로 바꾸는것, 최소화 등
- 벽이 어느 방향을 바라보고 있냐에 따라 다른 texture를 적용해야 한다. (North, South, East, West)
- floor 와 ceiling 색을 다른 색으로 적용해야 한다.
- The program displays the image in a window and respects the following rules:
	- 왼쪽 오른쪽 방향키는 왼쪽, 오른쪽을 보게 만들어야 하낟.
	- The W, A, S, and D keys must allow you to move the point of view through the maze.
	- Pressing ESC must close the window and quit the program cleanly.
	- Clicking on the red cross on the window’s frame must close the window and quit the program cleanly.
	- The use of images of the minilibX is strongly recommended.

Your program must take as a first argument a scene description file with the .cub extension.
  - The map must be composed of only 6 possible characters: 0 for an empty space, 1 for a wall, and N,S,E or W for the player’s start position and spawning orientation.
  - The map must be closed/surrounded by walls, if not the program must return an error.
  - Except for the map content, each type of element can be separated by one or more empty line(s).
  - Except for the map content which always has to be the last, each type of element can be set in any order in the file.
  - Except for the map, each type of information from an element can be separated by one or more space(s).
  - The map must be parsed as it looks in the file. Spaces are a valid part of the map and are up to you to handle. You must be able to parse any kind of map, as long as it respects the rules of the map.

Each element (except the map) firsts information is the type identifier (composed by one or two character(s)), followed by all specific informations for each object in a strict order such as :

- North texture:   
	`NO ./path_to_the_north_texture`
  - identifier: NO
  - path to the north texure
- South texture:   
	`SO ./path_to_the_south_texture`
  - identifier: SO
  - path to the south texure
- West texture:   
    `WE ./path_to_the_west_texture`
  - identifier: WE
  - path to the west texure
- East texture:   
    `EA ./path_to_the_east_texture`
  - identifier: EA
  - path to the east texure
- Floor color:   
	`F 220,100,0`
  - identifier: F
  - R,G,B colors in range [0,255]: 0, 255, 255
- Ceilling color:   
	`C 225,30,0`
  - identifier: C
- R,G,B colors in range [0,255]: 0, 255, 255

- Example of the mandatory part with a minimalist .cub scene:
```
	NO ./path_to_the_north_texture
	SO ./path_to_the_south_texture
	WE ./path_to_the_west_texture
	EA ./path_to_the_east_texture
	
	F 220,100,0
	C 225,30,0

			1111111111111111111111111
			1000000000110000000000001
			1011000001110000000000001
			1001000000000000000000001
	111111111011000001110000000000001
	100000000011000001110111111111111
	11110111111111011100000010001
	11110111111111011101010010001
	11000000110101011100000010001
	10000000000000001100000010001
	10000000000000001101010010001
	11000001110101011111011110N0111
	11110111 1110101 101111010001
	11111111 1111111 111111111111
```

- If any misconfiguration of any kind is encountered in the file, the program must exit properly and return "Error\n" followed by an explicit error message of your choice.
