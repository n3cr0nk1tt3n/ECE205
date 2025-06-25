# Game Design Document (GDD)
**Title:** The Curse of Kursore  
**Studio:** Spell Lynx Games  
**Design Lead:** Derek Miner  
**Document Version:** v1.1 (June 2025)

---

## 1. Overview
**Genre:** Clicker / Idle Game with Light RPG Elements  
**Platform:** PC (standalone, with browser-based potential)  
**Visual Style:** 2D pixel art, dark fantasy necromancer aesthetic  

The player controls a cursed phylactery that grows in power by harvesting souls, unlocking spectral units, and spreading corruption across the UI/world.

---

## 2. Current Features (Implemented)
- Click-to-harvest mechanic using a phylactery
- Real-time soul counter displayed in-game
- Spirit Summoning Panel (unlocked by souls, scrollable if >4 units)
  - Dynamic unit boxes with name, description, cost, sprite, and Summon button
  - Units contribute passive souls per second
  - Cost increases per purchase
  - Only the next summonable unit appears; others unlock progressively
- Spirit units go red when unaffordable and return to normal when buyable
- Game loop structure with basic render, update, and input

---

## 3. Planned & Discussed Features
- Persistent Prestige/Ritual system (reset with permanent upgrades)
- Additional resource types (Bone Fragments, Woe, Dark Sigils, Blight)
- Structure upgrades (Soul Well, Bone Mill, Wailing Tree, etc.)
- Multiple progression zones ("Progression Areas")
- Visual corruption to UI as player advances
- Lore fragments and Prophecy/Event Chains
- Save/load system
- Audio design: whispering ambience, brittle bone clicks
- Modular phylactery skins

---

## 4. UI Design
- Center: Clickable phylactery
- Left: Spirit Panel (scrollable list of spirit units)
- Future: Right for event/status panels, bottom for resource/action bars

---

## 5. Next Steps
- Finalize SpiritPanel logic (unit positioning, upgrades, scroll behavior)
- Fix font loading issue
- Begin work on Ritual reset/prestige system
- Save/load system integration

---

## 6. Dev Notes
- Font currently fails to load from assets (`pixel_font.ttf`)
- Passive soul income accumulates correctly after fix
- Game builds successfully on make
