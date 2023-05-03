# This is a QMK firmware that implements Wakib keybinding.

The following are the bindings being implemented in this repo.

![wakib-q5-v1](https://user-images.githubusercontent.com/2610287/236075575-2ab9a91c-dde5-4a90-b16e-84de7bc15338.png)

It also provides the `ESC` key on Left `ALT` double-tapping, and Caps Lock uses Caps Word (auto-off after word).

The numpad has also been rearranged to make it easier to use without the need for dedicated arrow keys.

The code implements them on the `wakib` keymap for the `Keychron Q5` specifically the `ansi_encoder`

This allows the use of these bindings on most applications by mapping them to standard shortcuts.

If you find these keybindings interesting, please look at other options with similar keybindings at the [Wakib Project](https://github.com/darkstego/wakib-project)

## Shortcut list

This is a list of the basic Wakib shortcuts mapped to their counterpart in commonly used shortcuts.

| Modifier        | Key | Shortcut           | Effect                |
|:----------------|:----|:-------------------|:----------------------|
| L-Alt           | i   | Up-Arrow           | move line up          |
| L-Alt           | j   | Left-Arrow         | move char left        |
| L-Alt           | k   | Down-Arrow         | move line down        |
| L-Alt           | l   | Right-Arrow        | move char right       |
| L-Alt           | u   | Ctrl + Left-Arrow  | move one word left    |
| L-Alt           | o   | Ctrl + Right-Arrow | move one word right   |
| L-Alt           | d   | backspace          | delete char left      |
| L-Alt           | f   | delete             | delete char right     |
| L-Alt           | e   | Ctrl + backspace   | delete word left      |
| L-Alt           | r   | Ctrl + delete      | delete word right     |
| L-Alt + L-Shift | i   | PageUp             | Move up one page      |
| L-Alt + L-Shift | k   | PageDown           | Move down one page    |
| L-Alt + L-Shift | u   | Home               | Move to start of line |
| L-Alt + L-Shift | o   | End                | Move to end of line   |
| L-Alt + L-Shift | j   | Ctrl + PgUp        | Previous Tab          |
| L-Alt + L-Shift | l   | Ctrl + PgDown      | Next Tab              |
| L-Alt           | ;   | F3                 | Next (in Find)        |
| L-Alt + L-Shift | ;   | Shift + F3         | Previous (in Find)    |



## How to install

The implementation is added as a keymap to the Keychron Q5 Keyboard ANSI_encoder version. To use another keyboard you should copy the code in that keymap.c and rules.mk and adjust to your keyboard. 

The essential parts to be copied over are those that include the word "Wakib" as well as the `process_record_user` section. 

### Keychron Q5 Install example 

Test that code compiles with 

`qmk compile -kb keychron/q5/ansi_encoder -km wakib`

Then flash (also compiles)

`qmk flash -kb keychron/q5/ansi_encoder -km wakib`

Remember that you should reset the keyboard before and after you complete the flashing. To reset you simply hold the ESC button while plugging the cable on to the keyboard. 


## Official Website

[qmk.fm](https://qmk.fm) is the official website of QMK, where you can find links to this page, the documentation, and the keyboards supported by QMK.
