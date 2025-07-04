# Game Design Document (GDD)

**Title:** *The Curse of Kursore*  
**Studio:** Spell Lynx Games  
**Design Lead:** Derek Miner  
**Document Version:** v1.2 (July 2025)

---

## 1. Game Overview

**Genre:** Clicker / Idle Game with Light RPG Mechanics  
**Platform:** PC (Standalone EXE; browser-based potential in future ports)  
**Engine/Framework:** SFML with C++  
**Visual Style:** 2D pixel art, dark necromantic fantasy aesthetic

**Premise:**  
The player inhabits a cursed phylactery, once a vessel of forbidden power, now reborn to harvest souls and corrupt the remnants of the world. Through relentless clicking and spectral automation, the phylactery grows its influence, summoning spirits, spreading UI-based corruption, and unlocking the secrets of a forgotten prophecy.

---

## 2. Core Gameplay Features (Implemented)

- **Primary Interaction:**
  - Clickable phylactery generates **Souls** (primary resource).
  - Clicking gives immediate feedback and resource increment.

- **Soul Display:**
  - Real-time soul counter shown on HUD.

- **Spirit Summoning Panel:**
  - Unlocks after collecting initial soul threshold.
  - Scrollable if more than four units unlocked.
  - Each unit includes:
    - Name
    - Description
    - Soul Cost
    - Custom sprite
    - “Summon” button

- **Automation:**
  - Summoned spirits passively generate souls per second.
  - Unit costs scale up with each purchase.

- **Progressive Unlocks:**
  - Only the next unlockable spirit is visible until affordable.
  - Spirit boxes turn red when unaffordable and normalize when buyable.

- **Game Loop:**
  - Core SFML loop includes rendering, input handling, and update tick.

---

## 3. Planned & In-Progress Features

- **Prestige System:**
  - *Ritual Reset* mechanic for permanent upgrade progression.
  - Unlocks additional modifiers or meta-currencies on reset.

- **Secondary Resources:**
  - Will be introduced as progression milestones:
    - *Bone Fragments*
    - *Woe*
    - *Dark Sigils*
    - *Blight*

- **Structures & Upgrades:**
  - Constructible/clickable UI buildings:
    - Soul Well
    - Bone Mill
    - Wailing Tree
  - Each adds passive effects or resource bonuses.

- **Progression Zones:**
  - Themed stages or “zones” representing different realms of corruption.
  - Each introduces new spirits, mechanics, and event types.

- **UI Evolution:**
  - The interface grows in **complexity** over time, unlocking new management panels and tools.
  - Early game presents minimal UI (training wheels); mid-to-late game introduces:
    - Resource and upgrade bars
    - Ritual/event side panels
    - Expanded spirit and structure management
  - Reflects player mastery without overwhelming at the start.

- **Lore & Narrative:**
  - Unlockable *Prophecies* and *Lore Fragments* through progression.
  - Optional event chains with narrative decisions.

- **Audio Design:**
  - Minimalist and atmospheric:
    - Whispering ambience
    - Bone click SFX
    - Event stingers

- **Cosmetic Phylactery Skins:**
  - Unlock new clickable phylactery visuals through progression or achievements.

- **Save/Load System:**
  - Local save files with auto-save interval.
  - Will serialize souls, spirits, structures, and player state.

---

## 4. UI Design

- **Center (Main Click Zone):**
  - Large animated phylactery (clickable object)

- **Left Panel:**
  - Spirit Summoning Panel (scrollable)

- **Right Panel (Planned):**
  - Events, narrative fragments, ritual indicators

- **Bottom Bar (Planned):**
  - Multi-resource tracker
  - Structure/Ritual activation buttons

- **Visual Language:**
  - Retro pixel font (`pixel_font.ttf`)
  - Clean layout, dark color palette with necromantic highlights

---

## 5. Development Roadmap (Next Steps)

- [ ] Finalize *Spirit Panel* logic (layout, scroll behavior, upgrades)
- [ ] Resolve **font loading** issue for `pixel_font.ttf`
- [ ] Begin implementation of **Ritual Reset / Prestige** system
- [ ] Design & hook up **Save/Load** functionality (binary or JSON)
- [ ] Add placeholder **SFX hooks** (soul collection, summon feedback)

---

## 6. Developer Notes

- Font file not currently loading; verify path and file presence.
- Passive soul income functions correctly after last patch.
- Game builds and runs via `make` using SFML 2.x.
- Codebase modularized: render, logic, and input handled in separate files.
