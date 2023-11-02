all: main.elf

main.elf: main.c ../Pong/statemachine.c buttons.c led.c mario.s
    msp430-gcc -mmcu=msp430g2553 -o $@ $^

clean:
    rm -f main.elf
