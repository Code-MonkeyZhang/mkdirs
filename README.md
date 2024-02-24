# mkdirs
`mkdirs` is a command-line interface (CLI) tool written in C++ designed to simplify the process of creating complex directory structures with ease. By allowing users to input a desired file structure, `mkdirs` automates the creation of directories and files, reflecting the specified hierarchy directly in the filesystem.


## Why you need it 
Have you ever embarked on a new project, only to find yourself tediously right-clicking to create each file and folder one by one? 🖱️ Or perhaps you've encountered someone else's project with a file management system that seemed like a complete mess? 📂🔥 This is where mkdirs steps in to save the day! 💡🚀
<img width="831" alt="image" src="https://github.com/Code-MonkeyZhang/mkdirs/assets/56613491/845e6a1b-2270-400b-954b-5b2a4dd9e6f8">
<img width="245" alt="image" src="https://github.com/Code-MonkeyZhang/mkdirs/assets/56613491/d70dc0e8-0302-4d78-aad1-e1850b87b2f4">

1. **Start with Names:** Begin by typing the name of your first file or directory. Press `Enter` to confirm.

2. **Set Hierarchy with Tab:** Utilize the `Tab` key to indicate the hierarchy levels for your structure. Each `Tab` press nests the next item deeper in the structure.

3. **Undo with Delete:** Made a mistake? Simply press `Delete` to remove the last entered item.

4. **Build Your Structure:** Continue adding the names of files or directories, confirming with `Enter` and setting their position in the hierarchy with `Tab`. Once you're done, `mkdirs` will create the directory and file structure as you've outlined.


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


