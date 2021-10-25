TARGET = ./main.out
HDRS_DIR = project/include

SRCS = project/src/main.c \
       project/src/write_data_tofile.c \
	   project/src/enter_transaction_data.c \
	   project/src/update_data_base.c \
	   project/src/test.c

.PHONY: all build rebuild check test memtest clean

all: clean check test memtest

$(TARGET): $(SRCS) 
	$(CC) -Wpedantic -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TARGET) $(CFLAGS) $(SRCS)

build: $(TARGET)

rebuild: clean build

check:
	./linters/run.sh

test: $(TARGET)
	./btests/run.sh $(TARGET)

memtest: $(TARGET)
	./btests/run.sh $(TARGET) --memcheck

clean:
	rm -rf $(TARGET)
