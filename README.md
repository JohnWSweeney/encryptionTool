# encryptionTool

A Windows console app for encrypting/decrypting messages using C++ pseudorandom number generators (PRNGs). The v1.0.0 release uses the rand() and srand() functions with a seed provided by the user.

## Function
The app opens a console window on startup. Enter the command keywords separated by a space. Commands are currently case-sensitive and must be lower-case.

### Encrypt
The *encrypt* function encrypts a message using a seed provided by the user. Enter:

> *encrypt seed message*

where  *seed* is a positive integer.
### Encryption/Decryption Loop
The *loop* function encrypts a message using a seed provided by the user, then decrypts the encrypted message with the same seed. Enter:

> *loop seed message*

where  *seed* is a positive integer.
## App Control
To exit the app, enter:
> *exit*

## Future Updates
- Standalone decrypt function.
- Additional PRNG engines.

## Download
[encryptionTool v1.0.0](https://github.com/JohnWSweeney/encryptionTool/releases/download/v1.0.0/encryptionTool_v1_0_0.exe) [> kB]

## ChangeLog <br/>
v1.0.0
- Added encrypt/decrypt loop function.
- Added README.