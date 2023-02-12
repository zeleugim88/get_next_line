//Debemos ser capaces de compilar este proyecto con y sin el flag -D
//BUFFER_SIZE, junto a los flags habituales.

cc -Wall -Werror -Wextra -D BUFFER_SIZE=42 <archivos>.c.