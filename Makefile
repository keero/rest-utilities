CC = g++
CFLAGS = -Wall
BINDIR = ./bin
LIBDIR = ./lib

.PHONY : all clean

$(BINDIR)/UrlTemplateTester : ./UrlTemplate/UrlTemplateTester.cpp $(LIBDIR)/UrlTemplate.so
	$(CC) $(CFLAGS) ./UrlTemplate/UrlTemplateTester.cpp $(LIBDIR)/UrlTemplate.so -o $@

$(LIBDIR)/UrlTemplate.so : ./UrlTemplate/UrlTemplate.cpp ./UrlTemplate/UrlTemplate.h
	$(CC) $(CFLAGS) -c ./UrlTemplate/UrlTemplate.cpp -o $@

all : $(BINDIR)/UrlTemplateTester

clean :
	\rm -rf $(BINDIR)/* $(LIBDIR)/*