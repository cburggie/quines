all: quine

run: quine.c
	gcc -o quine $<
	@echo
	./quine $<
	@echo
	@cat $<

clean:
	rm -f simple quine.c quine


simple: csource/simple.c
	gcc -o $@ $<
	./$@ > %<

quine.c: quine
	./$< @@

quine: csource/source.c
	gcc -o $@ $<






