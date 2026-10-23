# x64 Modern Stack Migration - Server Game

Branch: migration/game-x64-modern-stack

Current foundation
- game is built with -m64.
- Compiler: GCC 14.
- Language mode: C++20.
- Client/server wire layouts must remain fixed-width and synchronized with Project_ClientSrc.

Dependency target
- Upgrade bundled Crypto++ 7.0 to Crypto++ 8.9 and build it with the same compiler/ABI as game.
- Keep native FreeBSD amd64 MariaDB/MySQL and DevIL dependencies.
- Do not change packet field widths merely because host pointers are 64-bit.

Acceptance
- game and its project libraries are amd64.
- No 32-bit object/archive is linked.
- Login, character select, enter-game and map changes work with the x64 client.
- Packet/wire static assertions remain synchronized with the client.
