CC = g++
CFLAGS = -Wall
BINDIR = ./bin
LIBDIR = ./lib

.PHONY : all clean UrlTemplate

$(BINDIR) :
	mkdir $(BINDIR)

$(LIBDIR) :
	mkdir $(LIBDIR)

$(BINDIR)/UrlTemplateTester : ./UrlTemplate/UrlTemplateTester.cpp $(LIBDIR)/UrlTemplate.so | $(BINDIR)
	$(CC) $(CFLAGS) ./UrlTemplate/UrlTemplateTester.cpp $(LIBDIR)/UrlTemplate.so -o $@

$(LIBDIR)/UrlTemplate.so : ./UrlTemplate/UrlTemplate.cpp ./UrlTemplate/UrlTemplate.h | $(LIBDIR)
	$(CC) $(CFLAGS) -c ./UrlTemplate/UrlTemplate.cpp -o $@

UrlTemplate : $(LIBDIR)/UrlTemplate.so

all : $(BINDIR)/UrlTemplateTester

clean :
	\rm -rf $(BINDIR) $(LIBDIR)
