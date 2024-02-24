# mkdirs
`mkdirs` is a command-line interface (CLI) tool written in C++ designed to simplify the process of creating complex directory structures with ease. By allowing users to input a desired file structure, `mkdirs` automates the creation of directories and files, reflecting the specified hierarchy directly in the filesystem.


## Why you need it 
Have you ever embarked on a new project, only to find yourself tediously right-clicking to create each file and folder one by one? 🖱️ Or perhaps you've encountered someone else's project with a file management system that seemed like a complete mess? 📂🔥 This is where mkdirs steps in to save the day! 💡🚀

## How to Run
### Step 1: Clone the Repository
```bash
git clone https://github.com/Code-MonkeyZhang/mkdirs.git
```

### Step 2: Navigate to the Binary Directory
```bash
cd mkdirs/bin/
```

### Step 3: Run the Tool
To run mkdirs, you have two options:

**Option 1**: Execute Directly in the Terminal

```bash
./mkdirs
```
**Option 2**: Source the Binary File

Alternatively, you can source the binary file to make mkdirs available from any location in the terminal. To do so, you need to add the full path of the mkdirs binary to your shell's configuration file (e.g., .bashrc, .zshrc, etc.). This method allows you to run mkdirs by simply calling its name in the terminal:

```bash
source /path/to/mkdirs/bin/mkdirs
```
Replace /path/to/mkdirs/bin/mkdirs with the actual path to the mkdirs binary on your system. After sourcing, you can use the mkdirs command directly:

```bash
mkdirs
```


