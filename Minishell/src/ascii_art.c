#include "minishell.h"

const char *ascii_art = "                                                                                             \n"
"__  __    ___    _  _     ___     ___    _  _     ___     _       _                                                  \n"
"|  |/  |  |_ _|  | || |   |_ _|   / __|  | || |   | __|   | |     | |                                                \n"
"| ||/| |   | |   | .` |    | |    |__ |  | __ |   | _|    | |__   | |__                                              \n"
"|_|__|_|  |___|  |_||_|   |___|   |___/  |_||_|   |___|   |____|  |____|                                             \n"
"                                                                                                                     \n"
"'`-o-0-''`-o-0-''`-0-0-' -o-o-'''`--0-''`-0-0-''`-0-0-''`-0-0-''`-0-0-'                                              \n"
"    ___    ___     _       ___      ___    ___                 __  __    ___     ___     ___     ___                 \n"
"   | __|  |_ _|   | |     |_ _|    | _ |  /   |     o O O     |  |/  |  /   |   | _ |   |_ _|   / _ |                \n"
"   | _|    | |    | |__    | |     |  _/  | - |               | ||/| |  | - |   |   /    | |   | (_) |               \n"
"  _|_|_   |___|   |____|  |___|   _|_|_   |_|_|               |_|__|_|  |_|_|   |_|_|   |___|   |___/                \n"
"                                                                                                                     \n"
"''`-0-0-'''`-0-0-'''`-0-0-''`-0-0-''`-0-0-''`-0-0-'.    .|o--'0-0-0-''`-0-0-''`-0-0-''`-0-0-''`-0-0-''`-0-0-'        \n";
                                                                                                                
void shell_image() 
{
    printf("%s\n", ascii_art);
}