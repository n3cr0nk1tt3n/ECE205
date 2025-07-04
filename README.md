# The Curse of Kursore — `curse-test` Branch

Welcome to the **`curse-test`** branch of *The Curse of Kursore*.

This branch serves as a **dedicated development and testing zone** for experimental features, system refinements, and UI/UX iterations. All changes in this branch are isolated for the purpose of **safe testing and debugging** before they are finalized and merged into the main or submission branches.

---

## 🔍 Purpose

- Isolate in-progress work from the primary production codebase
- Test new gameplay mechanics, UI panels, and rendering adjustments
- Validate game loop stability, input handling, and performance
- Experiment with save/load systems, scaling mechanics, and prestige logic

---

## ✅ Current Focus Areas

- Finalizing SpiritPanel logic (scroll, upgrade visibility, state logic)
- Fixing `pixel_font.ttf` load failure
- Prototyping Ritual/Prestige system infrastructure
- Building out save/load system (manual + auto-save)
- Hooking up placeholder audio (whispers, clicks)

---

## 🧪 Guidelines for Use

- Commit only testable or modular code that won’t break core gameplay
- Use feature branches off of `curse-test` if changes are major
- Test UI states under various progression levels
- Leave clear commit messages with scope of test (e.g., `feat: add ritual cost scaling`)

---

## 🔄 Merge Strategy

- Do **not** merge into `main` or `submission` until features are fully functional and reviewed
- Approved features will be cherry-picked or merged manually into the final game branch

---

## 📁 Structure Notes

- All SFML-based game logic remains modular (render, update, input split)
- New features should remain decoupled when possible
- Save data structure is being prototyped using simple file-based serialization

---

## 🧠 Developer Notes

> “Break it here so you don’t break it later.”  
This branch is designed for safe creative chaos—don’t be afraid to test, break, and iterate.

---

## 🛠 Build Instructions

Standard build via terminal:
```bash
make
./curse_of_kursore
