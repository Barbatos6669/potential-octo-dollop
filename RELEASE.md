# Release: v0.2.1-alpha - April 1, 2025

This update includes the ability to store a due date

---

# Release: v0.2.1-alpha - April 1, 2025

This update includes the latest improvements and bug fixes for the task manager CLI app.

---

## ✨ Added

- **Improved Task Filtering**  
  Added the ability to filter tasks by completion status directly from the menu.

- **Enhanced Menu Navigation**  
  Improved menu organization for better usability.

---

## 🐛 Fixed

- **Task Deletion Bug**  
  Fixed an issue where deleting a task sometimes caused incorrect task renumbering.

- **UI Glitch**  
  Resolved a minor display issue when marking tasks as completed.

---

## 🔍 Notes

- Task filtering is now available for completed and pending tasks.
- Menu navigation is more intuitive with clearer options.

---

# Release: v0.2.0-alpha - March 31, 2025

This update introduced several new features and improvements.

---

## ✨ Added

- **File Saving/Loading (Persistence)**  
  Tasks are now saved to a file and loaded automatically on startup.

- **Task Editing**  
  Added the ability to edit task descriptions.

- **Task Priorities**  
  Tasks can now be assigned priorities (low, medium, high).

---

## 📅 Coming Soon

- Categories for tasks
- Improved CLI help and documentation
- Additional UI enhancements

---

# Release: v0.1.2-alpha - March 30, 2025

This update introduces a couple of core features and improvements to the task manager CLI app.

---

## ✨ Added

- ✅ **Mark tasks as completed**  
  Tasks can now be marked complete using the menu. Completed tasks show `[✓]`.

- 🔁 **Reorganize Task IDs after Deletion**  
  When a task is removed, remaining tasks are renumbered to keep IDs sequential.

- 🧼 **Code Cleanup & Reorganization**  
  Moved `main()` to the top of the file for cleaner structure and easier navigation.

---

## 🔍 Notes

- All completed tasks now display a checkmark `[✓]`
- You can still remove or view completed tasks like normal
- Task IDs will always be clean and in order

---

## 📅 Coming Soon

- File saving/loading (persistence)
- Task editing, priorities, categories
- Better menu organization & completed task filtering
