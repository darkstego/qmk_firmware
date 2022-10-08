# This is a QMK for that implements Wakib keybinding.

The following are the bindings being implemented in this repo.

![wakib bindings](https://raw.githubusercontent.com/darkstego/qmk_firmware/wakib/wakib-basic.png)

It also provides the `ESC` key on Left `ALT` tapping.

The code implements them on the `wakib` keymap for the `Keychron Q5` specifically the `q5_ansi_stm32l432_ec11`

This allows the use of these bindings on most applications by mapping them to standard shortcuts.

## How to install

Test that code compiles with 

`qmk compile -kb keychron/q5/q5_ansi_stm32l432_ec11 -km wakib`

Then flash (also compiles)

`qmk flash -kb keychron/q5/q5_ansi_stm32l432_ec11 -km wakib`


## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
