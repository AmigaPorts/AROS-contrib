# This manages to rebuild graminit.{h, c} under MSVC 6 (Windows), via
#
#     nmake /f grammar.mak
#
# The intermediate files can be nuked afterwards:
#
#     nmake /f grammar.mak clean
#
# I don't understand the maze of preprocessor #define's on Windows, and
# as a result this requires linking with python22.lib, so it's of no use
# for bootstrapping (the cause appears to be a useless-- in this
# particular case --pragma in PC\pyconfig.h, which demands that
# python22.lib get linked in).

LIBS= ..\PCbuild\python22.lib

CFLAGS= /I ..\Include /I ..\PC /D MS_NO_COREDLL

GRAMMAR_H= ..\Include\graminit.h
GRAMMAR_C= ..\Python\graminit.c
GRAMMAR_INPUT= ..\Grammar\Grammar

PGEN= pgen.exe

POBJS= acceler.obj grammar1.obj listnode.obj node.obj parser.obj \
       parsetok.obj tokenizer.obj bitset.obj metagrammar.obj

PARSER_OBJS= $(POBJS) myreadline.obj

PGOBJS= firstsets.obj grammar.obj pgen.obj printgrammar.obj pgenmain.obj

PGENOBJS= $(POBJS) $(PGOBJS)

$(GRAMMAR_H) $(GRAMMAR_C): $(PGEN) $(GRAMMAR_INPUT)
		$(PGEN) $(GRAMMAR_INPUT) $(GRAMMAR_H) $(GRAMMAR_C)

$(PGEN):	$(PGENOBJS)
		$(CC) $(PGENOBJS) $(LIBS) /Fe$(PGEN)

clean:
        del *.obj
        del $(PGEN)
