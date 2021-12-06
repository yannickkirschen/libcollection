# libcollection - A collection framework written in C.

VERSION = 0.1.0
ARCH = x86

CC                 = gcc
CC_FLAGS           = -std=c99 -Wall -I.

SRC_DIR            = src
OBJ_DIR            = build/bin
BIN_DIR            = build/bin
LIBRARY_NAME       = collection
SHARED_OBJECT_NAME = libcollection

SOURCES            := $(wildcard $(SRC_DIR)/*.c)
INCLUDES           := $(wildcard $(SRC_DIR)/*.h)
OBJECTS            := $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
rm                 = rm -f
mkdir              = mkdir -p
cp                 = cp
chmod              = chmod

all: build

init:
	@$(mkdir) $(OBJ_DIR)
	@$(mkdir) $(BIN_DIR)

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)

$(OBJECTS): $(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) $(CC_FLAGS) -c $< -o $@

build: clean init $(OBJECTS)
	@$(CC) -shared -o $(BIN_DIR)/$(SHARED_OBJECT_NAME).so $(OBJ_DIR)/*.o

demo: build
	@$(CC) -L $(BIN_DIR) -l $(LIBRARY_NAME) -o $(BIN_DIR)/demo $(OBJ_DIR)/demo.o

deb: build
	@$(mkdir) build/deb/usr/include/$(LIBRARY_NAME)
	@$(mkdir) build/deb/usr/lib/$(LIBRARY_NAME)

	@$(chmod) 0555 build/deb/DEBIAN/preinst

	$(foreach header, $(HEADERS), $(@$(cp) $(header) build/deb/usr/include/$(LIBRARY_NAME)))
	@$(cp) $(BIN_DIR)/$(SHARED_OBJECT_NAME).so build/deb/usr/lib/$(LIBRARY_NAME)
	dpkg -b build/deb $(BIN_DIR)/$(SHARED_OBJECT_NAME)_$(VERSION)_$(ARCH).deb
	@$(cp) $(BIN_DIR)/$(SHARED_OBJECT_NAME)_$(VERSION)_$(ARCH).deb $(BIN_DIR)/$(SHARED_OBJECT_NAME).deb
