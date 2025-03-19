# CLI-Based To-Do List Manager

## Overview
A simple and efficient command-line task manager designed to help users organize their tasks easily. Users can add, remove, edit, complete, and prioritize tasks.

## Features
- Add, remove, and edit tasks
- Mark tasks as completed
- Prioritize tasks (High, Medium, Low)
- Sort tasks based on priority
- Color-coded task display
- Persistent storage using files
- Simple and user-friendly CLI
- Error handling to prevent crashes

## Installation
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/todo-list-cli.git
   ```
2. Navigate to the project directory:
   ```sh
   cd todo-list-cli
   ```
3. Compile the program:
   ```sh
   g++ todo_list.cpp -o todo_list
   ```
4. Run the program:
   ```sh
   ./todo_list
   ```

## Usage
- Add a task: `add "Task description"`
- Remove a task: `remove <task_id>`
- Mark as complete: `complete <task_id>`
- Edit a task: `edit <task_id> "New description"`
- Show tasks: `list`
- Clear completed tasks: `clear`

## Contribution
Feel free to contribute by submitting pull requests or reporting issues.

## License
This project is open-source and available under the MIT License.