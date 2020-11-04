[< Parent](./Readme.md)

# MacOS

## Prevent MacBook Pro from sleeping

Disable sleep using the power management settings (`pmset`) command line utility. The following commands will make the time to sleep infinite as well as prevent sleeping when there is no display connected:

```sh
sudo pmset -a sleep 0;
sudo pmset -a disablesleep 1
```

## Update MacOS via command line

```sh
softwareupdate --list
softwareupdate --install -a
```

### Install Xcode from command line

```sh
softwareupdate --install xcode
xcode-select --install
```

### Update Xcode from command line

```sh
softwareupdate --install -a
sudo rm -rf /Library/Developer/CommandLineTools
xcode-select --install
```

## Update Apps from App Store via command line

```sh
brew install mas
mas outdated
mas upgrade
```
