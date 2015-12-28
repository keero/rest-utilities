CC = g++
CFLAGS = -Wall
LFLAGS = -I. -Iinclude
BINDIR = bin
LIBDIR = lib

.PHONY : all clean

$(BINDIR) :
	mkdir $(BINDIR)

$(LIBDIR) :
	mkdir $(LIBDIR)

$(BINDIR)/UrlTemplateTester : UrlTemplate/UrlTemplateTester.cpp $(LIBDIR)/UrlTemplate.so | $(BINDIR)
	$(CC) $(CFLAGS) $(LFLAGS) UrlTemplate/UrlTemplateTester.cpp $(LIBDIR)/UrlTemplate.so -o $@

$(LIBDIR)/UrlTemplate.so : UrlTemplate/UrlTemplate.cpp UrlTemplate/UrlTemplate.h | $(LIBDIR)
	$(CC) $(CFLAGS) -shared UrlTemplate/UrlTemplate.cpp -o $@

UrlTemplate : $(LIBDIR)/UrlTemplate.so

$(BINDIR)/HypermediaTester : Hypermedia/HypermediaTester.cpp $(LIBDIR)/Hypermedia.so $(LIBDIR)/UrlTemplate.so | $(BINDIR)
	$(CC) $(CFLAGS) $(LFLAGS) Hypermedia/HypermediaTester.cpp $(LIBDIR)/Hypermedia.so $(LIBDIR)/UrlTemplate.so -o $@

$(LIBDIR)/Hypermedia.so : Hypermedia/Link.cpp Hypermedia/Link.h Hypermedia/Form.cpp Hypermedia/Form.h $(LIBDIR)/UrlTemplate.so | $(LIBDIR)
	$(CC) $(CFLAGS) $(LFLAGS) -shared Hypermedia/Link.cpp Hypermedia/Form.cpp $(LIBDIR)/UrlTemplate.so -o $@


UrlTemplate : $(LIBDIR)/UrlTemplate.so
Hypermedia : $(LIBDIR)/Hypermedia.so

all : $(BINDIR)/UrlTemplateTester $(BINDIR)/HypermediaTester

clean :
	\rm -rf $(BINDIR) $(LIBDIR)
