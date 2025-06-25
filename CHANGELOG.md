# Changelog
**Project:** The Curse of Kursore  
**Studio:** Spell Lynx Games  
**Generated:** 2025-06-25

---

## [v0.1.0] - Initial Spirit Panel Integration
### Added
- SpiritUnit and SpiritPanel systems created
- Click-to-harvest phylactery + soul counter display
- SpiritUnit panel with sprite, name, description, summon button, cost scaling
- Scrollable spirit panel after 4+ units
- Conditional unlock and red-highlight states based on soul count
- Passive soul income logic per unit

### Fixed
- Souls-per-second now adds correctly after SpiritUnit bug resolved
- Panel drawing and positioning confirmed left of main phylactery
- Compile errors for constructor parameter mismatch resolved

### Known Issues
- Font not loading from `assets/pixel_font.ttf` (fallback used)
- No save/load system yet
- No Ritual system or reset loop implemented

---
