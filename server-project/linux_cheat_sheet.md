cat << 'EOF'

## 1. Navigation & File Management
- pwd : Print working directory (shows where you are)
- ls -la : List all files, including hidden ones, in current directory
- cd [path] : Change directory (e.g., cd server-project or cd .. to go up)
- mkdir [name] : Create a new directory
- rmdir [name] : Delete an empty directory
- rm -r [name] : Delete a directory and all its contents
- touch [name] : Create a blank file
- cp [src] [dest] : Copy a file
- mv [old] [new] : Move or rename a file
- rm [file] : Delete a file

## 2. Editing & Compiling Code (C Server Focus)
- nano [file] : Open simple terminal text editor (Ctrl+O to save, Ctrl+X to exit)
- gcc [file] -o [out] : Compile C code into an executable (e.g., gcc server.c -o server)
- ./[executable] : Run a compiled program (e.g., ./server)

## 3. Networking & Server Debugging
- ss -tuln : View all active listening ports and sockets
- ip a : Check your network interfaces and IP addresses
- curl [url] : Send an HTTP request to test your server (e.g., curl localhost:8080)

## 4. Package Management
- sudo apt update : Refresh package lists
- sudo apt install [pkg] : Install software (e.g., sudo apt install build-essential)
EOF
