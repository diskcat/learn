## version 1
```
mytool: main.o tool1.o tool2.o
	gcc main.o tool1.o tool2.o -o mytool
main.o:main.c 
	gcc main.c -c -Wall -o main.o
tool1.o: tool1.c
	gcc tool1.c -c -Wall -o tool1.o
tool2.o: tool2.c 
	gcc tool2.c -c -Wall -o tool2.o
```

## version 2
```
OBJS = main.o tool1.o tool2.o
CC = gcc
mytool: $(OBJS)
	$(CC) $(OBJS) -o mytool
main.o:main.c 
	$(CC) main.c -c -Wall -o main.o
tool1.o: tool1.c
	$(CC) tool1.c -c -Wall -o tool1.o
tool2.o: tool2.c 
	$(CC) tool2.c -c -Wall -o tool2.o

clean: 
	$(RM) *.o mytool -r
```


## version 3
```
OBJS = main.o tool1.o tool2.o
CC = gcc
CFLAGS += -c -Wall -o
mytool: $(OBJS)
	$(CC) $(OBJS) -o mytool
main.o:main.c 
	$(CC) main.c $(CFLAGS) main.o
tool1.o: tool1.c
	$(CC) tool1.c $(CFLAGS) tool1.o
tool2.o: tool2.c 
	$(CC) tool2.c $(CFLAGS) tool2.o

clean: 
	$(RM) *.o mytool -r
```

## version 4

```
OBJS = main.o tool1.o tool2.o
CC = gcc
CFLAGS += -c -Wall -o
mytool: $(OBJS)
	$(CC) $^ -o $@
main.o:main.c 
	$(CC) $^ $(CFLAGS) $@
tool1.o: tool1.c
	$(CC) $^ $(CFLAGS) $@
tool2.o: tool2.c 
	$(CC) $^ $(CFLAGS) $@

clean: 
	$(RM) *.o mytool -r
```