## dotfiles

Contained are my dotfiles, which should go in $HOME/.config in order to work properly.

Credit to Adrien Carbonaro for his [dotfiles](https://github.com/adriencarbonaro/dotfiles). Configurations for polybar and rofi were taken directly from there.

Credit to Noah Frederick for his original [Planck keymap](https://noahfrederick.com/log/the-planck-keyboard). It has since been modified, as one should do with keymaps found on the internet.

## keyboard

### Resetting Keyboard

Under this keymap, the keyboard can be reset (e.g. to be flashed) via `LOWER+RAISE+q`. This is convenient for resetting a keyboard without using its physical reset switch.

### Building Firmware and Flashing

To build the firmware for each type of keyboard, follow these steps:

#### Planck
1. Ensure that `qmk_firmware/keyboards/planck/keymaps/louki/keymap.c` is up to date
2. From `qmk_firmware`, run `make planck/rev6:louki:dfu-util`
3. If the `.bin` file created in step 2 doesn't get automatically moved, run `mv .build/planck_rev6_louki.bin planck_rev6_louki.bin`
4. Plug in or reset the keyboard
5. Open `planck_rev6_louki.bin` in QMK Toolbox
6. Click `flash`


#### Lets Split
1. Ensure that `qmk_firmware/keyboards/lets_split/keymaps/louki/keymap.c` is up to date
2. From `qmk_firmware`, run `make lets_split/rev2:louki`
3. Plug in or reset the keyboard
4. Open `lets_split_rev2_louki.hex` in QMK Toolbox
5. Click `flash`

