
#include <stdio.h>

#define SIZE 10

int buffer[SIZE];
int head = 0, tail = 0, count = 0;

void send(int data)
{
    if (count == SIZE)
    {
        printf("Buffer Full!\n");
        return;
    }

    buffer[head] = data;
    head = (head + 1) % SIZE;
    count++;

    printf("Sent: %c\n", data);
}

void receive()
{
    if (count == 0)
    {
        printf("Buffer Empty!\n");
        return;
    }

    printf("Received: %c\n", buffer[tail]);

    tail = (tail + 1) % SIZE;
    count--;
}

int main()
{
    send('H');
    send('I');
    send('!');

    printf("\nReceiving Data:\n");

    receive();
    receive();
    receive();

    return 0;
}
