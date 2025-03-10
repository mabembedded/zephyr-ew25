# zephyr-ew25

## Building
```
$> west init -m https://github.com/mabembedded/zephyr-ew25.git
$> west update
$> west build -p -b nrf52840dk/nrf52840 app/
$> west flash
```

## Running tests
```
$> ../zephyr/scripts/twister --platform native_sim -WT tests/
```
