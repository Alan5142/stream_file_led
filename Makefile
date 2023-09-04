CC ?= gcc

APP_NAME = stream_file_led
OBJ_FILES = stream_file_led.o
LIBS = .

FLAGS ?= -Wall -Werror -Wpedantic

all: $(APP_NAME)

$(APP_NAME): $(OBJ_FILES)
	$(CC) -o $@ $^ $(FLAGS)

%.o: %.c
	$(CC) -o $@ -c $^ -g $(FLAGS)

clean:
	rm *.o $(APP_NAME)