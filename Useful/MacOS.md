# MacOS

## Prevent MacBook Pro from sleeping

Disable sleep using the power management settings (`pmset`) command line utility. The following commands will make the time to sleep infinite as well as prevent sleeping when there is no display connected:

```sh
sudo pmset -a sleep 0;
sudo pmset -a disablesleep 1
```
