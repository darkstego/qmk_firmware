# This is a QMK firmware that implements Wakib keybinding.

The following are the bindings being implemented in this repo.

![wakib bindings](https://raw.githubusercontent.com/darkstego/qmk_firmware/wakib/wakib-basic.png)

It also provides the `ESC` key on Left `ALT` double-tapping.

The code implements them on the `wakib` keymap for the `Keychron Q5` specifically the `ansi_encoder`

This allows the use of these bindings on most applications by mapping them to standard shortcuts.

## How to install

Test that code compiles with 

`qmk compile -kb keychron/q5/ansi_encoder -km wakib`

Then flash (also compiles)

`qmk flash -kb keychron/q5/ansi_encoder -km wakib`

Remember that you should reset the keyboard before and after you complete the flashing. To reset you simply hold the ESC button while plugging the cable on to the keyboard. 

## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
