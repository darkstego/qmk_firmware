# darkstego user configs

To add this user config folder you must first either name your keymap `darkstego` or add `USER_NAME := darkstego` to your `rules.mk` file.

## Adding Wakib

To enable add `WAKIB_ENABLE = yes` to your `rules.mk`

Then, in your `keymap.c` file add `#include wakib.h` and in the function `process_record_user` add
```
    if (!process_record_wakib(keycode, record)) {
        return false;
    }
```

## Wakib Shortcut list

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

## License


Copyright 2023 Abdulla Bubshait

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.


