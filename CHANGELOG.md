# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

---

## [Unreleased]
- Daily updates planned as time allows.

---

## [v0.2.3-alpha] - 2025-04-02
## Added
- undu task
- displays how many days laft a task 
- resturctured some code 

## Notes
- Menu navigation is more intuitive with clearer options.

---

## [v0.2.1-alpha] - 2025-04-01

## Added
- documented trimUserInput()
- Added an entry for due date in add task function
- Added a due date category to save and load
- Improved task filtering: filter tasks by completion status directly from the menu ✨
- Enhanced menu navigation for better usability ✨

### Fixed
- Task deletion bug: resolved incorrect task renumbering after deletion 🐛
- UI glitch: fixed minor display issues when marking tasks as completed 🐛

### Notes
- Task filtering now supports completed and pending tasks.
- Menu navigation is more intuitive with clearer options.

---

## [v0.2.0-alpha] - 2025-03-31

### Added
- File saving/loading (persistence): tasks are now saved to a file and loaded automatically on startup ✨
- Task editing: added the ability to edit task descriptions ✨
- Task priorities: tasks can now be assigned priorities (low, medium, high) ✨

### Notes
- This release introduced significant new features to improve task management.

---

## [v0.1.2-alpha] - 2025-03-30

### Added
- Feature to mark tasks as completed ✅
- Automatic ID reordering after task deletion 🔁
- Improved code organization (moved `main()` to top level)

### Notes
- Completed tasks display a checkmark `[✓]`.
- Task IDs are now always sequential after a task is removed.

---

## [v0.1.0-alpha] - 2025-03-28

### Added
- Initial release of the project
- Core functionality: add, remove, and view tasks

### Known Issues
- Limited error handling in some inputs
- Task persistence not yet implemented
- No task editing or sorting yet

### Notes
- This is an alpha release. Expect frequent updates as development progresses.
