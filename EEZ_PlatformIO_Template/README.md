# Bare minimum EEZ Studio & PlatformIO project for the Sunton aka Cheap Yellow Display (CYD) boards and others.

This is basic project is based on the great work of [esp32-smartdisplay](https://github.com/rzeldent/esp32-smartdisplay) library that is intended to be used in [PlatformIO](https://platformio.org/).
See [https://github.com/rzeldent/esp32-smartdisplay](https://github.com/rzeldent/esp32-smartdisplay/) for more information about the driver library.

This example uses EEZ Studio to build the LVGL GUI elements. See the /src/ui/ directory for the EEZ Studio project files.
The project is configured to automatically build the files to the UI directory, so no manual copying of files is required.

This project additionally uses the [Sunton boards definitions](https://github.com/rzeldent/platformio-espressif32-sunton) to make it a breeze to use these various CYD-variant boards.


Ensure the correct board is selected in the `platformio.ini` file:
```ini
#This board has single Micro USB connector
#default_envs = esp32-2432S028R

#This board has single USB-C connector
#default_envs = esp32-2432S028Rv2

#This variant has USB-C and Micro USB connectors
#default_envs = esp32-2432S028Rv3
```

> [!WARNING]
> Do not forget to clone this repository with submodules: `git clone --recurse-submodules`!
> This is required to also have the latest version of the [Sunton boards definitions](https://github.com/rzeldent/platformio-espressif32-sunton) copied into the `boards` directory!.

