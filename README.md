# encryptionTool

A console app for exploring cryptography and encryption/decryption functions using C++ pseudorandom number generators (PRNGs). PRNGs include the 32 and 64-bit Mersenne Twisters, `mt19937` and `mt19937_64`, respectively. The original Standard Libary PRNG `rand` is also included for demonstration purposes but is not recommended for serious cryptography applications.

## Functions
The app opens a console window on startup. Enter the command keywords separated by a space. Commands are currently case-sensitive and must be lower-case. The user provides an integer `seed` to the PRNG, which acts as a primative "key" for the encyption/decryption algorithm.

### Encrypt
The *encrypt* function encrypts a message using a seed provided by the user. Enter:

> `encrypt seed message`

### Encryption/Decryption Loop
The `loop` function encrypts a message using a seed provided by the user, then decrypts the encrypted message with the same seed. Seed acts as a password. Enter:

> `loop seed message`

### Default PRNG 
The 32-bit Mersenne Twister `mt19937` is the default PRNG. The default PRNG can be set to another by entering:
>`default set prngName`

where `prngName` is `rand` for the original Standard Library PRNG, `mt32` for the 32-bit Mersenne Twister, or `mt64` for the 64-bit Mersenne Twister.

To query the current PRNG, enter:
>`default query`

### App Control
To exit the app, enter:
> `exit`

## Future Updates
- Standalone decrypt function.
- Advnaced key schemes.

## Known Issues
- Apostrophe and backslash characters not supported in messages.

## Download
[encryptionTool v1.1.0](https://github.com/JohnWSweeney/encryptionTool/releases/download/v1.1.0/encryptionTool_v1_1_0.exe) [37 kB]

## ChangeLog
v1.1.0
- Added random class with multiple PRNGs and related functions.

v1.0.0
- Added encrypt/decrypt loop function.
- Added README.