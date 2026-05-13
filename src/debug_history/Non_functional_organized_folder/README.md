## 1. Install WSL
Open **Command Prompt** or **PowerShell** as an Administrator and run (restart after installation):
```
wsl --install
```

## 2. Prepare Environment
Open your **WSL Terminal** and run the following commands to install the compiler, Verilator, and SDL2 graphics libraries:
```
sudo apt update
sudo apt install -y build-essential verilator libsdl2
```

## 3. Run simulation
Open your **WSL Terminal** and execute these commands to compile and launch the simulation:
# Navigate to your Windows project folder
```
cd /mnt/c/Users/Username/PathToHere
```

# Compile Verilog and C++ wrapper with SDL2 flags
```
verilator -I. -cc project.v --exe main.cpp -o vga_sim -CFLAGS "$(sdl2-config --cflags)" -LDFLAGS "$(sdl2-config --libs)"
```

# Build the executable binary
```
make -C ./obj_dir -f Vproject.mk
```

# Launch the graphical VGA simulation
```
./obj_dir/vga_sim
```

# Clean up build files (Optional)
```
rm -rf ./obj_dir
```