# YD68 from YMDK68

Setup for the older MiniUSB-B version that is discontinued as of today. However, it should work on the new Type-C version as long as the following files are modified according to the new pin layout:
- `rules.mk`
- `config.h`
- `info.json`

This is a direct port of the original firmware [through this tool](https://noroadsleft.github.io/kbf_qmk_converter/) from noroadsleft. Although, the output has been modified.