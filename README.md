# achimt's QMK Keymap

Colemak-DH keymap for the **Corne (crkbd) rev4.1**.

## Kompilieren

```sh
cd /mnt/m/Documents/Projects/qmk_userspace
qmk userspace-compile
```

Das Binary landet unter:

```
crkbd_rev4_1_standard_achimt.uf2
```

## Flashen

1. Keyboard neu starten und dabei **Q** oder **P** (QWERTY-Position) gedrückt halten → Bootloader
2. Das `.uf2`-File auf das erscheinende Laufwerk kopieren

## Layer-Übersicht

| Layer | Aktivierung |
|-------|-------------|
| COLEMAK | Default |
| QWERTY | `DF(_QWERTY)` im FUNC-Layer |
| GAMING | `TG(_GAMING)` im FUNC-Layer |
| NAV | `MO(_NAV)` linker Daumen (mitte) |
| SYM | `LT(_SYM, BSPC)` rechter Daumen (mitte) |
| FUNC | `LT(_FUNC, ENT)` rechter Daumen (rechts) |
| NUM | `MO(_NUM)` linker Daumen (links) |
| SUDOKU | `TG(_SUDOKU)` im FUNC-Layer |